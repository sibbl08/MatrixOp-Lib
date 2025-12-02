#include<stdlib.h>
#include "MatrixOp.h"

void mADD(int A[3][3], int B[3][3], int C[3][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mSUB(int A[3][3], int B[3][3], int C[3][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mMUL_EW(int A[3][3], int B[3][3], int C[3][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}