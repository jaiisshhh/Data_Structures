#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

class Graph {
public : 
    unordered_map<int, list<pair<int,int>> > adjList;
    
    void addEdge(int u, int v, int wt){
            adjList[u].push_back({v, wt});
    }
    
    void printList(){
        for(auto i : adjList){
            cout << i.first << " : ";
            for(auto nbr : i.second){
                cout << "{ " << nbr.first << " " << nbr.second << " } ";
            }
            cout << endl;
        }
    }
    
    void floydWarshall(int n){
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        // Initial State 
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }
        for(auto a : adjList){
            for(auto b : a.second){
                auto u = a.first;
                auto v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }
        
        // Main logic
        for(int helper = 0; helper < n; helper++){
            for(int src = 0; src < n; src++){
                for(int dest = 0; dest < n; dest++){
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 3); 
    g.addEdge(1, 0, 2);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 4);
    g.addEdge(3, 2, 2);
    g.addEdge(2, 1, 1);
    
    g.floydWarshall(4);

    return 0;
}