//Author: Dhruvil Patel(DP)
#include<bits/stdc++.h>

using namespace std;


int knapsack(int weightknapsack,int weight[],int val[],int n)
{
  int ans[n][weightknapsack+1]={0};
  int i,j;

  for(i=0;i<n;i++)
  {
    for(j=0;j<=weightknapsack;j++)
    {
      if(j==0)
      {
        ans[i][j]=0;
        continue;
      }

      if(j<weight[i])
      {
        if(i==0)
        {
          ans[i][j]=0;
        }
        else{
        ans[i][j]=ans[i-1][j];
      }
      }
      else{
        if(i==0)
        {
          ans[i][j]=val[i];
        }
        else{
        ans[i][j]=max(ans[i-1][j],ans[i-1][j-weight[i]]+val[i]);
      }
    }
    }
  }

for(i=0;i<n;i++)
{
  for(j=0;j<=weightknapsack;j++)
  {
    cout<<ans[i][j]<<" ";
  }
  cout << '\n';
}
return ans[n-1][weightknapsack];
}

int main() {
   cout << "Enter the number of items in a Knapsack Bag:";
   int n, weightknapsack;
   cin >> n;
   int val[n], weight[n];
   for (int i = 0; i < n; i++) {
      cout << "Enter value for item " << i+1 << ":"<<endl;
      cin >> val[i];
      cout<<"Enter the weight for item "<<i+1<<":"<<endl;
      cin >> weight[i];
   }
   cout << "Enter the capacity of knapsack :";
   cin >> weightknapsack;
   cout << "The optimal answer is "<<knapsack(weightknapsack, weight, val, n);
   return 0;
}
