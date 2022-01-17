#include<bits/stdc++.h>
using namespace std;

//GCD function
/*
* Euclid's Algorithm is based on repeated application of equality
  gcd(M, N) = gcd(M, M mod N) until the second number becomes zero,
  that makes the problem trivial

* Time Complexity: O(log n)

*/
int gcd(int m, int n){
  if(n == 0){
    return m;
  }
  return gcd(n, m%n);
}



int main(){
  int m, n;
  cout<<"Enter first number: ";
  cin>>m;
  cout<<"Enter second number: ";
  cin>>n;

  cout<<"GCD of m and n: "<<gcd(m, n)<<endl;
  return 0;
}
