#include<iostream>
using namespace std;

int main(){
  int index, item;
  int n;
  cout<<"Enter length of array: ";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }

  cout<<endl;

  cout<<"Enter index position to be inserted:";
  cin>>index;

  cout<<"Enter value to be inserted:";
  cin>>item;
  cout<<endl;

  cout<<"Array before insertion:"<<endl<<endl;

  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;

  for(int i = n-1; i >= index; i--){
    arr[i+1] = arr[i];
  }

  arr[index] = item;

  n = n+1;
  cout<<"Array after insertion:"<<endl<<endl;
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
