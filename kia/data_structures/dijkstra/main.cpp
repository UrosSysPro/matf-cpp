#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> neighbours_list;
    vector<bool> visited;
    vector<pair<int,int>> edges;
public:
    Graph(int n) {
        this->n=n;
        neighbours_list.resize(n);
        visited.resize(n,false);
    }

    void addEdge(int i, int j) {
        neighbours_list[i].push_back(j);
        neighbours_list[j].push_back(i);
    }

    void dfs(int index) {
        visited[index]=true;
        for (int j=0;j<neighbours_list[index].size();j++) {
            if (!visited[j]) {
                edges.push_back(pair(index,j));
                dfs(neighbours_list[index][j]);
            }
        }
    }

    vector<pair<int,int>> smer(int start) {
        dfs(start);
        return edges;
    }
};

int main(int argc,char** argv) {
    int n;
    cin >> n;
    Graph g = Graph(n);
    for (int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    int start;
    cin>>start;
    auto edges = g.smer(start);

    sort(edges.begin(),edges.end());

    for (const auto& [first,second]: edges) {
        cout<<first<<" "<<second<<endl;
    }

    return 0;
}