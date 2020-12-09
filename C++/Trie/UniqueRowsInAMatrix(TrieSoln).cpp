//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
  TrieNode* child[2];
  int wordCount;
};

TrieNode* makeNewNode()
{
  TrieNode* node = new TrieNode;
  node->child[0]=NULL;
  node->child[1]=NULL;
  node->wordCount=0;
  return node;
}

bool insert(vector<int> v, TrieNode* root)
{
  TrieNode* temp = root;
  for(auto x:v)
  {
    if(temp->child[x]==NULL)
    {
      temp->child[x]=makeNewNode();
    }

    temp=temp->child[x];
  }

  if(temp->wordCount>0)
  {
    return true;
  }

  temp->wordCount++;

  return false;
}



int main()
{

int a[3][4]={{1,1,0,1},{1,0,0,1},{1,1,0,1}};

TrieNode* root = makeNewNode();

for(int i=0;i<3;i++)
{
  vector<int> v;
  for(int j=0;j<4;j++)
  {
    v.push_back(a[i][j]);
  }

  if(!insert(v,root))
  {
    for(int j=0;j<4;j++)
    {
      cout<<a[i][j]<<" ";
    }
  }

  cout<<endl;
}



  return 0;
}
