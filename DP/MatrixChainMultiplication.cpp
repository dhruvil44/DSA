//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

int MCM(int dim[],int n)
{
  //Creating the table for memoisation
  int ans[5][5]={0};

  int i,j,k,l;
  for(i=1;i<n-1;i++)
  {
    for(l=1;l<n-i;l++)
    {
      int j=l+i;
      if(j<=i)
      {
        ans[l][j]=0;
        continue;
      }

      int mini=INT_MAX;
      for(k=l;k<j;k++)
      {
        int temp = ans[l][k] + ans[k+1][j] + dim[l-1]*dim[k]*dim[j];
        if(temp<mini)
        {
          mini=temp;
        }
      }

      ans[l][j]=mini;
    }
  }


  return ans[1][n-1];
}

int main()
{

int dim[]={5,4,6,2,7};

cout<<"The minimum multiplications required is "<<MCM(dim,5)<<endl;


  return 0;
}
