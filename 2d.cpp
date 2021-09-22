#include<iostream>
using namespace std;

int main(){
  int n = 2, m = 3, arr1[n][m], arr2[n][m],  sum[n][m];
  cout<<"Enter first array:"<<endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>arr1[i][j];
    }
  }

  cout<<endl<<"Enter first array:"<<endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>arr2[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      sum[i][j] = arr1[i][j] + arr2[i][j];
    }
  }

  cout<<"Sum: "<<sum<<endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<sum[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;

}
