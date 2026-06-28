#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

class Node;
class Edge;

using namespace std;

int n = 10;

class Edge {
public:
    int start, end, weight;

    Edge(int start, int end, int weight) {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
};

class Node {
public:
    bool visited;
    string name;

    Node(string name) {
        this->visited = false;
        this->name = name;
    }
};

class Graph {
public:
    vector<Node> nodes;
    vector<Edge> edges;

    Graph(vector<Node> nodes, vector<Edge> edges) {
        this->nodes = nodes;
        this->edges = edges;
    }

    ~Graph() {

    }

    void printEdges() {
        for (const auto &edge: edges) {
            printf("%s --%d--> %s \n", nodes[edge.start].name.c_str(), edge.weight, nodes[edge.end].name.c_str());
        }
    }

    void printShortestDistances() {

    }
};

int main(int argc, char** argv) {
    Graph g = Graph(
        vector<Node>({
            Node("A"),
            Node("B"),
            Node("C"),
            Node("D"),
            Node("E"),
            Node("F"),
        }),
        vector<Edge>({
            Edge(0,1,5),
            Edge(0,2,2),
            Edge(0,4,6),
            Edge(1,5,4),
            Edge(2,5,1),
            Edge(2,3,7),
            Edge(3,5,9),
            Edge(3,4,8),
        })
    );

    g.printEdges();

    return 0;
}