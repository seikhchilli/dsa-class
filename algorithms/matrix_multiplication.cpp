#include<iostream>
using namespace std;

int main(){
    int r1 = 4, c1 = 4, r2 = 4, c2 = 4;
    int mat1[r1][c1] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };
 
    int mat2[r2][c2] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };

    int mat3[4][4];

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            mat3[i][j] = 0;
            for(int k = 0; k < r1; k++){
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout<<"Product of Matrix 1 and Matrix 2 : "<<endl;

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            cout<<mat3[i][j]<<" ";
        }
        cout<<endl;
    }
}