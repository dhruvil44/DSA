#include<bits/stdc++.h>
using namespace std;

class Queue{
  private:
    int *arr;
    int front;
    int rear;
    int maxSize;

  public:
    Queue(int defaultSize=5) {
      arr = new int[defaultSize];
      this->maxSize = defaultSize;
      this->front=-1;
      this->rear=-1;
      cout<<"Queue created\n";
    }

    bool full() {
      return (((rear+1)%maxSize)==front);
    }

    bool empty() {

      if(front==-1) {
        return true;
      }

      return false;
    }

    void push(int data) {

      if(front==-1) {
        front=0;
        rear = (rear+1)%maxSize;
        arr[rear]=data;
        cout<<"Pushed "<<data<<"\n";
        return;
      }

      if((rear+1)%maxSize==front) {
        return;
      }

      rear = (rear+1)%maxSize;
      arr[rear]=data;
      cout<<"Pushed "<<data<<"\n";
    }

    void pop() {

      if(front==-1) {
        return;
      }

      if(front==rear) {
        front=-1;
        rear=-1;
        return;
      }

      front++;
    }

    int getFront() {
      return arr[front];
    }

};

int main() {

  Queue q(10);

  for(int i=1;i<=6;i++) {
    q.push(i);
  }

  while(!q.empty()) {
    cout<<q.getFront()<<endl;
    q.pop();
  }



  return 0;
}
