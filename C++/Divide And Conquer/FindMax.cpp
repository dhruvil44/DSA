// Author : Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;


int maxi(int a[],int s,int e)
{
  if(s>=e)
  {
    return a[s];
  }
  int mid=(s+e)/2;
  int m1=maxi(a,0,mid);
  int m2=maxi(a,mid+1 ,e);

  return max(m1,m2);
}


int main()
{

int a[]={11,22,3};
int m = maxi(a,0,2);
cout<<m;



  return 0;
}
