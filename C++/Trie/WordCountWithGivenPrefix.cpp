//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
int prefixCount;
struct TrieNode* child[26];
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

int numberOfWordsWithGivenPrefix(string prefix, struct TrieNode* root)
{
  struct TrieNode* temp = root;
  for(int i=0;i<prefix.size();i++)
  {
    if(temp->child[prefix[i]-'a']==NULL)
    {
      return -1;
    }

    temp=temp->child[prefix[i]-'a'];
  }

  return temp->prefixCount;
}

int main()
{

struct TrieNode* root = makeNewNode();

insert("abc",root);
insert("abdd",root);
insert("acd",root);

cout<<numberOfWordsWithGivenPrefix("ab",root);


  return 0;
}
