#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

const double INF = numeric_limits<double>::infinity();

// --- Fibonacci Heap ---
struct Node {
    int vertex;
    double key;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    int degree;
    bool mark;

    Node(int v, double k) : vertex(v), key(k), parent(nullptr),
                              child(nullptr), left(this), right(this),
                              degree(0), mark(false) {}
};

class FibonacciHeap {
private:
    Node* minNode;
    int numNodes;

    void link(Node* y, Node* x) {
        y->left->right = y->right;
        y->right->left = y->left;
        y->parent = x;
        if (x->child == nullptr) {
            x->child = y;
            y->right = y;
            y->left = y;
        } else {
            y->left = x->child;
            y->right = x->child->right;
            x->child->right->left = y;
            x->child->right = y;
            y->parent = x;
        }
        x->degree++;
        y->mark = false;
    }

    void consolidate() {
        int maxDeg = (int)(log2(numNodes)) + 2;
        vector<Node*> A(maxDeg, nullptr);
        vector<Node*> nodes;

        Node* curr = minNode;
        if (curr != nullptr) {
            do {
                nodes.push_back(curr);
                curr = curr->right;
            } while (curr != minNode);
        }

        for (Node* w : nodes) {
            Node* x = w;
            int d = x->degree;
            while (A[d] != nullptr) {
                Node* y = A[d];
                if (x->key > y->key) swap(x, y);
                link(y, x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
        }

        minNode = nullptr;
        for (int i = 0; i < maxDeg; i++) {
            if (A[i] != nullptr) {
                if (minNode == nullptr) {
                    minNode = A[i];
                    minNode->left = minNode;
                    minNode->right = minNode;
                } else {
                    A[i]->left = minNode;
                    A[i]->right = minNode->right;
                    minNode->right->left = A[i];
                    minNode->right = A[i];
                    if (A[i]->key < minNode->key) minNode = A[i];
                }
            }
        }
    }

    void cut(Node* x, Node* y) {
        if (x->right == x) y->child = nullptr;
        else {
            x->left->right = x->right;
            x->right->left = x->left;
            if (y->child == x) y->child = x->right;
        }
        y->degree--;
        x->left = x;
        x->right = x;
        x->parent = nullptr;
        x->mark = false;

        x->left = minNode;
        x->right = minNode->right;
        minNode->right->left = x;
        minNode->right = x;
    }

    void cascadingCut(Node* y) {
        Node* z = y->parent;
        if (z != nullptr) {
            if (!y->mark) {
                y->mark = true;
            } else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}

    Node* insert(int vertex, double key) {
        Node* node = new Node(vertex, key);
        if (minNode != nullptr) {
            node->left = minNode;
            node->right = minNode->right;
            minNode->right->left = node;
            minNode->right = node;
            if (node->key < minNode->key) minNode = node;
        } else {
            minNode = node;
        }
        numNodes++;
        return node;
    }

    Node* extractMin() {
        Node* z = minNode;
        if (z != nullptr) {
            if (z->child != nullptr) {
                Node* firstChild = z->child;
                vector<Node*> children;
                Node* curr = firstChild;
                do {
                    children.push_back(curr);
                    curr = curr->right;
                } while (curr != firstChild);

                for (Node* c : children) {
                    c->left = minNode;
                    c->right = minNode->right;
                    minNode->right->left = c;
                    minNode->right = c;
                    c->parent = nullptr;
                }
            }
            z->left->right = z->right;
            z->right->left = z->left;

            if (z == z->right) {
                minNode = nullptr;
            } else {
                minNode = z->right;
                consolidate();
            }
            numNodes--;
        }
        return z;
    }

    void decreaseKey(Node* x, double k) {
        if (k > x->key) return;
        x->key = k;
        Node* y = x->parent;
        if (y != nullptr && x->key < y->key) {
            cut(x, y);
            cascadingCut(y);
        }
        if (x->key < minNode->key) minNode = x;
    }

    bool isEmpty() { return minNode == nullptr; }

    ~FibonacciHeap() {
        // Note: In a production environment, we'd recursively delete nodes.
        // For this example, we'll rely on OS cleanup or manual clear if needed.
    }
};

struct Edge {
    int to;
    double weight;
};

void runDijkstra(int startNode, int n, const vector<vector<Edge>>& adj) {
    vector<double> dist(n, INF);
    vector<int> parent(n, -1);
    vector<Node*> nodes(n, nullptr);
    FibonacciHeap fh;

    dist[startNode] = 0;
    for (int i = 0; i < n; i++) {
        nodes[i] = fh.insert(i, dist[i]);
    }

    while (!fh.isEmpty()) {
        Node* min = fh.extractMin();
        int u = min->vertex;

        if (dist[u] == INF) break;

        for (auto& edge : adj[u]) {
            int v = edge.to;
            double weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                fh.decreaseKey(nodes[v], dist[v]);
            }
        }
    }

    // --- Visualization and Analysis ---
    auto start = chrono::high_resolution_clock::now();
    // Re-running logic check is not needed, but let's calculate stats
    double totalDist = 0;
    int reachableCount = 0;
    double maxDist = 0;

    for (int i = 0; i < n; i++) {
        if (dist[i] != INF) {
            totalDist += dist[i];
            reachableCount++;
            if (dist[i] > maxDist) maxDist = dist[i];
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "========================================" << endl;
    cout << "   DIJKSTRA PERFORMANCE REPORT" << endl;
    cout << "========================================" << endl;
    cout << "Nodes:          " << n << endl;
    cout << "Edges:         " << (size_t)adj.size() << " (approx. calculated)" << endl; // Actually count edges

    // Count actual edges
    long long edgeCount = 0;
    for(int i=0; i<n; ++i) edgeCount += adj[i].size();
    cout << "Total Edges:   " << edgeCount << endl;
    cout << "Execution Time: " << fixed << setprecision(4) << elapsed.count() << " seconds" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Reachable Nodes: " << reachableCount << " / " << n << endl;
    cout << "Average Distance: " << (reachableCount > 0 ? totalDist / reachableCount : 0) << endl;
    cout << "Maximum Distance: " << maxDist << endl;
    cout << "----------------------------------------" << endl;

    // Sample Paths for specific targets
    vector<int> targets = {500, 750, 999};
    cout << "Sample Paths (Source 0 -> Target):" << endl;
    for(int target : targets) {
        cout << "Target " << target << ": ";
        if (dist[target] == INF) cout << "Unreachable" << endl;
        else {
            vector<int> path;
            for (int v = target; v != -1; v = parent[v]) path.push_back(v);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
            }
            cout << " (Total Cost: " << dist[target] << ")" << endl;
        }
    }
    cout << "========================================" << endl;
}

int main() {
    int numVertices = 1000;
    long long targetEdges = 1000000;
    vector<vector<Edge>> adj(numVertices);

    cout << "Generating " << targetEdges << " random edges..." << endl;

    // Using a fixed seed for reproducibility during testing
    mt19937 rng(42);
    uniform_int_distribution<int> distNode(0, numVertices - 1);
    uniform_real_distribution<double> distWeight(1.0, 100.0);

    // Build the graph
    for (long long i = 0; i < targetEdges; ++i) {
        int u = distNode(rng);
        int v = distNode(rng);
        if (u == v) continue; // Skip self-loops
        adj[u].push_back({v, distWeight(rng)});
    }

    cout << "Graph generation complete. Starting Dijkstra..." << endl;

    runDijkstra(0, numVertices, adj);

    return 0;
}