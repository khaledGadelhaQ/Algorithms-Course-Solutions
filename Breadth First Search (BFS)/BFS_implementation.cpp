#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 10000000;	// A big value expressing infinity


void add_undirtected_graph(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

vector<int> BFS(GRAPH &graph, int start) {
    vector<int> visited(graph.size(), OO);
    queue<int> q;
    q.push(start);
    visited[start] = 0; // Set the level of the starting node to 0
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto neighbor : graph[front]) {
            if (visited[neighbor] == OO) {
                visited[neighbor] = visited[front] + 1; // Increment the level of the neighbor
                q.push(neighbor);
            }
        }
    }
    return visited;
}

void print_bfs(vector<int> visited) {
    cout << endl;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] != OO) {
            cout << "Node: " << i << " Level: " << visited[i] << endl;
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    GRAPH graph(nodes);

    while (edges--) {
        int from, to;
        cin >> from >> to;
        add_undirtected_graph(graph, from, to);
    }
    print_bfs(BFS(graph, 1));
}

/*

9 8
1 6
1 5
1 3
3 4
3 7
6 0
4 2
2 8

Output:
Node: 0 Level: 2
Node: 1 Level: 0
Node: 2 Level: 3
Node: 3 Level: 1
Node: 4 Level: 2
Node: 5 Level: 1
Node: 6 Level: 1
Node: 7 Level: 2
Node: 8 Level: 4

*/

