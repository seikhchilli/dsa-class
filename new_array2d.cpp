#include<iostream>
using namespace std;

int main(){
  int n, m;

  cin>>n;
  cin>>m;
/*
  int **ptr;


  ptr = new int *[n];
  for(int i = 0; i < n; i++){
    ptr[i] = new int[m];
  }

  */

  int *ptr = new int[n*m];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>*(ptr+(i*n+j));
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<*(ptr+(i*n+j))<<" ";
    }
    cout<<endl;
  }

/*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>*(*(ptr+j)+i);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<*(*(ptr+j)+i)<<" ";
    }
    cout<<endl;
  }

  */
}
