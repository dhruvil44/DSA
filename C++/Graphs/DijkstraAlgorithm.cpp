//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

class Graph{

private:
  map<int,list<pair<int,int> > > l;

public:
  void addEdge(int x, int y, int weight, bool bidirectional=true) {
    l[x].push_back(make_pair(y,weight));

    if(bidirectional) {
      l[y].push_back(make_pair(x,weight));
    }
  }


  void dijkstra (int src) {

    map<int,int> dis;
    for(auto x: l) {
      dis[x.first] = INT_MAX;
    }

    dis[src]=0;

    //We use set because set by default stores the value in increasing order.
    //And here we want that the minimum distance node should be first, thats why we use a set.

            //dis,node
    set<pair<int,int> >s;
    s.insert(make_pair(0,src));


    while(!s.empty()) {

      //fetching the first element of the set
      auto p = *(s.begin());
      int node = p.second;
      int nodeDis = p.first;

      //popping the first element
      s.erase(s.begin());

      for(auto x: l[node]) {
        if(nodeDis + x.second < dis[x.first]) {

          
          auto it = s.find(make_pair(dis[x.first],x.first));

          if(it!=s.end()) {
            s.erase(it);
          }

          dis[x.first] = nodeDis + x.second;
          s.insert(make_pair(dis[x.first],x.first));
        }
      }

    }

    for(auto x: dis) {
      cout<<"The distance of "<<x.first<<" from "<<src<<" is "<<x.second<<endl;
    }

  }

};


int main() {

  Graph g;
  g.addEdge(1,2,1);
  g.addEdge(1,3,4);
  g.addEdge(2,3,1);
  g.addEdge(3,4,2);
  g.addEdge(1,4,7);

  g.dijkstra(1);

  cout<<endl;

  Graph g1;
  g1.addEdge(0,1,4);
  g1.addEdge(0,2,1);
  g1.addEdge(1,2,2);
  g1.addEdge(2,5,1);
  g1.addEdge(5,4,2);
  g1.addEdge(3,4,3);
  g1.addEdge(1,3,8);

  g1.dijkstra(0);



  return 0;
}
