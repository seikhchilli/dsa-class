#include<iostream>
using namespace std;

struct node{
  int data;
  node *next;
};

struct Queue{
  node *front, *rear;

};

void enequeue(Queue *queue, int data){
  node *temp = (node*)malloc(sizeof(node));
  temp->data = data;
  temp->next = NULL;
  if(queue->rear == NULL){
    queue->front = queue->rear = temp;
  }
  queue->rear->next = temp;
  queue->rear = temp;
  cout<<"enequeued"<<endl;
}

int dequeue(Queue *queue){
  int val = queue->front->data;
  queue->front = queue->front->next;
  return val;
}

void display(Queue *queue){
  node* temp = queue->front;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main(){
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  queue->front = NULL;
  queue->rear = NULL;

  enequeue(queue, 10);
  enequeue(queue, 20);
  dequeue(queue);
  display(queue);
}
