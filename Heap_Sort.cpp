#include<iostream>
using namespace std;



heapify(int arr[], int n, int i){
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if(left < n && arr[left] > arr[largest]){
    largest = left;
  }

  if(right < n && arr[right] > arr[largest]){
    largest = right;
  }

  if(largest != i){
    swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }
}

heapSort(int arr[], int n){
  for (int i = n / 2 - 1; i >= 0; i--){
    heapify(arr, n, i);
  }
  for(int i = n - 1; i > 0; i--){
    swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

int main(){
  cout<<"Enter size of array: ";
  int n;
  cin>>n;
  int arr[n];
  cout<<"Enter elements of array: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }

  cout<<"\n\nArray entered: ";
  for(auto i : arr){
    cout<<i<<" ";
  }

  heapSort(arr, n);

  cout<<"\n\nSorted array: ";
  for(auto i: arr){
    cout<<i<<" ";
  }
}
