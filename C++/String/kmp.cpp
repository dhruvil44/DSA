//Author: Dhruvil Patel(Dp)

#include<bits/stdc++.h>

using namespace std;


void lps(string pattern, int lpsarray[])
{
  int i,j;
  i=0;
  j=1;

  while(j<pattern.size())
  {
    if(pattern[i]==pattern[j])
    {
      lpsarray[j]=i+1;
      i++;
      j++;
    }

    else{
      lpsarray[j]=0;
      i=0;
      j++;
    }
  }
}

int kmpFun(string text, string pattern)
{

  //First of all compute longest prefix and suffix array
  int lpsarray[pattern.size()]={0};
  lps(pattern,lpsarray);



  //The Algorithm begins here
  int i,j;

  //i pointer to traverse the text
  i=0;

  //j pointer to traverse the pattern
  j=0;

  while(i<text.size())
  {
    if(text[i]==pattern[j])
    {
      i++;
      j++;
    }

    else{

      if(j==0)
      {
        j=0;
        i++;
      }

      else{
        j=lpsarray[j-1];
      }


    }

    if(j==pattern.size())
    {
      return i-j;
    }

  }



  return -1;
}

int main()
{

  string text = "onionionsonio";
  string pattern="onions";

  //It returns the index(0-based) of the starting character from where the pattern matches.
  //It return -1 if there is no pattern in the text.
  cout<<kmpFun(text,pattern);

  return 0;
}
