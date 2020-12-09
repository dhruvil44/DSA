//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/word-break-problem-trie-solution/

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


bool search(string s, TrieNode* root)
{
  TrieNode* temp = root;

  for(int i=0;i<s.size();i++)
  {
    if(temp->child[s[i]-'a']==NULL)
    {
      return false;
    }
    temp=temp->child[s[i]-'a'];
  }

  if(temp!=NULL && temp->wordCount>0)
  {
    return true;
  }

  return false;
}

bool wordBreak(string str, TrieNode *root)
{
    int size = str.size();


    if (size == 0)
       return true;

    for (int i=1; i<=size; i++)
    {

        if (search(str.substr(0, i),root) &&
            wordBreak(str.substr(i, size-i), root))
            return true;
    }

    return false;
}

int main()
{

  struct TrieNode* root = makeNewNode();

  string dictionary[] = {"mobile","samsung","sam",
                          "sung","ma","mango",
                          "icecream","and","go","i",
                          "like","ice","cream"};


    for(int i=0;i<13;i++)
    {
      insert(dictionary[i],root);
    }

    cout<<wordBreak("ilikesamsung",root);

  return 0;
}
