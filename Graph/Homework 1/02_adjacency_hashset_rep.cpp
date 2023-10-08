#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/* Time complexity: 
* O(1) add/remove/check node
* O(S) iterate on neighbours (S = the size of the set) 
* space complexity: O(e) (e is the number of Edges)
*/
typedef vector<unordered_set<int>> Graph;

void add_neighbour(Graph &graph, int from, int to){
    graph[from].insert(to);
}

void print_graph(Graph &graph){
   
    int nodes = graph.size();
    for(int i = 0 ; i < nodes;  i++){
        cout << "Node: "<<i<<" has neighbours: ";
        for(auto val : graph[i]){
            cout << val <<" ";
        }
        cout << endl;
    }

}


int main(){
     
    cout << "Enter Num of Nodes - Edges: \n";
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);
    for (int i = 0 ; i < edges ; i++ ){
        int from, to;
        cin >> from >> to ;
        add_neighbour(graph, from , to);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 

/*

6 7
2 1 
2 5 
2 0 
2 3 
0 5 
1 4 
5 4 

Output
Node: 0 has neighbours: 5 
Node: 1 has neighbours: 4 
Node: 2 has neighbours: 3 0 5 1 
Node: 3 has neighbours: 
Node: 4 has neighbours: 
Node: 5 has neighbours: 4 



*/