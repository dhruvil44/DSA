#include<bits/stdc++.h>

//Checking for the Bipartiteness of the Graph (such that the graph can be colored by 2 colors and no 2 adjacent nodes have same color)

using namespace std;

class Graph{

unordered_map<int,list<int> >l;

public:
  void addEdge(int x, int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);

  }

  //node    visited color
  map<int,pair<bool,int> >visited;

  bool isBipartite_DFS(int src,int c){

    (visited[src]).first=true;
    (visited[src]).second=c;

    for(auto x:l[src])
    {
      //if the nbr is not visited then visit it
      if(!((visited[x]).first))
      {
        if(c==0)
        {
          //mark the color of the nbr as 1 and call further
          if(!isBipartite_DFS(x,1))
          {
            return false;
          }
        }

        else
        {
          //mark the color of the nbr as 0 and call further
          if(!isBipartite_DFS(x,0))
          {
            return false;
          }
        }
      }

      //if the nbr is visited then check if the color of the nbr is same as the current node..if it is then return false.
      else{
        if(visited[x].second == visited[src].second)
        {
          return false;
        }

      }

    }


    return true;

  }


};


int main()
{

Graph g;
g.addEdge(1,2);
g.addEdge(3,2);
g.addEdge(3,4);
g.addEdge(1,4);

cout<<g.isBipartite_DFS(4,0);
cout<<endl;

Graph g1;
g1.addEdge(1,2);
g1.addEdge(2,3);
g1.addEdge(3,5);
g1.addEdge(5,2);
g1.addEdge(4,5);
g1.addEdge(1,4);

cout<<g1.isBipartite_DFS(3,0);

cout<<endl;
Graph g2;

g2.addEdge(3, 2);
g2.addEdge(1, 4);
g2.addEdge(2, 1);
g2.addEdge(5, 3);
g2.addEdge(6, 2);
g2.addEdge(3, 1);

cout<<g2.isBipartite_DFS(3,0);
  return 0;
}
