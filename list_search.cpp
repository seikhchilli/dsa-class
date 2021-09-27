#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

void append(node **pr, int data){
  node *p, *temp;
  p = (node *)malloc(sizeof(node));
  p->data = data;
  p->next = NULL;

  if(*pr == NULL){
    *pr = p;
    return;
  }
  temp = *pr;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = p;
}

void display(node *p){
  if(p == NULL){
    cout<<"There are no elements in this list."<<endl;
    return;
  }
  node *temp;
  temp = p;
  cout<<"List: ";
  while(temp != NULL){
    cout<<(temp->data)<<" ";
    temp = temp->next;
  }
  cout<<endl;

}

int search(node *p, int data){
  if(p == NULL){
    return -1;
  }
  node *temp;
  temp = p;
  int pos = 0;
  while(temp != NULL){
    pos++;
    if(temp->data == data){
      return pos;
    }
    temp = temp->next;
  }
  return -1;
}


int main(){
  node *start = NULL;

  append(&start, 10);
  append(&start, 40);
  append(&start, 20);
  append(&start, 20);
  append(&start, 30);

  display(start);
  int n;
  cout<<"Enter the number to be searched: ";
  cin>>n;
  int position = search(start, n);
  cout<<"position: "<<position<<endl;

  return 0;
}
