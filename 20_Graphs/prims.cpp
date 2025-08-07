#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<climits>
using namespace std;

class Graph{
public : 
    unordered_map<int, list<pair<int, int > > > adjList;

    void addEdge(int u, int v, int wt){
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
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

    int primMST() {
        int n = adjList.size();
        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);
        vector<int> parent(n, -1);

        key[0] = 0;

        for(int i = 0; i < n - 1; i++) {
            int u = -1;
            int mini = INT_MAX;

            for(int v = 0; v < n; v++) {
                if(!mst[v] && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }

            if(u == -1) break;

            mst[u] = true;

            for(auto [v, wt] : adjList[u]) {
                if(!mst[v] && wt < key[v]) {
                    key[v] = wt;
                    parent[v] = u;
                }
            }
        }

        int sum = 0;
        for(int i = 1; i < n; i++) {
            if(parent[i] != -1) {
                for(auto [v, wt] : adjList[i]) {
                    if(v == parent[i]) {
                        sum += wt;
                        break;
                    }
                }
            }
        }

        return sum;
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(3,1,8);
    g.addEdge(1,4,5);
    g.addEdge(1,2,3);
    g.addEdge(2,4,7);

    g.printList();
    cout << "MST Total Weight: " << g.primMST() << endl;

    return 0;
}
  