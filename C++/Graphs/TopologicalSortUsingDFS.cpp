//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Find the topological sort using DFS.
//Topological Sorting can be done only in DIRECTED ACYCLIC GRAPH.

template<typename T>
class Graph {

private:
  map<T,list<T> >l;

public:
  void addEdge(T x, T y) {
    l[x].push_back(y);
  }


  void dfs(T src, map<T,bool> &visited, list<T> &topologicalOrdering) {

    visited[src]=true;

    for(auto x: l[src]) {
      if(!visited[x]) {
        dfs(x,visited,topologicalOrdering);
      }
    }

    topologicalOrdering.push_front(src);
  }

  void topologicalSort() {
    map<T,bool> visited;
    for(auto x: l) {
      visited[x.first]=false;
    }

    list<T> topologicalOrdering;

    for(auto x: l) {
      if(!visited[x.first]) {
        dfs(x.first,visited,topologicalOrdering);
      }
    }


    for(T x: topologicalOrdering) {
      cout<<x<<" ";
    }
  }


};


int main() {

  Graph<string> g;

  g.addEdge("A","B");
  g.addEdge("A","C");
  g.addEdge("B","C");
  g.addEdge("E","A");
  g.addEdge("E","D");
  g.addEdge("D","C");

  g.topologicalSort();

  return 0;
}
