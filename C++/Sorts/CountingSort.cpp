//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;


void coutingSort(int a[], int n)
{
  int temp[10000]={0};

  for(int i=0;i<n;i++)
  {
    temp[a[i]]++;
  }


  for(int i=1;i<7;i++)
  {
    temp[i]=temp[i]+temp[i-1];
  }



  int ans[n];

  for(int i=n-1;i>=0;i--)
  {
    ans[--temp[a[i]]]=a[i];
  }

  for(int i=0;i<n;i++)
  {
    a[i]=ans[i];
  }

}

int main()
{

int a[]={4,3,5,1,6};

coutingSort(a,5);

for(int i=0;i<5;i++)
{
  cout<<a[i]<<" ";
}

  return 0;
}
