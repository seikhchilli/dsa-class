#include<iostream>
using namespace std;

struct Queue{
  int size;
  int rear;
  int front;
  int *arr;
};

Queue* createQueue(int capacity){
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->rear = queue->front = -1;
  queue->size = capacity;
  queue->arr = (int*)malloc(capacity*sizeof(int));
  return queue;
}

void enQueue(Queue* queue, int data){
  if((queue->rear == queue->size - 1 && queue->front == 0) || (queue->rear == queue->front - 1)){
    cout<<"Buffer overflow."<<endl;
    return;
  }
  if(queue->front == -1){
    queue->front = queue->rear = 0;
    queue->arr[queue->rear] = data;
    return;
  }
  if(queue->rear == queue->size - 1 && queue->front != 0){
    queue->rear = 0;
    queue->arr[queue->rear] = data;
    return;
  }
  queue->rear += 1;
  queue->arr[queue->rear] = data;
  return;
}

int deQueue(Queue* queue){
  if(queue->front == -1){
    cout<<"Buffer underflow."<<endl;
    exit(1);
  }
  int value = queue->arr[queue->front];

  if(queue->front == queue->rear){
    queue->front = queue->rear = -1;
    return value;
  }
  if(queue->front == queue->size - 1){
    queue->front = 0;
    return value;
  }
  queue->front += 1;
  return value;

}

void displayQueue(Queue *queue){
  if(queue->front == -1){
    cout<<"Empty Queue."<<endl;
    return;
  }
  if(queue->rear >= queue->front){
    for(int i = queue->front; i <= queue->rear; i++){
      cout<<queue->arr[i]<<" ";
    }
    cout<<endl;
    return;
  }
  for(int i = queue->front; i < queue->size; i++){
    cout<<queue->arr[i]<<" ";
  }
  for(int i = 0; i <= queue->size; i++){
    cout<<queue->arr[i]<<" ";
  }
}

int main(){
  Queue* queue = createQueue(5);

  enQueue(queue, 14);
  enQueue(queue, 22);
  enQueue(queue, 13);
  enQueue(queue, -6);


  displayQueue(queue);

  cout<<"\nDeleted value = "<<deQueue(queue);
  cout<<"\nDeleted value = "<<deQueue(queue);

  displayQueue(queue);

  enQueue(queue, 9);
  enQueue(queue, 20);
  enQueue(queue, 5);

  displayQueue(queue);
  enQueue(queue, 20);
  return 0;
}
