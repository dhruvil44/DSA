//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

#define INF 10000

/*
By this algo, we can find shortest path from any node to any node.
In Dijkstra we could only find shortest path from one node to all nodes.

Its a DP based solution
Time Complexity = o(N^3)
*/


void floyd_warshall(vector<vector<int>> graph) {

  vector<vector<int>> dist(graph);

  int V = graph.size();

  for(int intermediate_node = 0; intermediate_node<V; intermediate_node++) {

    for(int i=0; i<V; i++) {
      for(int j=0; j<V; j++) {

        if(dist[i][j] > dist[i][intermediate_node] + dist[intermediate_node][j]) {
          dist[i][j] =  dist[i][intermediate_node] + dist[intermediate_node][j];
        }

      }
    }

  }


  for(int i=0;i<dist.size();i++) {
    for(int j=0;j<dist.size();j++) {
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }

}


int main() {


  vector<vector<int>> graph = {
                                {0,INF,-2,INF},
                                {4,0,3,INF},
                                {INF,INF,0,2},
                                {INF,-1,INF,0}
                              };
  floyd_warshall(graph);



  return 0;
}
