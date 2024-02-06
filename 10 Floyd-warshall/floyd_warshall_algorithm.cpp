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

void floyd(GRAPH &graph){
    int n = graph.size();
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                int relax = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j] , relax);
            }
        }
        cout<<"After relaxing with k = " << k << endl << endl;
        print(graph);
    }
}


void readGraph(GRAPH &graph){
    int nodes, edges;
    cin >> nodes >> edges;
    graph = GRAPH(nodes, vector<int>(nodes,OO)); 
    // set the dignoal of the table with 0
    // to prevent self loops
    for(int i = 0 ; i < nodes ; i++)
        graph[i][i] = 0;
    for(int i = 0 ; i < edges ; i++){
        int to,from,weight;
        cin >> from >> to >> weight;
        if(from == to) continue;
        graph[from][to] = min(graph[from][to], weight);
    }
    cout<<"Input array: \n";
    print(graph);
}

int main(){

    GRAPH graph;
    readGraph(graph);
    floyd(graph);
    
}

/*

INPUT:

5 12
0 1 5
0 1 9
0 3 2
1 2 2
1 1 7
2 0 3
2 4 7
3 2 4
3 4 1
4 0 1
4 1 8
4 1 3



OUTPUT:

Input matrix
0 5 OO 2 OO
OO 0 2 OO OO
3 OO 0 OO 7
OO OO 4 0 1
1 3 OO OO 0
**************************
After relaxing with 0
0 5 OO 2 OO
OO 0 2 OO OO
3 8 0 5 7
OO OO 4 0 1
1 3 OO 3 0
**************************
After relaxing with 1
0 5 7 2 OO
OO 0 2 OO OO
3 8 0 5 7
OO OO 4 0 1
1 3 5 3 0
**************************
After relaxing with 2
0 5 7 2 14
5 0 2 7 9
3 8 0 5 7
7 12 4 0 1
1 3 5 3 0
**************************
After relaxing with 3
0 5 6 2 3
5 0 2 7 8
3 8 0 5 6
7 12 4 0 1
1 3 5 3 0
**************************
After relaxing with 4
0 5 6 2 3
5 0 2 7 8
3 8 0 5 6
2 4 4 0 1
1 3 5 3 0
**************************

 */