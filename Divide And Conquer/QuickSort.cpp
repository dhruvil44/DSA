/*Author: Dhruvil Patel(DP)*/

#include<bits/stdc++.h>

using namespace std;




void quicksort(int a[],int l,int h)
{
    if(l>=h)
    {
      return;
    }
    int pivot = a[l];
    cout<<pivot<<endl;
    int i=l+1;
    int j=h;
    int t;


    while(i<j)
    {
      while(a[i]<=pivot)
      {
        i++;
      }
      while (a[j]>pivot) {
        j--;
      }

      if(i<j)
      {
          t=a[i];
          a[i]=a[j];
          a[j]=t;
      }

    }

    t=a[l];
    a[l]=a[j];
    a[j]=t;

    quicksort(a,l,j-1);
    quicksort(a,j+1,h);


}

int main()
{

  int a[]={7,6,5,4,3,2,1};

  quicksort(a,0,6);

  for(int i=0;i<7;i++)
  {
    cout<<a[i]<<" ";
  }



  return 0;
}
