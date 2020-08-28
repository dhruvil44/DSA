//Author:Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//Program to find the smallest subarray size with sum>=s

int smallestsubarray(int a[],int s,int n)
{

int start=0;

int smallestize=INT_MAX;

int sum=0;

for(int end=0;end<n;end++)
{
  sum+=a[end];

  if(sum>=s)
  {

    smallestize=min(smallestize,end-start+1);

    while(sum>=s && start<=end)
    {
      sum-=a[start];
      start++;
      if(sum>=s)
      {
      smallestize=min(smallestize,end-start+1);
    }
    }


  }


}


  return smallestize;
}

int main()
{

int s=20;
int a[]={4,7,1,8,2,6,9,12,4,8};
cout<<smallestsubarray(a,s,10);


  return 0;
}
