#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

void add_beg(node **start, int data){
  node *p;
  p = (node* )malloc(sizeof(node));
  p->data = data;
  p->next = NULL;
  if(*start == NULL){
    *start = p;
    return;
  }
  p->next = *start;
  *start = p;
}

void display(node* p){
  if(p == NULL){
    cout<<"There are no elements in this list."<<endl;
    return;
  }
  node* temp;
  temp = p;
  while(temp != NULL){
    cout<<(temp->data)<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main(){
  node *start = NULL;

  add_beg(&start, 10);
  add_beg(&start, 20);
  add_beg(&start, 0);
  add_beg(&start, 50);

  display(start);
}
