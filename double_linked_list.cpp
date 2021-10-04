#include<bits/stdc++.h>
using namespace std;

struct node{
  node* prev;
  int data;
  node* next;
};

void add_at_beg(node** start, int data){
  node *p = (node*)malloc(sizeof(node));
  if(p == NULL){
    cout<<"Cannot add new node because of overflow\n";
    return;
  }
  p->prev = NULL;
  p->data = data;
  p->next = NULL;
  if(*start == NULL){
    *start = p;
    return;
  }
  p->next = *start;
  (*start)->prev = p;
  *start = p;

}

void display(node *start){
  if(start == NULL){
    cout<<"List is empty."<<endl;
    return;
  }
  while(start != NULL){
    cout<<(start->data)<<" ";
    start = start->next;
  }
  cout<<endl;
}

int main(){
  node* start = NULL;

  int x, n;
  cout<<"Enter size of list: ";
  cin>>n;
  cout<<"Enter elements of list: "<<endl;
  while(n--){
    cin>>x;
    add_at_beg(&start, x);
  }


  display(start);
}
