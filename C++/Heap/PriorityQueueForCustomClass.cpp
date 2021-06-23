//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Generally we have seen priority queue for numbers in the form of minheap and maxheap.
//here we will make priority queue for a custom class and make our own comparator.

class Person{
public:
  string name;
  int age;

  Person() {

  }

  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }
};

class PersonCompare{

public:
  //here we have to use operator "()" overloading
  bool operator()(Person A, Person B) {
    // cout<<"Comparing "<<A.age<<" and "<<B.age<<endl;
    return A.age < B.age;
  }

};

int main() {

  int n;
  cin>>n;

  priority_queue<Person, vector<Person>, PersonCompare> pq;

  for(int i=0;i<n;i++) {
    string name;
    int age;
    cin>>name>>age;

    Person p(name,age);
    pq.push(p);
  }

  //find the first k Person with highest age
  int k=3;
  for(int i=0;i<k;i++) {
    Person p = pq.top();
    cout<<p.name<<" "<<p.age<<endl;
    pq.pop();
  }


  return 0;
}
