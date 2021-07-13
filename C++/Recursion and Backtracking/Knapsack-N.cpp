//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given problem is almost similar to the knapsack 0-1 problem but with 1 difference.
//Here we could pick any item multiple times.
//We have infinite supply of all items and we can take any item for anytimes we want to maximize the value.

//Example:-
// n=5 , knapsack = 11
// weights[] = 3 2 4 5 1
// values[] = 4 3 5 6 1

//Output:- 16

//We take second item 4 times and fifth item one time to make the total values 16.

int knapsack_soln(int i, int weights[], int values[], int n, int knapsack) {

  if(i==n) {
    return 0;
  }

  int op1=INT_MIN, op2 = INT_MIN;

  //choose the ith bag
  if(weights[i]<=knapsack) {
    op1 = values[i] + knapsack_soln(i,weights,values,n,knapsack-weights[i]);
  }


  //discard the ith bag
  op2 = knapsack_soln(i+1,weights,values,n,knapsack);

  return max(op1,op2);
}

int main() {

  int n=5;
  int knapsack = 11;

  int weights[] = {3,2,4,5,1};
  int values[] = {4,3,5,6,1};

  cout<<knapsack_soln(0,weights,values,n,knapsack)<<endl;

  return 0;
}
