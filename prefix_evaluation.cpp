#include<iostream>
#include<string>
using namespace std;

struct stack{
  int size;
  int top;
  int *stack_arr;
};

stack* createStack(int Size){
  stack* stacks = (stack*)malloc(sizeof(stack));
  stacks->size = Size;
  stacks->top = -1;
  stacks->stack_arr = (int*)malloc(Size*sizeof(int));
  return stacks;
}

void push(stack* stacks, int data){
  if(stacks->top == stacks->size - 1){
    cout<<"Buffer overflow"<<endl;
    return;
  }
  stacks->top = stacks->top + 1;
  stacks->stack_arr[stacks->top] = data;
}

int pop(stack* stacks){
  if(stacks->top == -1){
    cout<<"Buffer underflow"<<endl;
    exit(1);
  }
  int value = stacks->stack_arr[stacks->top];
  stacks->top = stacks->top - 1;
  return value;
}

int operate(int a, int b, char c){
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

void display(stack* stacks){
  if(stacks->top == -1){
    cout<<"stack empty"<<endl;
    return;
  }
  for(int i = 0; i <= stacks->top; i++){
    cout<<(stacks->stack_arr[i])<<" ";
  }
  cout<<endl;
}

int main(){
  string s = "+-/*26318";

  stack* stacks = createStack(20);


  for(int i = s.length() - 1; i >= 0; i--){
    if(s[i] >= '0' && s[i] <= '9'){
      push(stacks, (s[i] - '0'));

    }
    else{
      push(stacks, operate(pop(stacks), pop(stacks), s[i]));
    }
  }

  display(stacks);



}
