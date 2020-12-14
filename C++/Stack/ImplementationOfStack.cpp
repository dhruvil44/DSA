//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;


class Stack
{
   int maxSize;
   int top;

public:

  //initiating the stack
  Stack(int maxSize)
  {
    this->maxSize=maxSize;
    top=-1;
  }

  //returns the total capacity of the stack
  int getCapacity()
  {
    return this->maxSize;
  }


  //pushes the data on the top of the stack
  void push(int data,int stack[])
  {
    if(top==maxSize)
    {
      cout<<"Stack is full"<<endl;
      return;
    }
    stack[++top]=data;
  }


  //pops the top element
  int pop(int stack[])
  {
    if(top==-1)
    {
      cout<<"Stack is empty"<<endl;
      return -1;
    }
    return stack[top--];
  }

  //returns the top element
  int peek(int stack[])
  {
    if(top==-1)
    {
      cout<<"Stack is empty"<<endl;
      return -1;
    }

    return stack[top];
  }


  //returns the size of the stack
  int getSize()
  {
    return top+1;
  }


  //checks if the stack is empty
  bool isEmpty()
  {
    return (top==-1);
  }

};

int main()
{

Stack stack(10);

int stackArr[stack.getSize()];

stack.push(1,stackArr);
stack.push(22,stackArr);
stack.push(11,stackArr);

cout<<stack.peek(stackArr);
cout<<endl;
cout<<stack.getSize();


  return 0;
}
