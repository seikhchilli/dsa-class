#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

void append(node** start, int data){
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

void display(node* start){
  if(start == NULL){
    cout<<"No elements. "<<endl;
    return;
  }

  while(start != NULL){
    cout<<start->data<<" ";
    start = start->next;
  }
  cout<<endl;
}


void del_end_el(node* start){
  if(start == NULL){
    cout<<"List is already empty. "<<endl;
    return;
  }
  if(start->next == NULL){
    cout<<"run"<<endl;
    free(start);
    start = NULL;

    return;
  }
  while(start->next->next != NULL){
    start = start->next;
  }
  free(start->next);
  start->next = NULL;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  node *start = NULL;

  append(&start, 20);
//  append(&start, 40);
///  append(&start, 50);
  //append(&start, 10);

  cout<<"Array before deletion: ";
  display(start);

  del_end_el(start);
  cout<<"Array after deletion: ";
  display(start);

}
