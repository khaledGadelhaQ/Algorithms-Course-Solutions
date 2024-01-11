#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef map<string,vector<pair<string,int>>> Graph;

void directed_graph(Graph &graph,  string from , string to, int cost){
    graph[from].push_back({to,cost});
}

void undirected_graph(Graph &graph,  string from , string to, int cost){
    graph[from].push_back({to,cost});
    graph[to].push_back({from,cost});
}

bool cmp_to_cost(pair<string,int> &a ,pair<string,int> &b){
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
     
}

void print_graph(Graph &graph){
    for(auto val : graph){
        cout <<"Flights from "<< val.first<<" :"<<endl;
        sort(val.second.begin(), val.second.end(), cmp_to_cost);
        for(auto pair : val.second){
            cout<<"\tTo "<< pair.first <<" with cost "<<pair.second <<endl;
        }
    }
}
 
int main(){
     
    cout << "Enter the number of nodes and the number of edges: \n";
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph;
    for (int i = 0 ; i < edges ; i++ ){
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        directed_graph(graph, from , to, cost);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 
/*
Enter the number of nodes and the number of edges: 
5 9
California Texas 30
California Texas 10
Florida California 70
California Florida 75
NewYork California 35
Pennsylvania Florida 18
Pennsylvania Florida 28
California Texas 35
California Pennsylvania 37

Output
Flights from California :
        To Florida with cost 75
        To Pennsylvania with cost 37
        To Texas with cost 10
        To Texas with cost 30
        To Texas with cost 35
Flights from Florida :
        To California with cost 70
Flights from NewYork :
        To California with cost 35
Flights from Pennsylvania :
        To Florida with cost 18
        To Florida with cost 28

No Run Time Error
*/