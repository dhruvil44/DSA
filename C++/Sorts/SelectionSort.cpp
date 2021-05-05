//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

void selectionSort(int a[], int n)
{


  for(int i=0;i<n-1;i++)
  {
    int mini = a[i];
    int minIndex=i;
    for(int j=i+1;j<n;j++)
    {
      if(a[j]<=mini)
      {
        minIndex=j;
        mini=a[j];
      }
    }

    int temp=a[i];
    a[i]=mini;
    a[minIndex]=temp;
  }
}

int main()
{


  int a[]={4,3,5,6,1};

  selectionSort(a,5);

  for(int i=0;i<5;i++)
  {
    cout<<a[i]<<" ";
  }

  return 0;
}
