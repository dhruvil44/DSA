//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Find the topological sort using BFS.
//Topological Sorting can be done only in DIRECTED ACYCLIC GRAPH.

template<typename T>
class Graph{

private:
  map<T,list<T> > l;

public:
  void addEdge(T x, T y) {
    l[x].push_back(y);
  }

  void topologicalSort() {

    //Initializing all nodes with indegree 0
    map<T,int> indegree;
    for(auto x: l) {
      indegree[x.first]=0;
    }

    //Updating indegree of all nodes according to the graph
    for(auto x: l) {
      for(auto y: x.second) {
        indegree[y]++;
      }
    }

    //visited map
    map<T,bool> visited;
    for(auto x: l) {
      visited[x.first]=false;
    }

    //1) Find the node with 0 indegree and push them in the queue
    queue<T> q;
    for(auto x: l) {
      if(indegree[x.first]==0) {
        q.push(x.first);
      }
    }



    //2. Repeat until q is empty
    while(!q.empty()) {
      T node = q.front();
      q.pop();

      cout<<node<<" ";

      for(auto x: l[node]) {
        indegree[x]--;
        if(indegree[x]==0) {
          q.push(x);
        }
      }

    }

  }


};

int main() {

  Graph<string> g;

  g.addEdge("E","A");
  g.addEdge("E","D");
  g.addEdge("A","B");
  g.addEdge("B","C");
  g.addEdge("A","C");
  g.addEdge("D","C");

  g.topologicalSort();


  return 0;
}
