#include<bits/stdc++.h>
using namespace std;

struct node{
  node *prev;
  int data;
  node *next;
};

void append(node** start, int data){
  node *p = (node*)malloc(sizeof(node));
  if(p == NULL){
    cout<<"Buffer overflow"<<endl;
    return;
  }
  p->prev = NULL;
  p->data = data;
  p->next = NULL;
  if(*start == NULL){
    *start = p;
    return;
  }
  node *temp = *start;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = p;
  temp->next->prev = temp;
}

void display(node* start){
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  node *start = NULL;

  append(&start, 20);
  append(&start, 30);
  append(&start, 40);
  append(&start, 50);
  append(&start, 60);

  display(start);

}
