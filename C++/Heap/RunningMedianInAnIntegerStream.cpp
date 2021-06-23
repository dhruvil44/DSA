//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Take an integer stream input until the input is -1.
//Your task is to print the median everytime an integer is taken as an input.

//For ex:- Input = 1  Output = 1  Because median of 1 is 1
           // Input = 1  Output = 1  Because median of 1,1 is 1
           // Input = 4  Output = 1  Because medain of 1,1,4 is 1
           // Input = 5  Output = 2.5 Because median of 1,1,4,5 is 2.5
           // Input = 0  Output = 1   Because median of 0,1,1,4,5 is 1
           // Input = -1  Terminate


int main() {

  priority_queue<int> leftHeap; //max heap
  priority_queue<int, vector<int>, greater<int> >rightHeap; //min heap


  int data;
  cin>>data;

  leftHeap.push(data);

  float median = data;
  cout<<"Median is " <<data<<endl;


  cin>>data;

  while(data!=-1) {

    if(data<=median) {

      if(leftHeap.size()>rightHeap.size()) {
        rightHeap.push(leftHeap.top());
        leftHeap.pop();
        leftHeap.push(data);

        median = (leftHeap.top()+rightHeap.top())/2.0;
      }

      else if(leftHeap.size()==rightHeap.size()) {
        leftHeap.push(data);
        median = leftHeap.top();
      }

      else {
        leftHeap.push(data);
        median = (leftHeap.top() + rightHeap.top())/2.0;
      }

    }


    else if(data>median) {
      if(rightHeap.size()>leftHeap.size()) {
        leftHeap.push(rightHeap.top());
        rightHeap.pop();

        rightHeap.push(data);
        median = (leftHeap.top() + rightHeap.top())/2.0;
      }

      else if(rightHeap.size() == leftHeap.size()) {
        rightHeap.push(data);
        median = rightHeap.top();
      }

      else{
        rightHeap.push(data);
        median = (leftHeap.top() + rightHeap.top())/2.0;
      }
    }

    cout<<"Median is "<<median<<endl;

    cin>>data;

  }

  return 0;
}
