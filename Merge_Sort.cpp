#include<iostream>
#include<limits>
using namespace std;


void merge_array(int arr[], int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;

  int left[n1];
  int right[n2];

  for(int i = 0; i < n1; i++){
    left[i] = arr[p + i];
  }
  for(int j = 0; j < n2; j++){
    right[j] = arr[q + j + 1];
  }
  left[n1] = numeric_limits<int>::max();
  right[n2] = numeric_limits<int>::max();

  int i = 0;
  int j = 0;
  for(int k = p; k <= r; k++){
    if(left[i] <= right[j]){
      arr[k] = left[i];
      i++;
    }
    else{
      arr[k] = right[j];
      j++;
    }
  }
}


void merge_sort(int arr[], int l, int r){
  if(l < r){
    int m = (l + r)/2;
    merge_sort(arr, l , m);
    merge_sort(arr, m+1, r);
    merge_array(arr, l, m, r);
  }


}


int main(){
  int n;
  cout<<"Enter Size of array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements of array: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }

  cout<<"\n\nUnsorted Array:  ";
  for(auto i : arr){
    cout<<i<<" ";
  }

  merge_sort(arr, 0, n);

  cout<<"\n\nSorted array:  ";
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;


}
