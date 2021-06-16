//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a Undirected and Unweighted Graph Or All the Edges with same weights.
//Find the Shortest Path to all Nodes from the given Source Node.

//In Undirected and unweighted Graph we can simply use BFS to find the shortest path.

class Graph{

private:
  map<string,list<string> >l;

public:
  void addEdge(string x, string y) {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void bfs(string src) {

    map<string,int> dist;
    for(auto x: l) {
      dist[x.first] = INT_MAX;
    }

    dist[src]=0;
    queue<string> q;
    q.push(src);

    while(!q.empty()) {
      string node = q.front();
      q.pop();

      for(auto x: l[node]) {
        if(dist[x]==INT_MAX) {
          dist[x] = dist[node]+1;
          q.push(x);
        }
      }
    }

      for(auto x: l) {
        cout<<"Distance from "<<src <<" to "<<x.first<<" is "<<dist[x.first]<<endl;
      }
  }





};

int main() {

  Graph g;

  g.addEdge("A","B");
  g.addEdge("B","C");
  g.addEdge("A","E");
  g.addEdge("E","B");
  g.addEdge("E","F");
  g.addEdge("C","F");
  g.addEdge("F","D");

  g.bfs("E");


  return 0;
}
