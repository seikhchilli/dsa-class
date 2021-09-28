#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* next;
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

void display(node *p){
  if(p == NULL){
    cout<<"No elements"<<endl;
    return;
  }
  while(p != NULL){
    cout<<(p->data)<<" ";
    p = p->next;
  }
  cout<<endl;

}

void insert_list(node *start, int position, int data){
  node *p, *temp;
  p = (node* )malloc(sizeof(node));
  p->data = data;
  temp = start;
  for(int i = 1; i < position-1; i++){
    temp = temp->next;
  }
  p->next = temp->next;
  temp->next = p;
}

int main(){
  node *start = NULL;

  add_beg(&start, 10);
  add_beg(&start, 20);
  add_beg(&start, 40);
  add_beg(&start, 60);
  add_beg(&start, 30);

  cout<<"List before insertion: ";
  display(start);

  int position, element;
  cout<<"Enter position to be inserted: ";
  cin>>position;
  cout<<"Enter element to be inserted: ";
  cin>>element;

  insert_list(start, position, element);

  cout<<"List after insertion: ";
  display(start);
}
