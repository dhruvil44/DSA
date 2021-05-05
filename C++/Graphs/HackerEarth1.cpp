//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

class Graph{

map<long long int,list<long long int> >L;

public:

  void addEdge(int x,int y)
  {
    L[x].push_back(y);
    L[y].push_back(x);
  }


  long long int DFS(long long int x,long long int k)
  {
    map<long long int,bool> visited;
    for(auto x:L)
    {
      visited[x.first]=false;
    }

    vector<long long int> v;
    vector<long long int> final;

    DFS_helper(v,visited,x,1,final);

    // for(auto p:final)
    // {
    //   cout<<p<<" ";
    // }

  final.pop_back();

  if(final.size()<k)
  {
    return -1;
  }

  else{
    return final[final.size()-k];
  }

  }

  void DFS_helper(vector<long long int> v,map<long long int,bool>&visited,long long int x,long long int root,vector<long long int> &final)
  {

    v.push_back(root);
    visited[root]=true;
    if(root==x)
    {
      final=v;
      return;
    }

    for(auto p:L[root])
    {
      if(!visited[p])
      {
        DFS_helper(v,visited,x,p,final);
      }
    }

  }

  // void print()
  // {
  //   for(auto x:L)
  //   {
  //     cout<<x.first<<"->";
  //     for(auto y:L[x.first])
  //     {
  //       cout<<y<<" ";
  //     }
  //     cout<<endl;
  //   }
  // }


};


int main()
{

  long long int n,q;

  cin>>n>>q;
  Graph g;

  for(int i=0;i<n-1;i++)
  {
    long long int a,b;
    cin>>a>>b;
    g.addEdge(a,b);

  }


// g.addEdge(1,2);
// g.addEdge(2,3);
// g.addEdge(3,4);
// g.addEdge(2,5);
// g.addEdge(1,6);

// cout<<"Q"<<" \n";
while(q--)
{
  long long int n,k;
  cin>>n>>k;

  cout<<g.DFS(n,k)<<"\n";
}

// cout<<g.DFS(5,3);




  return 0;
}
