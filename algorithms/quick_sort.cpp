#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = low-1;


  for(int j = low; j <= high-1; j++){
    if(arr[j] < pivot){
      i++;

      //swap
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[high];
  arr[high] = arr[i+1];
  arr[i+1] = temp;

  return (i+1);
}

void quickSort(int arr[], int low, int high){
  if(low < high){
    int s = partition(arr, low, high);

    quickSort(arr, low, s-1);
    quickSort(arr, s+1, high);
  }
}

int main(){
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n-1);

  cout<<"Sorted array : ";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
}
