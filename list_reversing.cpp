#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* next;
};

void append(node **start, int data){
  node *p, *temp;
  p = (node*)malloc(sizeof(node));
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

void display(node *start){
  if(start == NULL){
    cout<<"List is empty."<<endl;
    return;
  }
  while(start != NULL){
    cout<<start->data<<" ";
    start = start->next;
  }
  cout<<endl;
}

void reverse_list(node **start){
  node *prev, *temp, *next;
  temp = *start;
  next = temp->next;
  temp->next = NULL;
  while(next != NULL){
    prev = temp;
    temp = next;
    next = temp->next;
    temp->next = prev;
  }
  *start = temp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  node *start = NULL;

  append(&start, 20);
  append(&start, 30);
  append(&start, 40);
  append(&start, 50);
  append(&start, 60);

  cout<<"List before revesring: ";
  display(start);

  reverse_list(&start);

  cout<<"List after reversing: ";
  display(start);

}
