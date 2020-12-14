//Author:Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

class Queue{

  int front;
  int rear;
  int maxSize;


public:

  Queue(int maxSize)
  {
    front=-1;
    rear=-1;
    this->maxSize=maxSize;
  }


  void enqueue(int q[], int data)
  {

    if((rear+1)%maxSize==front)
    {
      cout<<"Queue is full"<<endl;
      return;
    }


    if(front==-1 && rear==-1)
    {
      front=0;
      rear=(rear+1)%maxSize;
      q[rear]=data;
      return;
    }


    rear = (rear+1)%maxSize;
    q[rear]=data;
  }

  void dequeue(int q[])
  {
    if(front==-1)
    {
      cout<<"Queue is empty"<<endl;
      return;
    }

    if(rear==front)
    {
      rear=-1;
      front=-1;
      return;
    }

    front=(front+1)%maxSize;

  }

  void printQueue(int q[])
  {
    if(front==-1)
    {
      cout<<"Queue is empty"<<endl;
      return;
    }

    int tempFront=front;
    while(1)
    {

      if(tempFront==rear)
      {
        cout<<q[tempFront]<<" ";
        break;
      }

      if(tempFront==maxSize)
      {
        tempFront=0;
        continue;
      }
      cout<<q[tempFront]<<" ";
      tempFront++;

    }


  }

  int getFront(int q[])
  {
    if(front==-1)
    {
      cout<<"Queue is empty"<<endl;
      return -1;
    }
    return q[front];
  }

  int getRear(int q[])
  {

    if(rear==-1)
    {
      cout<<"Queue is empty"<<endl;
      return -1;
    }

    return q[rear];
  }


};


int main()
{

  Queue queue(6);
  int q[6];
queue.enqueue(q,1);
queue.enqueue(q,2);
queue.enqueue(q,3);
queue.enqueue(q,4);
queue.enqueue(q,5);
queue.enqueue(q,6);
queue.dequeue(q);
queue.dequeue(q);
queue.dequeue(q);
queue.dequeue(q);

queue.enqueue(q,1);
queue.dequeue(q);
queue.dequeue(q);

queue.printQueue(q);

  return 0;
}
