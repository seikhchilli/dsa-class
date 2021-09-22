#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int first, int last, int search){
  if(last >= first){
    int mid = first + (last - first)/2;
    if((arr[mid] == search || mid == 0) && (arr[mid] == search || mid == n-1)){
      return mid;
    }
    else if(arr[mid] > search){
      binarySearch(arr, n, first, mid-1, search);
    }
    else{
      binarySearch(arr, n, mid+1, last, search);
    }
  }
  else{
    return -1;
  }
}

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;
  cout<<"\nEnter elements of array: "<<endl;

  int *arr = new int[n];

  for(int i = 0; i < n; i++){
    cin>>*(arr+i);
  }

  cout<<"Your array is: ";
  for(int i = 0; i < n; i++){
    cout<<*(arr+i)<<" ";
  }
  cout<<endl;

  int search;
  cout<<"\nEnter the number to be searched: ";
  cin>>search;

  int searchVal = binarySearch(arr, n, 0, n-1, search);

  if(searchVal == -1){
    cout<<"\nNumber not found."<<endl;
  }
  else{
    cout<<"\nNumber found at index position "<<searchVal<<endl;
  }
  delete arr;
  return 0;

}
