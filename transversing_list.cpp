#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void count_nodes(node*);

int main(){
  node *start = NULL;
  start = (node* )malloc(sizeof(node));

  start->data = 10;
  start->next = NULL;
  cout<<"done"<<endl;

  start->next = (node* )malloc(sizeof(node));
  start->next->data = 20;
  start->next->next = NULL;
  cout<<"done 2"<<endl;

  start->next->next = (node* )malloc(sizeof(node));
  start->next->next->data = 30;
  start->next->next->next = NULL;
  cout<<"done 3"<<endl;

  count_nodes(start);
}

void count_nodes(node *p){
  int count = 1;
  if(p->next == NULL){
    cout<<"There is no nodes."<<endl;
    return;
  }
  while(p->next != NULL){
    count++;
    p = p->next;
  }
  cout<<count<<endl;
}
