//Author:Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


struct trieNode{

  trieNode *child[26];
  int wordCount;
};

struct trieNode* init()
{
  struct trieNode *root = new trieNode;
  root->wordCount=0;

  for(int i=0;i<25;i++)
  {
    root->child[i]=NULL;
  }
  return root;
}

struct trieNode* makeNewNode()
{
  struct trieNode *node = new trieNode;
  node->wordCount=0;
  for(int i=0;i<25;i++)
  {
    node->child[i]=NULL;
  }
  return node;
}

void insert(string s,struct trieNode* root)
{
  struct trieNode *temp=root;
  for(int i=0;i<s.size();i++)
  {
    if(temp->child[s[i]-'a']==NULL)
    {
      temp->child[s[i]-'a']=makeNewNode();
    }

    temp = temp->child[s[i]-'a'];
  }

  temp->wordCount++;
}

bool check(string s,struct trieNode* root)
{
  struct trieNode *temp = root;

  for(int i=0;i<s.size();i++)
  {

      if(!temp->child[s[i]-'a'])
      {
        return false;
      }

      temp=temp->child[s[i]-'a'];

  }

  if(temp!=NULL && temp->wordCount!=0)
  {
    return true;
  }
return false;
}

void deleteString(string s, struct trieNode* root)
{
  struct trieNode *temp = root;

  for(int i=0;i<s.size();i++)
  {
    if(temp->child[s[i]-'a'])
    {
      temp=temp->child[s[i]-'a'];
    }

    else{
      cout<<"string not present"<<endl;
      return;
    }
  }

  temp->wordCount=0;
}

int main()
{

trieNode *root=init();

insert("abc",root);
insert("abd",root);
insert("abbd",root);

cout<<check("abbd",root)<<endl;
cout<<check("abc",root)<<endl;

deleteString("abc",root);
cout<<check("abc",root)<<endl;


  return 0;
}
