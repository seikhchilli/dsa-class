#include<bits/stdc++.h>
using namespace std;

int sqrtBS(int n){
  if(n == 0 || n == 1){
    return n;
  }
  int ans, low = 1, mid, high = n/2, sqr;

  while(low <= high){
    mid = (low + high)/2;

    sqr = mid * mid;
    if(sqr == n){
      return mid;
    }

    if(sqr < n){
      ans = mid;
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return ans;
}

int main(){
  int n;
  cout<<"Enter the number: ";
  cin>>n;
  int ans = sqrtBS(n);
  cout<<"Floor Square root: "<<ans<<endl;
}
