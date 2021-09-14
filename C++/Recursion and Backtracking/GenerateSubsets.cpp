//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(int i, int v[], int n, int j, int subsequence[]) {

  if(i==n) {
    int idx=0;
    while(idx<j) {
      cout<<subsequence[idx++]<<" ";
    }
    cout<<endl;
    return;
  }

  //include the current element
  subsequence[j] = v[i];
  generate_subsequence(i+1, v, n, j+1, subsequence);


  //discard the current element
  generate_subsequence(i+1,v, n , j,subsequence);

}

int main() {

    int v[4] = {1,2,3,4};

    int n = 4;

    int subsequence[100];

    generate_subsequence(0,v,4,0,subsequence);

  return 0;
}
