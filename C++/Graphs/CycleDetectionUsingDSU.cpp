//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Cycle Detection in a undirected graph using Disjoint Set Union Data Structure.

//Here we will use edgelist representation of graph rather than adjacency list.

class Graph{

private:
  int V;  //number of vertices
  list<pair<int,int> >l; //edge list

public:
  void addEdge(int x, int y) {
    l.push_back(make_pair(x,y));
  }

  //DSU Functions
  int findSet(int x, int parent[]) {
    if(parent[x]==-1) {
      return x;
    }

    return findSet(parent[x],parent);
  }

  void unionSet(int x, int y, int parent[]) {
    int s1 = findSet(x,parent);
    int s2 = findSet(y,parent);

    if(s1!=s2) {
      parent[s2] = s1;
    }

  }


  //Cycle contains Function
  bool containsCycle() {
    //Initialize parent array
    int *parent = new int[V];
    for(int i=0;i<V;i++) {
      parent[i]=-1;
    }

    //iterate over all the edges
    for(auto edge: l) {
      int i = edge.first;
      int j = edge.second;

      int s1 = findSet(i,parent);
      int s2 = findSet(j,parent);

      if(s1!=s2) {
        unionSet(i,j,parent);
      }
      else{
        cout<<"Same Parents\n";
        return true;
      }
    }

    return false;
  }
};

int main() {

  Graph g;

  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,1);

  cout<<g.containsCycle()<<endl;


  return 0;
}
