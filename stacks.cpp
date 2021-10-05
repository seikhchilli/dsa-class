#include<bits/stdc++.h>
using namespace std;

const int MAX = 5;

int stack_arr[MAX];
int top = -1;

void push(int data){
  if(top == MAX - 1){
    cout<<"Buffer overflow"<<endl;
    return;
  }
  top++;
  stack_arr[top] = data;
}

int pop(){
  if(top == -1){
    cout<<"Stack underflow."<<endl;
    exit(1);
  }
  int value;
  value = stack_arr[top];
  top--;
  return value;
}

bool isFull(){
  if(top == MAX - 1){
    return true;
  }
  return false;
}

bool isEmpty(){
  if(top == -1){
    return true;
  }
  return false;
}

void display(){
  if(top == -1){
    cout<<"Empty stack."<<endl;
    return ;
  }
  for(int i = 0; i <= top; i++){
    cout<<stack_arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  push(1);
  push(2);
  push(3);
  push(4);

  cout<<pop()<<endl;
  push(5);
  if(isFull()){
    cout<<"Stack is full."<<endl;
  }
  else{
    cout<<"Stack is not full."<<endl;
  }
  display();

}
