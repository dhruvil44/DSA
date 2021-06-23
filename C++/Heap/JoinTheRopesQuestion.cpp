//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given n ropes with their lengths. At a time you can select any 2 ropes A and B and join them.
//So the new length of the rope will be A+B and cost of this operation is also A+B.
//The task is to join all the ropes in minimum cost.

//Ex:- ropes[] = {2,3,4,6}
//First select 2 and 3 and join them so the cost will be 2+3=5. Now the array becomes = {5,4,6}.
//select 4 and 5 so the cost will be 4+5 = 9. Now the array becomes = {9,6}.
//Select 9 and 6 and the cost will be 9+6 = 15. Now all the ropes are joined.
//So the total cost = 5 + 9 + 15 = 29 which is the minimum possible cost.

//Algo:-
//Here we select the first 2 minimum length ropes and join them and insert the new length rope.
//Repeat the same process untill we get a single rope.


int join_ropes(int ropes[], int n) {

  //creating a minHeap priority queue
  priority_queue<int, vector<int> , greater<int> >pq(ropes,ropes+n);

  int cost=0;

  while(pq.size()>1) {
    //getting the first smallest element.
    int a = pq.top();
    //popping the element
    pq.pop();

    //again getting the smallest element.
    int b = pq.top();
    pq.pop();

    int new_rope = a+b;

    cost = cost + new_rope;

    //push the new rope in the priority_queue
    pq.push(new_rope);
  }

  return cost;
}

int main() {

  int ropes[] = {2,6,4,3};
  int n = sizeof(ropes)/sizeof(int);

  cout<<join_ropes(ropes,n);


  return 0;
}
