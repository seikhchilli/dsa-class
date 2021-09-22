#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements of array: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  cout<<endl<<"----------------------Your array------------------"<<endl<<endl<<"\t\t\t";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;
  int min, key;
  for(int i = 0; i < n; i++){
    min = arr[i];
    key = i;
    for(int j = i; j < n; j++){
      if(arr[j] < min){
        min = arr[j];
        key = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[key];
    arr[key] = temp;
  }
  cout<<"----------------------Sorted array------------------"<<endl<<endl<<"\t\t\t";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;
}
