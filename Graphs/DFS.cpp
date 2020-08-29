#include<bits/stdc++.h>
//Depth First Search For Graph
using namespace std;

class Graph{

  unordered_map<int,list<int> >l;

public:
  void addEdge(int x,int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void DFS_helper(int src,map<int,bool> &visited)
  {
    cout<<src<<" ";
    visited[src]=true;
    for(int x : l[src])
    {
      if(!visited[x])
      {
        DFS_helper(x,visited);
      }
      
    }
  }

  void DFS(int src)
  {

    map<int,bool> visited;

    for(auto p : l)
    {
      visited[p.first]=false;
    }

    DFS_helper(src,visited);


  }



};


int main()
{

  Graph g;

  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(3,0);
  g.addEdge(4,0);
  g.addEdge(2,5);

  g.DFS(0);


  return 0;
}
