#include <iostream>
#include <unordered_map>
#include <list>
#include <vector> 
#include <limits>
#include <set>
using namespace std;

class Graph{
public: 
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction){
        adjList[u].push_back({v, wt});
        if (!direction) {
            adjList[v].push_back({u, wt});
        }
    }

    void Dijkstra(int src, int dest){
        unordered_map<int, int> dist;
        set<pair<int, int>> st;

        // Initialize distances
        for (auto& node : adjList) {
            dist[node.first] = INT_MAX;
        }

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto [topDist, topNode] = *st.begin();
            st.erase(st.begin());

            for (auto [nbrNode, nbrDist] : adjList[topNode]) {
                if (topDist + nbrDist < dist[nbrNode]) {
                    auto prevEntry = st.find({dist[nbrNode], nbrNode});
                    if (prevEntry != st.end()) {
                        st.erase(prevEntry);
                    }
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        if (dist.find(dest) != dist.end() && dist[dest] != INT_MAX) {
            cout << "Shortest Distance from " << src << " to " << dest << " is " << dist[dest] << endl;
        } else {
            cout << "Node " << dest << " is unreachable from " << src << endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    int src = 6;
    int dest = 4;
    g.Dijkstra(src, dest);
}
