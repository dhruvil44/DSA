#include<bits/stdc++.h>

//using HashMap for the Graph

using namespace std;
class Graph{

unordered_map<string,list<pair<string,int> > > l;

public:
  void addEdge(string src,string des,bool isbidir,int weight)
  {
    l[src].push_back(make_pair(des,weight));
    if(isbidir)
    {
      l[des].push_back(make_pair(src,weight));
    }


  }

  void print()
  {
    for(auto x:l)
    {
      cout<<x.first<<"-> ";
      for(auto y:(x.second))
      {
        cout<<y.first<<" "<<y.second<<", ";
      }
      cout<<endl;
    }




  }





};


int main()
{

  Graph g;
  g.addEdge("A","B",true,20);
  g.addEdge("B","D",true,40);
  g.addEdge("A","C",true,10);
  g.addEdge("C","D",true,40);
  g.addEdge("A","D",false,50);

  g.print();



}
