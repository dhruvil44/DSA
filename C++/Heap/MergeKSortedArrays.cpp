//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

        //element   //row  col
typedef pair<int, pair<int,int> >node;  //For ex:- element=33 is in 0th row and 2nd col.


vector<int> mergekSortedArrays(vector<vector<int> >v) {

  vector<int> ans;

  //make a priority queue (minheap) of type node
  priority_queue<node, vector<node>, greater<node> >pq;

  //insert the 0th element of every row in the pq
  for(int i=0;i<v.size();i++) {
    pq.push({v[i][0],{i,0}});
  }

  while(!pq.empty()) {
    //Get the top node
    node element = pq.top();
    pq.pop();
    int value = element.first;
    int row = element.second.first;
    int col = element.second.second;

    ans.push_back(value);

    //check if further in that row element is present or not
    if(col<v[row].size()-1) {
      col++;
      pq.push({v[row][col],{row,col}});
    }

  }

  return ans;
}


int main() {


  vector<vector<int> > v= {{1,2,33,41},{3,4,5,7},{1,2,11}};


  vector<int> res = mergekSortedArrays(v);

  for(auto x: res) {
    cout<<x<<" ";
  }

  return 0;
}
