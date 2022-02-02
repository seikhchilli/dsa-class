#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int search){
  int low = 0, high = v.size() - 1, mid;

  while(high >= low){
    mid = low + (high - low)/2;
    if(search == v[mid]){
      return mid;
    }
    else if(v[mid] > search){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return -1;
}

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;
  cout<<"\nEnter elements of array: "<<endl;

  vector<int> v;
  int x;
  for(int i = 0; i < n; i++){
    cin>>x;
    v.push_back(x);
  }


  int search;
  cout<<"\nEnter the number to be searched: ";
  cin>>search;

  int searchVal = binarySearch(v, search);

  if(searchVal == -1){
    cout<<"\nNumber not found."<<endl;
  }
  else{
    cout<<"\nNumber found at index position "<<searchVal<<endl;
  }
  return 0;

}
