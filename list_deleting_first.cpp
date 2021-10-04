#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* next;
};

void append(node **start, int data){
  node *p, *temp;
  p = (node* )malloc(sizeof(node));

  p->data = data;
  p->next = NULL;

  if(*start == NULL){
    *start = p;
    return;
  }
  temp = *start;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = p;
}

void display(node* start){
  if(start == NULL){
    cout<<"No elements."<<endl;
    return;
  }
  while(start != NULL){
    cout<<(start->data)<<" ";
    start = start->next;
  }
  cout<<endl;
}

void del_first_el(node **start){
  if(*start == NULL){
    cout<<"List already empty."<<endl;
  }
  node *temp;
  temp = *start;
  *start = temp->next;
  free(temp);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  node *start = NULL;
                                        //Adding elements to list
  append(&start, 10);
  append(&start, 50);
  append(&start, 30);
  append(&start, 20);

  cout<<"Array before deletion of head: ";
  display(start);

  del_first_el(&start);                   //Deleting head node

  cout<<"Array after deletion of head node: ";
  display(start);
}
