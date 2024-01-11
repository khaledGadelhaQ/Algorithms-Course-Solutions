#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<int, vector<int>> Graph;

void directed_graph(Graph &graph, int from, int to) {
    graph[from].push_back(to);
}

void print_graph(Graph &graph) {
    for (auto pair : graph) {
        cout << "Node " << pair.first << " has neighbors: ";
        for (auto val : pair.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> graph(row, vector<int>(col, 0));

    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            graph[i][j] = num;
            num++;
        }
    }

    Graph GRAPH;

    int tmp1[4] = {0, 0, 1, -1};
    int tmp2[4] = {1, -1, 0, 0};

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < 4; k++) {
                if (i + tmp1[k] >= 0 && i + tmp1[k] < row && j + tmp2[k] >= 0 && j + tmp2[k] < col) {
                    directed_graph(GRAPH, graph[i][j], graph[i + tmp1[k]][j + tmp2[k]]);
                }
            }
        }
    }

    print_graph(GRAPH);
}
