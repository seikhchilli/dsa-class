#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;

  int arr[n];

  cout<<"Enter array elements: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  int index;
  cout<<"Enter index position to be deleted:";
  cin>>index;

  int deleted_elem = arr[index];

  cout<<"Array before deleting element: "<<endl<<endl;

  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }

  for(int i = index; i < n-1; i++){
    arr[i] = arr[i+1];
  }
  cout<<endl;
  n = n - 1;
  cout<<"Array after deleting element: "<<endl<<endl;

  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
