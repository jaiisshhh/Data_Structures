#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
using namespace std;

class Graph{
public : 
    unordered_map<int, list<pair<int, int> > > adjList;

    void addEdge(int u, int v, int wt, bool direction){
        if(direction == 1){
            adjList[u].push_back(make_pair(v, wt));
        }
        else{
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }
    }

    void printAdjList(){
        for(auto i : adjList){
            cout << i.first << ": ";
            for(pair<int, int> p : i.second){
                cout << "{ " << p.first << ", " << p.second << " }";
            }
            cout << endl;
        }
    }    

    void topoDFS(int src, unordered_map<int, bool> &vis, stack<int> &st){
        vis[src] = true;
        for(auto nbr : adjList[src]){
            if(!vis[nbr.first]){
                topoDFS(nbr.first, vis, st);
            }
        }
        st.push(src);
    }

    void shortestPathDFS(int n, stack<int> &st){
        vector<int> dist(n, INT_MAX);
        // Initial values
        int src = st.top();
        st.pop();
        dist[src] = 0;
        // Update Nbr Dist of src node
        for(auto nbr : adjList[src]){
            if(dist[src] + nbr.second < dist[nbr.first]){
                dist[nbr.first] = dist[src] + nbr.second;
            }
        }
        while(!st.empty()){
            int src = st.top();
            st.pop();
            for(auto nbr : adjList[src]){
                if(dist[src] + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = dist[src] + nbr.second;
                }
            }
        }

        cout << "Printing the dist array : ";
        for(auto i : dist){
            cout << i << " ";
        }
        cout << endl;
    }

};

int main(){
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(4, 3, 1, 1);

    //g.printAdjList();

    int src = 0;
    stack<int> st;
    unordered_map<int, bool> vis;
    g.topoDFS(src, vis, st);

    int n = 5;
    g.shortestPathDFS(n, st);

}

