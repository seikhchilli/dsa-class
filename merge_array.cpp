#include<iostream>
using namespace std;

int main(){
    int size1, size2;
    cout<<"Enter size of first array: ";
    cin>>size1;
    int arr1[size1];
    cout<<"Enter array: "<<endl;
    for(int i = 0; i < size1; i++){
      cin>>arr1[i];
    }
    cout<<"Enter size of second array: ";
    cin>>size2;
    int arr2[size2];
    cout<<"Enter array: "<<endl;
    for(int i = 0; i < size2; i++){
      cin>>arr2[i];
    }
    int i = 0;
    int j = 0, k = 0;
    int size3 = size1 + size2;
    int arr3[size3];
    while(i < size1 || j < size2){
      if(arr1[i] <= arr2[j]){
        arr3[k] = arr1[i];
        i++;
      }
      else{
        arr3[k] = arr2[j];
        j++;
      }
      k++;
    }
    cout<<"----------------------First array------------------"<<endl<<endl<<"\t\t\t";
    for(int i = 0; i < size1; i++){
      cout<<arr1[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"---------------------Second Array------------------"<<endl<<endl<<"\t\t\t";
    for(int i = 0; i < size2; i++){
      cout<<arr2[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"---------------------Merged Array-------------------"<<endl<<endl<<"\t\t\t";
    for(int i = 0; i < size1+size2; i++){
      cout<<arr3[i]<<" ";
    }
    cout<<endl<<endl;

    return 0;
}
