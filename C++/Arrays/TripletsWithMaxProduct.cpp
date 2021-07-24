//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given an array.
//Find out the triplets with maximum product possible.

//Approach:-
//Find the max, second max and third max.
//Find the min, second min.

//The ans will be maximum(max*second max*third max , min*second min*max).




int main() {

  int a[] = {1, -4, 3, -6, 7, 0};
  int n = 6;


  sort(a,a+n);

  int maxi, second_maxi, third_maxi;

  maxi = a[n-1];
  second_maxi = a[n-2];
  third_maxi = a[n-3];

  int mini, second_mini;

  mini = a[0];
  second_mini = a[1];

  cout<<max(maxi*second_maxi*third_maxi , maxi*mini*second_mini);

  return 0;
}
