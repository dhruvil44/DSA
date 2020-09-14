#include<bits/stdc++.h>

using namespace std;

// Using Adjacency list for Graph
class Graph{

list<int>*l;
int V;

public:
  Graph(int V)
  {
    this->V = V;
    l=new list<int>[V];
  }

  void addEdge(int x, int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void print()
  {
    for(int i=0;i<V;i++)
    {
      list<int>::iterator it;
      cout<<"Vertex "<<i<<"-> ";
      for(auto x:l[i])
      {
        cout<<x<<" ";
      }
      cout<<endl;
    }
  }

};


int main()
{

  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,0);

  g.print();

  return 0;
}
