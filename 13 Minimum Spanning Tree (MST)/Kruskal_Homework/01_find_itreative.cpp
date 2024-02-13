#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            swap(x, y);
        }
        parent[x] = y;
        if (rank[x] == rank[y]) {
            rank[y] += 1;
        }
    }
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = -1, rank[i] = 1;
    }
    int Find(int x) {
        vector<int> nodes;
        while(parent[x] != -1){
            nodes.push_back(x);
            x = parent[x];
        }
        for(auto val :nodes){
            parent[val] = x;
        }
        return x;
    }
    bool unionSets(int x, int y) {
        x = Find(x), y = Find(y);
        if (x != y) {
            link(x, y);
        }
        return x != y;
    }
};

class edge {
public:
    int from, to, weight;
};

int kruskal(vector<edge>& adjList, int n) {
    UnionFind uf(n);
    sort(adjList.begin(), adjList.end(), [](edge& a, edge& b) {
        return a.weight < b.weight;
    });
    int mnVal = 0; // Initialize mnVal to zero
    for (auto e : adjList) {
        if (uf.unionSets(e.from, e.to)) {
            mnVal += e.weight;
        }
    }
    return mnVal;
}

int main() {
    int n = 4; // Number of vertices
    vector<edge> adjList = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}}; // Define the graph
    cout << "Minimum Spanning Tree weight: " << kruskal(adjList, n) << endl; // Call kruskal function
    return 0;
}
