#include<iostream>
using namespace std;

void insert(int[], int, int);

void insert(int arr[], int x, int count){
  int ptr, par;
  ptr = count;
  while(ptr > 0){
    par = (ptr - 1)/2;
    if(arr[par] >= x){
      arr[ptr] = x;
      return;
    }
    arr[ptr] = arr[par];
    ptr = par;
  }
  arr[0] = x;
}

void heapify(int arr[], int n, int i){
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < n && arr[l] > arr[largest]){
    largest = l;
  }

  if(r < n && arr[r] > arr[largest]){
    largest = r;
  }

  if(largest != i){
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}

void deleteRoot(int arr[], int& n){
  int lastElement = arr[n-1];
  arr[0] = lastElement;
  n--;
  heapify(arr, n, 0);
}


int main(){
  int n = 5;
  int arr[n];
  insert(arr, 10, 0);
  insert(arr, 5, 1);
  insert(arr, 8, 2);
  insert(arr, 12, 3);
  insert(arr, 21, 4);

  cout<<"heap: ";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }

  deleteRoot(arr, n);
  cout<<"\n\nDeleted root: ";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
}
