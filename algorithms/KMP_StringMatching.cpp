#include<iostream>
using namespace std;

void computeLPSArray(string p, int m, int lps[]){
  int len = 0;
  int i = 1;
  lps[0] = 0;
  while(i < m){
    if(p[i] == p[len]){
      lps[i] = len + 1;
      len++;
      i++;
    }
    else{
      if(len != 0){
        len = lps[len-1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
}

int KMPSearch(string s, string p){
  int n = s.size();
  int m = p.size();
  int lps[m] = {0};

  computeLPSArray(p, m, lps);

  int i = 0, j = 0;
  while(i < n){
    if(s[i] == p[j]){
      i++;
      j++;
    }
    else{
      if(j != 0){
        j = lps[j-1];
      }
      else{
        i++;
      }
    }
    if(j == m){
      return (i-j);
    }
  }
  return -1;

}

int main(){
  string s, p;
  cout<<"Enter the string: ";
  cin>>s;
  cout<<"Enter the pattern: ";
  cin>>p;

  cout<<"Shifts required: "<<KMPSearch(s, p)<<endl;
}
