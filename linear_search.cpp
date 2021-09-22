#include<iostream>
using namespace std;


int main(){
  int *arr;
  int size;
  cout<<"Enter size of array: ";
  cin>>size;

  arr = new int[size];

  for(int i = 0; i < size; i++){
    cin>>*(arr+i);
  }

  cout<<endl;

  cout<<"Array is: ";
  for(int i = 0; i < size; i++){
    cout<<*(arr+i)<<" ";
  }

  cout<<"\nEnter the number to be searched: ";
  int x;
  cin>>x;

  int check = 0, i = 0;

  while(check == 0 && i < size){
    check = *(arr + i) == x;
    i++;
  }

  if(check == 0){
    cout<<"\nNo such number found.";
  }
  else{
    cout<<"\nNumber found at position "<<i<<endl;
  }
  
  delete arr;

  return 0;
}
