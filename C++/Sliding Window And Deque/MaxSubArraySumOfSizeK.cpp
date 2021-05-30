//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int maxsumsubarray(int a[],int k,int n)
{

  int currsum=0;
  int best=INT_MIN;


  for(int i=0;i<n;i++)
  {

    currsum+=a[i];

    if(i>=k-1)
    {

      best=max(best,currsum);

      currsum-=a[i-(k-1)];

      }

  }


return best;

}


int main()
{


int a[]={4,7,1,8,2,6,9,2,4,8};

int k=3;

cout<<maxsumsubarray(a,k,10);



  return 0;
}
