#include<bits/stdc++.h>
using namespace std;
const int MAX = 50;

char stack_arr[MAX];
int top = -1;

int prec(char c){
  if(c == '^'){
    return 3;
  }
  if(c == '*' || c == '/'){
    return 2;
  }
  if(c == '+' || c == '-'){
    return 1;
  }
  return -1;
}

void push(char data){
  if(top == MAX - 1){
    cout<<"Buffer overflow"<<endl;
    exit(1);
  }
  top++;
  stack_arr[top] = data;
}

char pop(){
  if(top == -1){
    cout<<"Buffer underflow"<<endl;
    exit(1);
  }
  char value = stack_arr[top];
  top--;
  return value;
}

bool isEmpty(){
  if(top == -1){
    return true;
  }
  return false;
}

void infix_2_postfix(string s){
  string result;

  for(int i = 0; i < s.length(); i++){
    char c = s[i];
    if(('z' >= c && 'a' <= c) || ('9' >= c && '0' <= c)){
      result += c;
    }

    else if(c == '('){
      push(c);
    }

    else if( c == ')'){
      while(stack_arr[top] != '('){
        result += pop();
      }
      pop();
    }

    else{
      while(!isEmpty() && prec(c) <= prec(stack_arr[top])){
        result += pop();
      }
      push(c);
    }
  }
  while (!isEmpty()) {
    result += pop();
  }
  cout<<result<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string exp = "a+b*(c^d-e)^(f+g*h)-i";
  infix_2_postfix(exp);

}
