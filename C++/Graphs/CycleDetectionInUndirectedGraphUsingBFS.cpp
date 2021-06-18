//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Approach:-
//We will do a simple BFS and if we are able to reach a node which was already visited then
//we can say that there is a cycle.

template<typename T>
class Graph{

private:
  map<T,list<T> >l;

public:
  void addEdge(T x, T y) {
    l[x].push_back(y);
    l[y].push_back(x);
  }


  bool isCycle() {

    map<T,int> visited;
    for(auto x: l) {
      visited[x.first]=false;
    }

    map<T,T> parent;
    for(auto x: l) {
      parent[x.first] = x.first;
    }


    //Start from any node
    T src;
    for(auto x: l) {
      src = x.first;
      break;
    }

    //Start BFS
    queue<T> q;
    q.push(src);
    visited[src]=true;

    while(!q.empty()) {
      T node = q.front();
      q.pop();

      for(auto x: l[node]) {
        if(visited[x] and parent[node]!=x) {
          return true;
        }

        else if(!visited[x]) {
          parent[x]=node;
          visited[x]=true;
          q.push(x);
        }
      }
    }

    return false;
  }

};

int main() {

  Graph<string> g;

  g.addEdge("A","B");
  g.addEdge("C","B");
  // g.addEdge("C","D");
  g.addEdge("D","B");
  g.addEdge("D","E");

  if(g.isCycle()) {
    cout<<"Cycle is present\n";
  }

  else{
    cout<<"No cycle present...Its a tree\n";
  }


  return 0;
}
