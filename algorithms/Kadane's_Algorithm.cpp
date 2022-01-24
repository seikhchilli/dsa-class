#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int len){
  int sum = 0;
  int max_sum = INT_MIN;
  for(int i = 0; i < len; i++){
    sum += arr[i];
    if(sum > max_sum){
      max_sum = sum;
    }
    if(sum < 0){
      sum = 0;
    }

  }
  return max_sum;
}

int main(){
  int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
  int max_sum = maxSubarraySum(arr, 9);
  cout<<"Maximum Contiguous sum: "<<max_sum<<endl;
  return 0;

}
