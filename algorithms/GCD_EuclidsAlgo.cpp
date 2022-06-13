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

int gcd_without_recursion(int m, int n){
  int rem;
  while(n > 0){
    rem = m % n;
    m = n;
    n = rem;
  }
  return m;
}

//LCM of (m, n) = (m * n) / HCF(m, n);



int main(){
  int m, n;
  cout<<"Enter first number: ";
  cin>>m;
  cout<<"Enter second number: ";
  cin>>n;

  cout<<"GCD of "<<m<<" and "<<n<<" : "<<gcd_without_recursion(m, n)<<endl;
  return 0;
}
