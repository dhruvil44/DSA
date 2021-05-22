//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int make_change(int coins[], int n, int money) {
  int cnt=0;

  while(money>0) {
    //this will give the index of the first element which is just greater than the money value
    int idx = upper_bound(coins,coins+n,money) - coins;

    //as the index value is just greater than the money value index we decreament it by 1
    idx--;

    money = money - coins[idx];

    cnt++;
  }

  return cnt;
}

int main() {


  int money;
  cin>>money;

  int coins[] = {1,2,5,10,20,50,100,200,500,2000};
  int n = sizeof(coins)/sizeof(int);

  cout<<make_change(coins,n,money);
  

  return 0;
}
