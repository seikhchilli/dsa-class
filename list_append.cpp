#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

void append(node **, int);
void display(node *);

int main(){
  node *start = NULL;
  append(&start, 20);
  append(&start, 30);
  append(&start, 40);
  display(start);
}

void append(node **ps, int x){
  node *p, *temp;
  p = (node *)malloc(sizeof(node));
  p->data = x;
  p->next = NULL;
  if(*ps == NULL){
    *ps = p;
    return;
  }
  temp = *ps;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = p;
}

void display(node *p){
  if(p == NULL){
    cout<<"There is no element in the list."<<endl;
    return;
  }
  while(p != NULL){
    cout<<(p->data)<<endl;
    p = p->next;
  }
}
