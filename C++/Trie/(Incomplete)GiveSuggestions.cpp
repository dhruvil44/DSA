//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//https://www.youtube.com/watch?v=DfkLGiW8vNA&list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl&index=5

struct TrieNode{

  struct TrieNode* child[26];
  int wordCount;
};

struct TrieNode* makeNewNode()
{
  struct TrieNode* node = new TrieNode;
  for(int i=0;i<26;i++)
  {
    node->child[i]=NULL;
  }
  node->wordCount=0;
  return node;
}

void insert(string s, struct TrieNode* root)
{
  struct TrieNode* temp = root;
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

bool isLeaf(struct TrieNode* root)
{
  int c=0;
  for(int i=0;i<26;i++)
  {
    if(root->child[i]==NULL)
    {
      c++;
    }
  }

  if(c==26)
  {
    return true;
  }

  return false;
}



void giveSuggestionsUtil(struct TrieNode* root, string t)
{
  if(root->wordCount>0)
  {
    cout<<t<<endl;
  }

  if(isLeaf(root))
  {
    return;
  }

  for(int i=0;i<26;i++)
  {
    if(root->child[i]!=NULL)
    {
      t.push_back(i+'a');
    }

    giveSuggestionsUtil(root->child[i],t);
  }


}





void giveSuggestions(string s, struct TrieNode* root)
{
  struct TrieNode* temp = root;
  for(int i=0;i<s.size();i++)
  {
    if(temp->child[s[i]-'a']==NULL)
    {
      cout<<"No Suggestions for "<<s<<endl;
      return;
    }

    temp=temp->child[s[i]-'a'];
  }

  string t =  s;
  giveSuggestionsUtil(temp,t);

}


int main()
{
struct TrieNode* root = makeNewNode();

insert("dhruvil",root);
insert("dhruvin",root);
insert("riddhi",root);
insert("rutva",root);
insert("rekha",root);

giveSuggestions("dh",root);

return 0;
}
