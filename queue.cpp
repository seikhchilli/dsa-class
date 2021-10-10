#include<iostream>
using namespace std;

struct Queue{
  int capacity, rear, front;
  int *arr;
};

Queue* createQueue(int Capacit){
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->capacity = Capacit;
  queue->arr = (int*)malloc(queue->capacity*sizeof(int));
  queue->rear = -1;
  queue->front = 0;
  return queue;
}

void enqueue(Queue *queue, int data){
  if(queue->rear == queue->capacity - 1){
    cout<<"Buffer overflow."<<endl;
    return;
  }
  queue->rear = queue->rear + 1;
  queue->arr[queue->rear] = data;
  cout<<"enequeued"<<endl;
}

int dequeue(Queue *queue){
  if(queue->front > queue->rear){
    cout<<"Buffer underflow."<<endl;
    exit(1);
  }
  int value = queue->arr[queue->front];
  queue->front = queue->front + 1;
  return value;
}

void display(Queue *queue){
  if(queue->front > queue->rear){
    cout<<"Queue Empty"<<endl;
    return;
  }
  for(int i = queue->front; i <= queue->rear; i++){
    cout<<queue->arr[i]<<" ";
  }
  cout<<endl;
}

int main(){

  Queue *queue = createQueue(5);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);
  enqueue(queue, 60);
  cout<<"Queue: ";

  display(queue);
  dequeue(queue);
  dequeue(queue);
  cout<<"Queue: ";
  display(queue);
}
