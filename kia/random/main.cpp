#include <deque>
#include<iostream>
#include <limits>
#include <queue>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


class Graph{
private:
    int n;
    vector<vector<int>> neighbours = vector<vector<int>>();
    vector<bool> visited = vector<bool>();

public:
    Graph(int n){
        this->n = n;
        neighbours.resize(n, vector<int>());
        visited.resize(n, false);
    }

    void addEdge(int start, int end){
        neighbours[start].push_back(end);
        neighbours[end].push_back(start);
    }

    void bfs(){
        for(int i = 0 ; i < visited.size() ; i++){
            visited[i] = false;
        }
        deque<int> toVisit = deque<int>();

        visited[0] = true;
        toVisit.push_back(0);

        while(!toVisit.empty()){
            int current = toVisit[0];
            toVisit.pop_front();
            for(auto neighbour : neighbours[current]){
                if(!visited[neighbour]){
                    cout << "visited " << neighbour << endl;
                    visited[neighbour] = true;
                    toVisit.push_back(neighbour);
                }
            }
        }
    }

    void dfs(){
        for(int i = 0 ; i < visited.size() ; i++){
            visited[i] = false;
        }
        deque<int> toVisit = deque<int>();

        visited[0] = true;
        toVisit.push_front(0);

        while(!toVisit.empty()){
            int current = toVisit[0];
            toVisit.pop_front();
            for(auto neighbour : neighbours[current]){
                if(!visited[neighbour]){
                    cout << "visited " << neighbour << endl;
                    visited[neighbour] = true;
                    toVisit.push_front(neighbour);
                }
            }
        }
    }
    void dijkstra(){
        struct Comparator{
            bool operator()(pair<int,int> first, pair<int,int> second){
                return first.second>second.second;
            }
        };
        for(int i = 0 ; i < visited.size() ; i++){
            visited[i] = false;
        }
        vector<int> distances = vector<int>();
        distances.resize(n,numeric_limits<int>().max());
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator> toVisit;

        visited[0] = true;
        toVisit.push(pair(0,1));

        while(!toVisit.empty()){
            auto [current, distance] = toVisit.top();
            toVisit.pop_front();
            for(auto neighbour : neighbours[current]){
                if(!visited[neighbour]){
                    cout << "visited " << neighbour << endl;
                    visited[neighbour] = true;
                    toVisit.push_front(neighbour);
                }
            }
        }
    }
};

int main(int argc, char** argv){
    Graph g = Graph(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 0);

    g.dfs();

    return 0;
}
