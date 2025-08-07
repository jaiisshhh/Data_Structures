#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

class Graph {
public : 
    unordered_map<char, list<pair<char,int>> > adjList;
    
    void addEdge(char u, char v, int wt){
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
    
    void bellmanFord(int n, int src){
        vector<int> dist(n, INT_MAX);
        dist[src - 'A'] = 0;
        for(int i = 0; i < n - 1; i++){
            for(auto a : adjList){
                for(auto b : a.second){
                    char u = a.first;
                    char v = b.first;
                    int wt = b.second;
                    if(dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A']){
                        dist[v - 'A'] = dist[u - 'A'] + wt;
                    }
                }
            }
        }
        // Checking for negative cycle :
        bool anyUpdate  = false;
        for(auto a : adjList){
            for(auto b : a.second){
                char u = a.first;
                char v = b.first;
                int wt = b.second;
                if(dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A']){
                    anyUpdate = true;
                    break;
                }                
            }
        }
        if(anyUpdate) cout << "Negative Cycle Present" << endl;
        else{
            cout << "No Negative Cycle Present" << endl;
            cout << "Printing Dist Array : ";
            for(auto i : dist){
                cout << i << " ";
            }
            cout << endl;
        } 
    }
};

int main()
{
    Graph g;
    g.addEdge('A', 'B', -1); 
    g.addEdge('E', 'D', -3);
    g.addEdge('B', 'E', 2); 
    g.addEdge('D', 'C', 5);
    g.addEdge('A', 'C', 4);
    g.addEdge('B', 'C', 3);
    g.addEdge('B', 'D', 2);
    g.addEdge('D', 'B', 1);
    
    //g.printList();
    
    g.bellmanFord(5, 'A');

    return 0;
}