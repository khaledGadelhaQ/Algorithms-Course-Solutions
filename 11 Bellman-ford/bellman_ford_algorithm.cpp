#include <bits/stdc++.h>
using namespace std;

const int OO = 1e5;

struct edge{
    int from,  to;
    int weight;
    edge(int from_, int to_, int w)
        : from(from_), to(to_), weight(w){}
};

vector<int> bellman(vector<edge> &graph, int V , int src){
    vector<int> path(V, OO);
    path[src] = 0; 
    for(int i = 0; i < V ; i++){
        for(auto edge : graph){
            path[edge.to] = min(path[edge.to] , path[edge.from] + edge.weight);
        }
    }
    return path;
}


int main(){

    vector<edge> graph = {
        {0,1,10},
        {0,5,8},
        {1,3,2},
        {2,1,1},
        {3,2,-2},
        {4,1,-4},
        {4,3,-1},
        {5,4,1}
    };
    int startNode = 0;
    cout << "Starting From "<< startNode <<" :" << endl;
    vector<int> shortestPath = bellman(graph, 6, startNode);
    for(int i = 0 ; i < shortestPath.size() ; i++){
        cout << "Shortest Path to "<< i <<" = " <<shortestPath[i] << endl;
    }
    return 0;
}
/**
 * Output:
Starting From 0 :
Shortest Path to 0 = 0
Shortest Path to 1 = 5
Shortest Path to 2 = 5
Shortest Path to 3 = 7
Shortest Path to 4 = 9
Shortest Path to 5 = 8
*/