//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

private:
  map<T,list<T> >l;

public:
  void addEdge(T x, T y) {
    l[x].push_back(y);
    l[y].push_back(x);
  }


  void dfs(T src, map<T,bool> &visited) {

    visited[src]=true;
    cout<<src<<" ";

    for(auto x: l[src]) {
      if(!visited[x]) {
        dfs(x,visited);
      }
    }

  }

  void connectedComponents() {
    int cnt=1;
    map<T,bool> visited;

    for(auto x: l) {
      visited[x.first]=false;
    }

    for(auto x: visited) {
      if(x.second==false) {

        cout<<"Component "<<cnt<<"-> ";
        dfs(x.first,visited);
        cout<<endl;
        cnt++;
      }
    }
  }

};

int main() {

  Graph<char> g;

  g.addEdge('A','B');
  g.addEdge('C','B');
  g.addEdge('A','C');
  g.addEdge('D','E');
  g.addEdge('F','G');
  g.addEdge('G','H');
  g.addEdge('X','X');

  g.connectedComponents();



  return 0;
}
