#include<iostream>
#include<string>
using namespace std;

const int MAX = 50;

class stacks{
public:
  int capacity;
  int *stack_arr;
  int top = -1;

  stacks(int Capacity){
    capacity = Capacity;
    stack_arr = (int*) malloc(capacity*sizeof(int));
  }


  void push(int data){
    if(top == capacity - 1){
      cout<<"Buffer overflow."<<endl;
      exit(1);
    }
    top++;
    stack_arr[top] = data;
  }

  int pop(){
    if(top == -1){
      cout<<"Buffer underflow."<<endl;
      exit(1);
    }
    int value = stack_arr[top];
    top--;
    return value;
  }

  bool isEmpty(){
    if(top == -1){
      return true;
    }
    return false;
  }

  void display(){
    for(int i = 0; i <= top; i++){
      cout<<stack_arr[i]<<" ";
    }
  }

};

int operate(int b, int a, char c){
  int res;
  switch(c){
    case '/':
      res = b/a;
      break;
    case '*':
      res = b*a;
      break;
    case '+':
      res = b+a;
      break;
    case '-':
      res = b-a;
      break;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stacks s(10);
  string posted = "231*+9-";

  for(int i = 0; i < posted.length(); i++){
    char c = posted[i];
    if(c <= '9' && c >= '0'){
      s.push((c - '0'));
    }
    else{
      s.push(operate(s.pop(), s.pop(), c));
    }
  }

  s.display();



}
