#include<iostream>
#include<list>
#include<map>
using namespace std;

class Graph{
public :
    unordered_map<int , list<int> > adjList;

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

    bool checkCycleUndirectedBFS(int src){
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto child : adjList[front]){
                if(child == parent[front]) continue; 
                if(!vis[child]){
                    q.push(child);
                    vis[child] = true;
                    parent[child] = front;
                }
                else if(vis[child] == true){
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCycleUndirectedDFS(int src, unordered_map<int, bool> &vis, int parent){
        vis[src] = true;
        for(auto nbr : adjList[src]){
            if(nbr == parent) continue;
            if(!vis[nbr]){
                bool ans = checkCycleUndirectedDFS(nbr, vis, src);
                if(ans == true) return true;
            }
            else if(vis[nbr] == true){
                return true;
            }
        }
        return false;
    }

    bool checkCycleDirectedDFS(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsTrack){
        vis[src] = true;
        dfsTrack[src] = true;
        for(auto nbr : adjList[src]){
            if(!vis[nbr]){
                bool ans = checkCycleDirectedDFS(nbr, vis, dfsTrack);
                if(ans) return true;
            }
            if(vis[nbr] == true && dfsTrack[nbr] == true) return true;
        }
        dfsTrack[src] = false;
        return false; 
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    //g.addEdge(3,4,0);
    g.addEdge(2,5,0);

    // int src = 0;
    // bool isCyclic = g.checkCycleUndirectedBFS(src);
    // if(isCyclic) cout << "Cycle Present" << endl;
    // else cout << "Cycle Absent" << endl;

    unordered_map<int, bool> vis;
    bool isCyclic = g.checkCycleUndirectedDFS(0, vis, -1);
    if(isCyclic) cout << "Cycle Present" << endl;
    else cout << "Cycle Absent" << endl;
}