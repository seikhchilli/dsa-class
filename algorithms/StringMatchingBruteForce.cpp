#include<iostream>
#include<string>
using namespace std;

int stringMatch(string s, string m){
  for(int i = 0; i < s.length()- m.length(); i++){
    int j = 0;
    while(j < m.length() && m[j] == s[i + j]){
      j++;
    }
    if(j == m.length()){
      return i;
    }
  }
  return -1;
}

int main(){
  string s, m;
  cout<<"Enter string: ";
  getline(cin, s);
  cout<<"Enter string to be matched: ";
  cin>>m;

  cout<<"\nShifts : "<<stringMatch(s, m);

}
