//Author:Dhruvil Patel(DP)
#include<bits/stdc++.h>

using namespace std;

class Graph{

unordered_map<string,list<pair<string,int> > >L;

public:
  void addEdge(string x,string y,int weight)
  {
    L[x].push_back({y,weight});
    L[y].push_back({x,weight});
  }

  map<string,int> dis;
  void dijkstra(string src)
  {


    map<string,bool> visited;

    for(auto x:L)
    {
      if(x.first==src)
      {
        dis[x.first]=0;
      }
      else{
      dis[x.first]=INT_MAX;
      }
    }


  for(auto x:L)
  {
    visited[x.first]=false;
  }


  //Code for Logic begins here
  while(1)
  {
      for(auto p:L[src])
      {
        if(!visited[p.first])
        {
          if(dis[src]+p.second < dis[p.first])
            {
              dis[p.first]=dis[src]+p.second;
            }
        }

      }

    visited[src]=true;

    int mindis=INT_MAX;
    string u;
    int f=0;
    for(auto x:dis)
    {
      if(x.second<mindis && !visited[x.first])
      {
        f=1;
        mindis=x.second;
        u=x.first;
      }
    }

    if(f==0)
    {
      break;
    }
    else{
      src=u;
      continue;
    }

  }


}

void printdistance()
{
  for(auto x:dis)
  {
    cout<<x.first<<"->"<<x.second<<endl;
  }
}


};

int main()
{

Graph g;
g.addEdge("A","B",8);
g.addEdge("A","D",9);
g.addEdge("A","C",6);
g.addEdge("C","D",1);
g.addEdge("B","D",4);
g.addEdge("E","D",2);
g.addEdge("D","G",5);
g.addEdge("D","F",3);
g.addEdge("G","F",2);
g.addEdge("G","E",1);

g.dijkstra("D");
g.printdistance();
  return 0;
}
