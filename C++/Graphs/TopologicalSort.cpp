//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

class Graph{

unordered_map<string,list<string> >L;

public:
  void addEdge(string x,string y)
  {
    L[x].push_back(y);
  }



  void topologicalsort()
  {

    map<string,int> indegree;

    for(auto x:L)
    {
      for(auto y:L[x.first])
      {
        indegree[y]++;
      }
    }




  }


};


int main()
{


  return 0;
}
