#include<bits/stdc++.h>

//Detect whether a cycle is present or not in a Graph
//If cycle is not present in a graph then it is a tree
//Approach 1:-Dfs
//Approach 2:- Check the number of edges:- as if there are 'c' edges then to have a cycle there must be more than 'c-1' edges or else it will form a tree

using namespace std;

class Graph{

unordered_map<int,list<int> >l;

public:
  void addEdge(int x,int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  map<int,bool>visited;

  bool iscycle_helper_dfs(int src,int parent)
  {
    visited[src]=true;

    for(auto x:l[src])
    {
      if(!visited[x])
      {
        if(iscycle_helper_dfs(x,src))
        {
          return true;
        }
      }

      else{
        if(x!=parent)
        {
          return true;
        }
      }
    }

    return false;
    }


};


int main()
{

  Graph g;
 g.addEdge(1, 0);
 g.addEdge(0, 2);
 g.addEdge(2, 1);
 g.addEdge(0, 3);
 g.addEdge(3, 4);

 cout<<g.iscycle_helper_dfs(0,0);
cout<<endl;
 Graph g1;
 g1.addEdge(0,1);
 g1.addEdge(1,2);
 g1.addEdge(2,3);
 g1.addEdge(3,4);
 cout<<g1.iscycle_helper_dfs(0,0);


  return 0;
}
