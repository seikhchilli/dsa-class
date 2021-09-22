#include<stdio.h>

int main(){
  int arr[10];
  int evensum = 0;
  int oddsum = 0;
  for(int i = 0; i<= 9; i++){
    scanf("%d", &arr[i]);
  }

  for(int i = 0; i <= 9; i++){
    if(arr[i]%2 == 0){
      evensum += arr[i];
    }
    else{
      oddsum += arr[i];
    }
  }

  printf("sum of even numbers: %d\n", evensum);
  printf("sum of odd numbers: %d\n", oddsum);
  return 0;
}
