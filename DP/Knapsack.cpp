//Author: Dhruvil Patel(DP)
#include<bits/stdc++.h>

using namespace std;


int knapsack(int weightknapsack,int weight[],int val[],int n)
{
  int ans[n+1][weightknapsack+1];
  int i,j;
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=weightknapsack;j++)
    {
      if(i==0 || j==0)
      {
        ans[i][j]=0;
      }

      else{
        if(j-weight[i]<0)
        {
          ans[i][j]=ans[i-1][j];
        }
        else{
          ans[i][j]=max(ans[i-1][j],ans[i-1][j-weight[i]]+val[i]);
        }
      }
    }

  }

  return ans[n][weightknapsack];

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
