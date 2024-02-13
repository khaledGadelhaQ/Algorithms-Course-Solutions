#include <bits/stdc++.h>
using namespace std;

const int OO = 1e6;

typedef pair<int,int> pii;

int MST(vector<vector<pii>> &adjList, int V, int src) {
    vector<bool> visited(V, false);
    vector<int> distance(V, OO);
    distance[src] = 0;
    int mnVal = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // using min heap
    pq.push({0, src});
    while (!pq.empty()) {
        auto cur = pq.top();
        int idx = cur.second;
        pq.pop();
        if (visited[idx]) continue;
        mnVal += cur.first; 
        for (auto e : adjList[idx]) {
            int to = e.second;
            int w = e.first;
            if(w < distance[to]){
                distance[to] = w;
                pq.push({w, to});
            }
        }
        visited[idx] = true;
    }
    return mnVal;
}

int main() {
    // Example graph: 
    //      1
    //   0 --- 1
    //   |  /  |
    // 2 | / 3 | 2
    //   |/    |
    //   2 --- 3
    vector<vector<pii>> adjList = {
        {{1, 1}, {2, 2}}, // Node 0
        {{0, 1}, {3, 3}}, // Node 1
        {{0, 2}, {3, 2}}, // Node 2
        {{1, 3}, {2, 2}}  // Node 3
    };
    
    int V = adjList.size(); // Number of vertices
    int src = 0; // Source node

    int minWeight = MST(adjList, V, src);
    cout << "Minimum Weight of MST: " << minWeight << endl;
    
    return 0;
}