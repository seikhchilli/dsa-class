#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

int main(){
  node *start = NULL;
  start = (node *)malloc(sizeof(node));

  start->data = 10;
  start->next = NULL;

  start->next = (node*)malloc(sizeof(node));
  start->next->data = 20;
  start->next->next - NULL;
}
