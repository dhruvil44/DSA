//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

void permute(char *s, int i) {

  //base case
  if(s[i]=='\0') {
    cout<<s<<" ";
    return;
  }

  //recursive case
  for(int j=i;s[j]!='\0';j++) {
    //swapping the ith character with all the remaining j characters and recursively calling the smaller string.
    swap(s[i],s[j]);
    permute(s,i+1);

    //bactrack...that is to restore the original string by reswapping the characters
    swap(s[i],s[j]);
  }


}


//if we want to get unique permutations and in lexicographically order we can use a Set
void permute_unique(char *s, int i, set<string> &st) {

  if(s[i]=='\0') {
    string str(s);
    st.insert(s);
    return;
  }

  for(int j=i;s[j]!='\0';j++) {
    swap(s[i],s[j]);
    permute_unique(s,i+1,st);

    //bactrack
    swap(s[i],s[j]);
  }

}

int main() {

  char s[10] = "abc";

  permute(s,0);

  cout<<endl;
  cout<<endl;

  char s1[10] = "aba";
  set<string> st;
  permute_unique(s1,0,st);
  for(auto str: st) {
    cout<<str<<" ";
  }

  return 0;
}
