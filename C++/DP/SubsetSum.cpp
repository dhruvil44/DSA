//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


bool subsetsum(int a[],int sum,int sizeOfArray)
{
  //Table
  bool ans[sizeOfArray][sum+1];

int i,j;
  for(i=0;i<sizeOfArray;i++)
  {
    for(j=0;j<=sum;j++)
    {
      ans[i][j]=0;
    }
  }




  //Base Condition
  for(i=0;i<sizeOfArray;i++)
  {
    ans[i][0]=true;
  }

  //Base Condition
  for(j=1;j<=sum;j++)
  {
    if(a[0]==j)
    {
      ans[0][j]=true;
    }
  }



  for(i=1;i<sizeOfArray;i++)
  {
    for(j=1;j<=sum;j++)
    {

      if(ans[i-1][j])
      {
        ans[i][j]=true;
      }

      else if(j>=a[i])
      {
        ans[i][j]=ans[i-1][j-a[i]];
      }
    }
  }

  // for(i=0;i<sizeOfArray;i++)
  // {
  //   for(j=0;j<=sum;j++)
  //   {
  //     cout<<ans[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

return ans[sizeOfArray-1][sum];

}


int main()
{

int a[]={1,2,3,5};

int sum=13;
int sizeOfArray=4;

 cout<<subsetsum(a,sum,sizeOfArray);


  return 0;
}
