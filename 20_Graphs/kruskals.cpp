#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt) {
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    void printList() {
        for (auto i : adjList) {
            cout << i.first << " : ";
            for (auto nbr : i.second) {
                cout << "{ " << nbr.first << " " << nbr.second << " } ";
            }
            cout << endl;
        }
    }

    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u == v) return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    static bool myComp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int kruskalMST(int V) {
        vector<vector<int>> edges;
        unordered_map<string, bool> visited;

        for (auto it : adjList) {
            int u = it.first;
            for (auto nbr : it.second) {
                int v = nbr.first;
                int wt = nbr.second;

                string key = to_string(min(u, v)) + "-" + to_string(max(u, v));
                if (!visited[key]) {
                    edges.push_back({u, v, wt});
                    visited[key] = true;
                }
            }
        }

        sort(edges.begin(), edges.end(), myComp);

        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        int ans = 0;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int pu = findParent(parent, u);
            int pv = findParent(parent, v);
            if (pu != pv) {
                unionSet(pu, pv, parent, rank);
                ans += wt;
            }
        }

        return ans;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(3, 1, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 4, 7);

    cout << "Minimum Spanning Tree Weight using Kruskal: " << g.kruskalMST(5) << endl;
}
