#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 1e5;


void print(GRAPH &graph){
    for(int i  = 0 ; i < graph.size() ; i++){
        for(int j = 0 ; j < graph[0].size(); j++){
            if(graph[i][j] >= OO)
                cout << "OO" << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    } 
    cout<<"*****************\n";
}

void countPaths(GRAPH &graph){
    int n = graph.size();
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                graph[i][j] += graph[i][k] * graph[k][j];
            }
        }
    }
    for(int k = 0 ; k < n ; k++){
        if(graph[k][k]){ //cycle
            for(int i = 0 ; i < n; i++){
                for(int j = 0 ; j < n ; j++){
                    if(graph[i][k] && graph[k][j]){
                        graph[i][j] = -1;
                    }
                }
            }
        }
    }

}


void readGraph(GRAPH &graph){
    int nodes, edges;
    cin >> nodes >> edges;
    graph = GRAPH(nodes, vector<int>(nodes,0)); 
    for(int i = 0 ; i < edges ; i++){
        int to,from;
        cin >> from >> to;
        graph[from][to] += 1;
    }
}

int main(){

    GRAPH graph;
    readGraph(graph);
    countPaths(graph);
    print(graph);
}


/*
5 6
0 1
0 2
1 2
0 3
3 4
4 3

0 1 2 -1 -1
0 0 1 0 0
0 0 0 0 0
0 0 0 -1 -1
0 0 0 -1 -1

5 7
0 1
0 2
0 4
2 4
2 3
3 1
4 3

0 4 1 3 2
0 0 0 0 0
0 2 0 2 1
0 1 0 0 0
0 1 0 1 0

6 5
0 2
0 1
1 5
2 5
2 1

0 2 1 0 0 3
0 0 0 0 0 1
0 1 0 0 0 2
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

5 9
0 1
0 2
0 3
0 4
1 4
2 1
2 0
3 0
3 1

-1 -1 -1 -1 -1
0 0 0 0 1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
0 0 0 0 0

 */