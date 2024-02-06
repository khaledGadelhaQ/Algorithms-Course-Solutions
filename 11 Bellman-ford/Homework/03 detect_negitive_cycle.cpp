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
        bool noChanges = false;
        for(auto edge : graph){
            if(path[edge.from] + edge.weight < path[edge.to]){
                path[edge.to] = path[edge.from] + edge.weight;
                noChanges = true;
            }
        }
        if(!noChanges){
            cout << "No Changes after "<< i+1 << " itreations.\n";
            break;
        }
        if(i == V-1){
            cout<<"\n Found Negitive Cycle!!\n";
            break;
        }
    }
    return path;
}


int main(){

    vector<edge> graph = { 
        { 0, 1, 1 }, 
        { 1, 2, 99 }, 
        { 2, 3, 5 }, 
        { 1, 4, 1 }, 
        { 4, 2, 3 }, 
        { 4, 5, 6 }, 
        { 5, 3, 7 } 
    };
    int startNode = 0;
    vector<int> shortestPath = bellman(graph, 6, startNode);
    cout << "Starting From "<< startNode <<" :" << endl;
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