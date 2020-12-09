//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
  TrieNode* child[26];
  int wordCount;
};


TrieNode* makeNewNode()
{
  TrieNode* node = new TrieNode;
  for(int i=0;i<26;i++)
  {
    node->child[i]=NULL;
  }
  node->wordCount=0;
  return node;
}



void insert(string s, TrieNode* root)
{
  TrieNode* temp = root;
  for(int i=0;i<s.size();i++)
  {
    if(temp->child[s[i]-'a']==NULL)
    {
      temp->child[s[i]-'a']=makeNewNode();
    }
    temp=temp->child[s[i]-'a'];
  }

  temp->wordCount++;
}

bool isLeaf(TrieNode* root)
{
  for(int i=0;i<26;i++)
  {
    if(root->child[i]!=NULL)
    {
      return false;
    }
  }

  return true;
}


void util(string t, TrieNode* root)
{

  if(isLeaf(root))
  {
    cout<<t<<" ";
    return;
  }

    for(int i=0;i<26;i++)
    {
      if(root->child[i]!=NULL)
      {
        t.push_back(i+'a');
        util(t,root->child[i]);
      }
    }
}

void searchWords(string prefix, TrieNode* root)
{
  TrieNode* temp = root;

  for(int i=0;i<prefix.size();i++)
  {
    if(temp->child[prefix[i]-'a']==NULL)
    {
      cout<<"0 ";
      return;
    }
    temp=temp->child[prefix[i]-'a'];
  }

  string t = prefix;
  util(t,temp);

}


int main()
{

int t;
cin>>t;
while(t--)
{
  int n;
  cin>>n;

  vector<string> stringList;

  TrieNode* root = makeNewNode();

  for(int i=0;i<n;i++)
  {
    string xx;
    cin>>xx;
    stringList.push_back(xx);
    insert(xx,root);
  }

  string query;
  cin>>query;

  for(int i=1;i<=query.size();i++)
  {
      searchWords(query.substr(0,i),root);
      cout<<endl;
  }



}

  return 0;
}
