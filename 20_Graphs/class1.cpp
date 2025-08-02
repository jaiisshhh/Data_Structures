#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

// UNWEIGHTED 
// class Graph{
// public : 
//     unordered_map<int , list<int> > adjList;
    
//     void addEdge(int u, int v, bool direction){
//         // 0 - Undirected
//         // 1 - Directed
//         if(direction == 1){
//             // u - v
//             adjList[u].push_back(v);
//         }
//         else{
//             // u <-> v;
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }

//         cout << endl << "Pringing adjList" << endl;
//         printAdjList();
//         cout << endl;
//     }

//     void printAdjList(){
//         for(auto i : adjList){
//             cout << i.first << " -> { ";
//             for(auto neighbour : i.second){
//                 cout << neighbour << " , ";
//             }
//             cout << " }" << endl;
//         }
//     }
// };

// WEIGHTED 
class Graph{
public : 
    unordered_map<int, list<pair<int, int> > > adjList;

    void addEdge(int u, int v, int wt, bool direction){
        // 0 - Undirected
        // 1 - Directed
        if(direction == 1){
            // u -> v
            adjList[u].push_back(make_pair(v, wt));
        }
        else{
            // u <-> v;
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }

        cout << endl << "Pringing adjList" << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList(){
        for(auto i : adjList){
            cout << i.first << ": { ";
            for(pair<int, int> p : i.second){
                cout << "{ " << p.first << ", " << p.second << " }";
            }
            cout << " }" << endl;
        }
    }    

    void bfs(int src){
        unordered_map<int, bool> vis;
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            int front = q.front();
            cout << front << " ";
            q.pop();
            for(auto nbr : adjList[front]){
                if(!vis[nbr.first]){
                    q.push(nbr.first);
                    vis[nbr.first] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool>& vis){
        vis[src] = true;
        cout << src << " ";
        for(auto nbr: adjList[src]){
            if(!vis[nbr.first]){
                dfs(nbr.first, vis);
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(1, 2, 10, 1);
    g.addEdge(1, 3, 20, 1);
    g.addEdge(2, 3, 50, 1);

    cout << "Printing BFS : ";
    g.bfs(0);
    cout << endl;

    cout << "Printing DFS : ";
    unordered_map<int, bool> vis;
    g.dfs(0, vis);
    cout << endl;
} 