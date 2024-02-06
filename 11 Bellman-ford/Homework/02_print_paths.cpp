#include <bits/stdc++.h>
using namespace std;

const int OO = 1e5;

struct edge{
    int from,  to;
    int weight;
    edge(int from_, int to_, int w)
        : from(from_), to(to_), weight(w){}
};

vector<int> bellman(vector<edge> &graph, int V , int src, vector<int> &prv){
    vector<int> path(V, OO);
    prv = vector<int>(V,-1); //-1 means no prvious nodes
    path[src] = 0; 
    for(int i = 0; i < V ; i++){
        for(auto edge : graph){
            if(path[edge.from] + edge.weight < path[edge.to]){
                path[edge.to] = path[edge.from] + edge.weight;
                prv[edge.to] = edge.from;
            }
        }
    }
    return path;
}

vector<int> bulidPath(int st, vector<int>& prv){
    vector<int> ans;
    for(int i = st ; i != -1 ; i = prv[i]){
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    vector<int> prv;
    int startNode = 0;
    vector<int> shortestPath = bellman(graph, 6, startNode, prv);
    cout << "Starting From "<< startNode <<" :" << endl;
    for(int i = 0 ; i < shortestPath.size() ; i++){
        cout << "Shortest Path to "<< i <<" = " <<shortestPath[i] << endl;
        cout<<"\t=> ";
        vector<int> curPath = bulidPath(i,prv);
        for(auto val : curPath) cout<<val<<" ";
        cout << endl;
    }
    return 0;
}
/**
 * Output:
Starting From 0 :
Shortest Path to 0 = 0
        => 0
Shortest Path to 1 = 5
        => 0 5 4 1
Shortest Path to 2 = 5
        => 0 5 4 1 3 2
Shortest Path to 3 = 7
        => 0 5 4 1 3
Shortest Path to 4 = 9
        => 0 5 4
Shortest Path to 5 = 8
        => 0 5
*/