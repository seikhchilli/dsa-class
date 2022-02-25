#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int closestPair(int arr[][2], int n){
  int d = INT_MAX;
  int d2;
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      d2 = (arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1]
        - arr[j][1])*(arr[i][1] - arr[j][1]);
      if(d > d2){
        d = d2;
      }
    }

  }
  return sqrt(d);
}

int main(){
  int n;
  cout<<"Enter number of points: ";
  cin>>n;
  int arr[n][2];
  cout<<"Enter points: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i][0];
    cin>>arr[i][1];
  }

  cout<<"Distance between close pair "<<closestPair(arr, n);
}
