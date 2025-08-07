#include <iostream>
#include <map>
#include <list>
#include <stack>
using namespace std;

class Graph{
public : 
    unordered_map<int , list<int> > adjList;

    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }

    void printList(){
        for(auto a : adjList){
            cout << a.first << " : ";
            for(auto b : a.second){
                cout << b << " ";
            }
            cout << endl;
        }
    }

    void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &vis){
        vis[node] = true;
        for(auto nbr : adjList[node]){
            if(!vis[nbr]){
                dfs1(nbr, ordering, vis);
            }
        }
        ordering.push(node);
    }

    void dfs2(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int> > &adjNew){
        vis[node] = true;
        cout << node << " ";
        for(auto nbr : adjNew[node]){
            if(!vis[nbr]){
                dfs2(nbr, vis, adjNew); 
            } 
        }
    }

    int getStronglyConnectedComponents(int n){
        // 1. Get he ordering
        stack<int> ordering;
        unordered_map<int, bool> vis1;

        for(int i = 0; i < n; i++){
            if(!vis1[i]){
                dfs1(i, ordering, vis1);
            }
        }

        // 2. Reverse edges
        unordered_map<int, list<int> > adjNew;
        for(auto a : adjList){
            for(auto b : a.second){
                int u = a.first;
                int v = b;
                adjNew[v].push_back(u);
            }
        }

        // 3. Traverse usign ordereing and count compontnets
        int count = 0;
        unordered_map<int, bool> vis2;

        while(!ordering.empty()){
            int node = ordering.top();
            ordering.pop();
            if(!vis2[node]){
                cout << "SCC No. " << count + 1 << " : ";
                dfs2(node, vis2, adjNew);
                count++;
                cout << endl;
            }
        }

        return count;
    }
};

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(6,7);

    int scc = g.getStronglyConnectedComponents(8);
    cout << "Nuber of scc : " << scc << endl;
} 