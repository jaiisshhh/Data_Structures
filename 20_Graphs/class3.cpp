// TOPOLOGICAL SORT

#include <iostream>
#include <map>
#include <stack>
#include <list>
#include <queue>
using namespace std;

class Graph{
public : 
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool dir){
        if(dir == 1){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printList(){
        for(auto i : adjList){
            cout << i.first << " -> ";
            for(auto nbr : i.second){
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    void topoSortDfs(int src, map<int, bool> &vis, stack<int> &st){
        vis[src] = true;
        for(auto nbr : adjList[src]){
            if(!vis[nbr]){
                topoSortDfs(nbr, vis, st);
            }
        }
        st.push(src);
    }

    void topoSortBfs(int n){
        queue<int> q;
        unordered_map<int, int> indegree;
        // Initialize indegree map
        for(auto i : adjList){
            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }
        // Push all zero indree nodes into the queue
        for(int node = 0; node < n; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }
        // BFS
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";
            for(auto nbr : adjList[frontNode]){
                indegree[nbr]--;
                // Check for zeros
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }

    void shortestPathBFS(int src, int dest){
        queue<int> q;
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while (!q.empty()){
            int front = q.front(); 
            q.pop();
            for(auto nbr : adjList[front]){
                if(!vis[nbr]){
                    q.push(nbr);
                    parent[nbr] = front;
                    vis[nbr] = true;
                }
            }
        }
        vector<int> ans;
        while(dest != -1){
            ans.push_back(dest);
            dest = parent[dest];
        }
        reverse(ans.begin(), ans.end());
        for(auto i : ans){
            cout << i << " ";
        }
    }

};

int main(){ 

    Graph g;
    g.addEdge(0, 5, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(6, 3, 0);
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0); 
    g.addEdge(2, 3, 0);

    //g.printList();
    
    // int n = 8; // No of node0
    // stack<int> st;
    // map<int, bool> vis;
    // // Handleing disconnected Component
    // for(int node = 0; node < n; node++){
    //     if(!vis[node]){
    //         g.topoSortDfs(node, vis, st);
    //     }
    // }
    // cout << "Printing Topo Order : ";
    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    // int n = 8;
    // g.topoSortBfs(n);
    // cout << endl;
 
    int src = 0;
    int dest = 3;
    g.shortestPathBFS(src, dest);

} 