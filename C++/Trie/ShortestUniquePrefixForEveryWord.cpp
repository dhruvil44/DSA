//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
struct TrieNode{
  struct TrieNode* child[26];
  int prefixCount;
};

struct TrieNode* makeNewNode()
{
  struct TrieNode* node = new TrieNode;
  for(int i=0;i<26;i++)
  {
    node->child[i]=NULL;
  }

  node->prefixCount=0;
  return node;
}

void insert(string s, struct TrieNode* root)
{
  struct TrieNode* temp=root;
  for(int i=0;i<s.size();i++)
  {
    if(temp->child[s[i]-'a']==NULL)
    {
      temp->child[s[i]-'a']=makeNewNode();
    }

    temp=temp->child[s[i]-'a'];
    temp->prefixCount++;
  }
}

void makeTrie(string arr[], int n, struct TrieNode* root)
{
  for(int i=0;i<n;i++)
  {
      insert(arr[i],root);
  }
}

void findPrefix(string s, struct TrieNode* root, string &t)
{
  struct TrieNode* temp = root;

  for(int i=0;i<s.size();i++)
  {
      temp=temp->child[s[i]-'a'];
      t+=s[i];
      if(temp->prefixCount==1)
      {
        return;
      }
  }
}

void findPrefixForAll(string arr[], int n, struct TrieNode* root)
{
  vector<string> prefixes;

  for(int i=0;i<n;i++)
  {
    string s = arr[i];
    string t="";
    findPrefix(s,root,t);
    prefixes.push_back(t);
  }

  for(auto x: prefixes)
  {
    cout<<x<<" ";
  }
}


int main()
{

string arr[]={"zebra","duck","dog","dove"};

struct TrieNode* root = makeNewNode();

makeTrie(arr,4,root);

findPrefixForAll(arr,4,root);

  return 0;
}
