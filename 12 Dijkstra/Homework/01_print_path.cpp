#include <bits/stdc++.h>
using namespace std;

const int OO = 1e6;

struct edge {
    int to;
    int weight;
    edge(int to_, int w) : to(to_), weight(w) {}

    bool operator<(const edge &e) const {
        return weight > e.weight;
    }
};

vector<int> Dijkstra(vector<vector<edge>> &adjList, int V, int src, vector<int> &prv) {
    vector<bool> visited(V, false);
    vector<int> distance(V, OO);
    distance[src] = 0;

    priority_queue<edge> pq;
    pq.push(edge(src, 0));
    while (!pq.empty()) {
        int idx = pq.top().to;
        pq.pop();
        if (visited[idx]) continue;
        for (auto e : adjList[idx]) {
            int idxx = e.to;
            int w = e.weight;
            if (distance[idxx] > distance[idx] + w) {
                distance[idxx] = distance[idx] + w;
                pq.push({idxx, distance[idxx]});
                prv[idxx] = idx;
            }
        }
        visited[idx] = true;
    }
    return distance;
}

int read_graph(vector<vector<edge>> &adjList) {
    int nodes, edges;
    cin >> nodes >> edges;
    adjList.resize(nodes);
    for (int i = 0; i < edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adjList[from].push_back({to, weight});
    }
    return nodes;
}

vector<int> print_path(vector<int> &prv, int i) {
    vector<int> path;
    for (; prv[i] != -1; i = prv[i]) {
        path.push_back(i);
    }
    path.push_back(i); // Adding the source node
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<vector<edge>> adjList;
    int n = read_graph(adjList);
    vector<int> prv(n, -1);
    int src = 0;
    vector<int> shortest_paths = Dijkstra(adjList, n, src, prv);
    // Print shortest paths
    cout << "Shortest paths from node " << src << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Shortest path to node " << i << ": ";
        vector<int> path = print_path(prv, i);
        for (int j = 0; j < path.size(); ++j) {
            cout << path[j];
            if (j != path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << " (distance: " << shortest_paths[i] << ")" << endl;
    }
    return 0;
}
/*
INPUT:
4 5
0 1 4
0 2 1
1 2 2
1 3 5
2 3 2
OUTPUT:
Shortest paths from node 0:
Shortest path to node 0: 0 (distance: 0)
Shortest path to node 1: 0 -> 1 (distance: 4)
Shortest path to node 2: 0 -> 2 (distance: 1)
Shortest path to node 3: 0 -> 2 -> 3 (distance: 3)
*/