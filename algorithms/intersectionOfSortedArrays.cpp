#include<bits/stdc++.h>
using namespace std;

void intersection(int arr1[], int arr2[], int m, int n){
  int i = 0, j = 0;
  while(i < m && j < n){
    if(arr1[i] == arr2[j]){
      cout<<arr1[i]<<" ";
      i++;
      j++;
    }
    else if(arr1[i] < arr2[j]){
      i++;
    }
    else{
      j++;
    }
  }

}

int main(){
  int arr1[] = {2, 5, 5, 5};
  int arr2[] = {2, 2, 3, 5, 5, 7};

  intersection(arr1, arr2, 4, 6);


}
