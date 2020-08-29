//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;


long long int gcd(long long int a , long long int b)
{
    if(b==0)
    {

        return a;
    }
    return gcd(b,a%b);


}

class Graph{


unordered_map<int,list<int> >l;

public:

void addEdge(int x, int y)
{
  l[x].push_back(y);
  l[y].push_back(x);
}

int ans[10000]={0};



void dfs(int a[] , map<int,bool> &visited,int index,vector<int>aux)
{
  visited[index]=true;

  aux.push_back(index);


  for(auto x:l[index])
  {
    if(aux.size()==1)
    {

      ans[index]=-1;

    }
    else{
      
      int f=0;
      for(int i=aux.size()-2;i>=0;i--)
      {
        if(gcd(a[index],a[aux[i]])==1)
        {

          ans[index]=aux[i];
          f=1;
          break;
        }
      }

      if(f==0)
      {
        ans[index]=-1;
      }

    }

    if(!visited[x])
    {
      dfs(a,visited,x,aux);
    }
  }


}

void algo(int a[]){

  map<int,bool> visited;
  vector<int> aux;
  for(auto x:l)
  {
    visited[x.first]=false;
  }

  dfs(a,visited,1,aux);

}

void print()
{
  for (int x=1;x<=l.size();x++)
  {
    cout<<ans[x]<<" ";
  }
}



};


int main()
{

int a[]={-1,16,17,12,7,20,18,7,8};

Graph g;

g.addEdge(6,8);
g.addEdge(3,8);
g.addEdge(8,1);
g.addEdge(2,7);
g.addEdge(2,3);
g.addEdge(7,5);
g.addEdge(2,4);

g.algo(a);

g.print();



  return 0;
}
