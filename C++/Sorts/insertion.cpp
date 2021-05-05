//Author:Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int main()
{

int a[]={8,7,6,5,4,3,2};
int i;
int temp;
for(i=1;i<7;i++)
{

  int j=i;
  int t=i-1;
  while(a[j]<a[t] && j>0)
  {
    temp=a[t];
    a[t]=a[j];
    a[j]=temp;
    t--;
    j--;
  }

}

for(int i=0;i<7;i++)
{
  cout<<a[i]<<" ";
}


  return 0;
}
