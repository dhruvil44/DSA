//Author: Dhruvil Patel

// We are given a circular array, print the next greater number for every element.
// If it is not found print -1 for that number.
// To find the next greater number for element Ai , start from index i + 1 and
// go uptil the last index after which we start looking for the greater number
// from the starting index of the array since array is circular.

//Input:- 3
        // 1  2  3
//Output   2  3 -1

//Input:- 3
          // 1  2  0
// Output    2 -1  1


//Approach:-
//Here as we are given a circular subarray we can append the array to itself.
//And then we can use a stack to solve this problem.

#include<bits/stdc++.h>
using namespace std;

int main() {

  long long int n;
  cin>>n;

  vector<long long int>v(n);
  for(long long int i=0;i<n;i++) {
    cin>>v[i];
  }



  //appending the elements to the back
  for(long long int i=0;i<n;i++) {
    v.push_back(v[i]);
  }



  //So now the size of the vector becomes 2*n.

  //Instead of pushing elements in the stack we will push the index number of that element
  stack<long long int>st;

  long long int ans[n];
  for(long long int i=0;i<n;i++) {
    ans[i] = -1;
  }

  for(long long int i=0;i<v.size();i++) {
    if(st.empty()) {
      st.push(i%n);
      continue;   //pushing %n because it will handle the overflow case
    }

    if(v[i]<=v[st.top()]) {
      st.push(i%n);
    }

    else{
      while(!st.empty() and v[i]>v[st.top()]) {
          ans[st.top()]=v[i];
          st.pop();
      }
      st.push(i%n);
    }


  }

  for(long long int i=0;i<n;i++) {
    cout<<ans[i]<<" ";
  }


  return 0;
}
