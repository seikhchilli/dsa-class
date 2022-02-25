#include<iostream>
#include<cmath>
#include<climits>
#include<string>
using namespace std;

void closestCities(string s[], double arr[][2], int n){
  double d = INT_MAX;
  double d2;
  int pair1, pair2;
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      d2 = (arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1]
        - arr[j][1])*(arr[i][1] - arr[j][1]);
      if(d > d2){
        d = d2;
        pair1 = i;
        pair2 = j;
      }
    }

  }
  cout<<"Closest Cities : "<<s[pair1]<<"  "<<s[pair2]<<endl;
}

int main(){
  int n;
  cout<<"Enter number of points: ";
  cin>>n;
  string s[n];
  double arr[n][2];
  cout<<"Enter cities and their longitude and latitude: "<<endl;
  cout<<"Ex: Mumbai 19.07 72.87 "<<endl;
  for(int i = 0; i < n; i++){
    cin>>s[i];
    cin>>arr[i][0];
    cin>>arr[i][1];
  }

  closestCities(s, arr, n);
}
