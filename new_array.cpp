#include<iostream>
using namespace std;

int main(){
  int *ptrArr;
  int n;
  cin>>n;
  ptrArr = new int[n];

  for(int i = 0; i < n; i++){
    cin>>*(ptrArr+i);
  }
  cout<<"Array: "<<endl;
  for(int i = 0; i < n; i++){
    cout<<*(ptrArr+i)<<" ";
  }
}
