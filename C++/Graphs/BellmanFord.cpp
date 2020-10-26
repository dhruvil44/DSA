#include<bits/stdc++.h>

//Shortest Path from a Source implementing BellmanFord Algorithm

using namespace std;

class Graph{

unordered_map<int,list<pair<int,int> > > l;

public:
  void addEdge(int x, int y , int weight)
  {
    l[x].push_back(make_pair(y,weight));
    l[y].push_back(make_pair(x,weight));
  }

  void print()
  {
    for(auto p:l)
    {
      cout<<p.first<<"-> ";

      for(auto x:p.second)
      {
        cout<<"{ "<<x.first<<" , "<<x.second<<" }";
      }
      cout<<endl;

}
}

/*int BellmanFordHelper(int src,int dest,map<int,int> &dis)
{

queue<int> q;
map<int,bool> dis1;

q.push(src);


for(auto x:l)
{


  for(auto p : x.second)
  {
      if(p.first==src)
      {
        continue;
      }
      dis[p.first]=min(dis[p.first],dis[x.first]+p.second);


  }




}

return dis[dest];

}*/

int BellmanFord(int src,int dest)
{

map<int,int> dis;

for(auto p:l)
{
  if(p.first==src)
  {
    dis[src]=0;
  }
  else{
    dis[p.first]=INT_MAX;
  }

  for(auto x:l)
  {
    for(auto p : x.second)
    {
        if(p.first==src)
        {
          continue;
        }
        dis[p.first]=min(dis[p.first],dis[x.first]+p.second);
          }
}

  return dis[dest];
}

}


};


int main()
{

  Graph g;
  g.addEdge(1,2,2);
  g.addEdge(2,5,5);
  g.addEdge(5,4,2);
  g.addEdge(4,2,3);
  g.addEdge(1,4,7);
  g.addEdge(1,3,3);
  g.addEdge(3,4,2);


  cout<<g.BellmanFord(1,4);
  return 0;
}
