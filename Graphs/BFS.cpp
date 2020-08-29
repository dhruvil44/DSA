#include<bits/stdc++.h>

//Breadth First Search for Graph

using namespace std;

class Graph{

  unordered_map<int,list<int> >l;

public:
  void addEdge(int x,int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void BFS(int src)
  {
    //done using queue
    queue<int> q;

    ///use a map to store the nodes visited
    map<int,bool> visited;

    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
      cout<<q.front()<<" ";
      for(auto x:l[q.front()])
      {
        if(visited[x]!=true)
        {
          q.push(x);
          visited[x]=true;
        }
      }
      q.pop();

    }

    }



};


int main()
{

  Graph g;
  //0 1 2 3 4 5
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(3,0);
  g.addEdge(4,0);
  g.addEdge(2,5);

  g.BFS(0);
  return 0;
}
