//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Cycle Detection In Directed Graph Using DFS.

class Graph{
private:
  map<int,list<int> >l;

public:
  void addEdge(int x, int y) {
    l[x].push_back(y);
  }

  bool cycle_util(int node, map<int,bool> &visited, map<int,bool> &stack) {
    visited[node]=true;
    stack[node]=true;

    for(auto x: l[node]) {
      if(stack[x]==true) {
        return true;
      }

      else if(visited[x]==false) {
        bool isCycle = cycle_util(x,visited,stack);

        if(isCycle==true) {
          return true;
        }

      }
    }



    stack[node]=false;
    return false;
  }

  bool contains_cycle() {
    map<int,bool> visited;
    map<int,bool> stack;

    for(auto x: l) {
      visited[x.first]=false;
      stack[x.first]=false;
    }

    return cycle_util(0,visited,stack);
  }
};


int main() {

  Graph g;

  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.addEdge(1,5);
  g.addEdge(5,6);
  g.addEdge(4,2);

  if(g.contains_cycle()) {
    cout<<"Graph contains cycle";
  }
  else{
    cout<<"No Cycle Present...Its a tree";
  }



  return 0;
}
