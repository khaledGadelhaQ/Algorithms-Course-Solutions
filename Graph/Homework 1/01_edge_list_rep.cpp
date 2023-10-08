#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/* Time complexity: O(eloge)
* space complexity: O(e)
* e is the number of Edges
*/
class edge{
public:
  int from;
  int to;
  int cost;

  void print(){
    cout<<"Edge: ("<<from<<" "<<to<<" "<<cost<<")\n";
  }
};

typedef vector<edge> Graph;


void add_graph(Graph &graph, int from , int to , int cost){
    graph.push_back({from,to,cost});
}

bool cmp_edge_cost(edge &edge1, edge &edge2){
    return edge1.cost < edge2.cost;
}

void print_graph(Graph &graph){
    sort(graph.begin(), graph.end(),cmp_edge_cost);
    for(auto edge : graph){
        if(edge.cost > 0)
            edge.print();
    }
}
 
int main(){
     
    cout << "Enter Num of Nodes - Edges: \n";
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph;
    for (int i = 0 ; i < edges ; i++ ){
        int from, to, cost;
        cin >> from >> to >> cost;
        add_graph(graph, from , to, cost);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 
/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10

Output
Edge: (2 1 10)
Edge: (5 4 10)
Edge: (2 5 20)
Edge: (2 3 33)
Edge: (0 5 45)
Edge: (1 4 60)
Edge: (2 0 77)

*/
