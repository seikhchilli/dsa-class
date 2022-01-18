#include<bits/stdc++.h>
using namespace std;

//GCD Consecutive Integer checking Algorithm

/*
* Step 1: Assign the value of min(m, n) to t.
* Step 2: Divide m by t. If remainder is 0, go to step 3; Otherwise go to step 4.
* Step 3: Divide n by t. If remainder is 0, return t and stop; Otherwise go to step 4.
* Step 4: Decrease t by 1 and go to step 2.

* Time Complexity: O(n)
*/

int gcd(int m, int n){
  int t = min(m, n);

  while(m % t != 0){
    t--;
  }

  while(m % t != 0 || n % t != 0){
    t--;
  }

  return t;
}

int main(){
  int m, n;
  cout<<"Enter first number: ";
  cin>>m;
  cout<<"Enter second number: ";
  cin>>n;

  cout<<"GCD of "<<m<<" and "<<n<<" : "<<gcd(m, n)<<endl;
  return 0;

}
