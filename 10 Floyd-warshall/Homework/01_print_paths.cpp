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

void floyd(GRAPH &graph, GRAPH &path){
    int n = graph.size();
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                int relax = graph[i][k] + graph[k][j];
                if(relax < graph[i][j]){
                    graph[i][j] = relax;
                    path[i][j] = k;
                }
            }
        }
    }
    print(graph);
}


int readGraph(GRAPH &graph){
    int nodes =0, edges;
    cin >> nodes >> edges;
    graph = GRAPH(nodes, vector<int>(nodes,OO)); 
    // set the dignoal of the table with 0
    // to prevent self loops
    for(int i = 0 ; i < nodes ; i++){
        graph[i][i] = 0;
    }
    for(int i = 0 ; i < edges ; i++){
        int to,from,weight;
        cin >> from >> to >> weight;
        if(from == to) continue;
        graph[from][to] = min(graph[from][to], weight);
    }
    return nodes;
}

void printPath(int from , int to, GRAPH &path){
    if(path[from][to] == -1){
        cout << from << " " << to << endl;
        return;
    }
    printPath(from , path[from][to], path);
    printPath(path[from][to], to , path);
}

int main(){
    
    GRAPH graph;
    int n = readGraph(graph);
    GRAPH path = GRAPH(n , vector<int>(n , -1));
    floyd(graph,path);
    int from,to;
    cout << "Enter the two nodes to print the path: ";
    cin>> from >> to;
    printPath(from,to,path);
    
}

/*
INPUT:

 */