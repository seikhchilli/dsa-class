#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int arr[], int n){
  int count = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-1-i; j++){
      if(arr[j] > arr[j+1]){
        count++;
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
  return count;
}

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter array: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  cout<<"----------------------Your array------------------"<<endl<<endl<<"\t\t\t";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;
  int count = bubbleSort(arr, n);
  cout<<"----------------------Sorted array------------------"<<endl<<endl<<"\t\t\t";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;
  cout<<"Number of Swappings: "<<count<<endl<<endl;


}
