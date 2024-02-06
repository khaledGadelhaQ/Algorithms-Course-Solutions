#include <bits/stdc++.h>
using namespace std;

const int OO = 1e5;

struct edge{
    int to;
    int weight;
    edge(int to_, int w)
        : to(to_), weight(w){}
    
    bool operator <(const edge &e) const{
        return weight > e.weight;
    }
};

vector<int> Dijkstra(vector<vector<edge>> &adjList, int V, int src) {
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
            }
        }
        visited[idx] = true;
    }
    return distance;
}

int main(){
    
}