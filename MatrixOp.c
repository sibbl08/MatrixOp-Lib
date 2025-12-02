#include<stdio.h>
#include "MatrixOp.h"

// Basic Operations
void mat_ADD(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mat_SUB(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mat_MUL_EW(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

// Linear
void mat_TRANS(double A[SIZE][SIZE]){
    
    int A_copy[SIZE][SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            A_copy[i][j]=A[i][j];
        }
        
    }
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            A[i][j]=A_copy[j][i];
        }
        
    }
}


void mat_MUL(double A[SIZE][SIZE], double B[SIZE][SIZE],double C[SIZE][SIZE]){

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++){
            C[i][j]=0.0;
        }
    }
    

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            for (size_t k= 0; k < SIZE; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            
        }
        
    }
}

// Advanced
double mat_DET(double A[SIZE][SIZE])
{
    double det = 0.0;

    // Positive Diagonalen
    for (int start_col = 0; start_col < SIZE; start_col++) {
        double mult = 1.0;

        for (int i = 0; i < SIZE; i++) {
            int col = (start_col + i) % SIZE;
            mult *= A[i][col];
        }

        det += mult;
    }

    // Negative Diagonalen
    for (int start_col = 0; start_col < SIZE; start_col++) {
        double mult = 1.0;

        for (int i = 0; i < SIZE; i++) {
            int col = (start_col - i + SIZE) % SIZE;
            mult *= A[i][col];
        }

        det -= mult;
    }

    return det;
}

double det2x2(double m[2][2])
{
    return m[0][0]*m[1][1] - m[0][1]*m[1][0];
}

void mat_ADJ(double A[SIZE][SIZE], double SOL[SIZE][SIZE])
{
    double minor[2][2];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            // Build minor matrix (skip row i and col j)
            int r = 0;
            for (int row = 0; row < SIZE; row++) {
                if (row == i) continue;

                int c = 0;
                for (int col = 0; col < SIZE; col++) {
                    if (col == j) continue;

                    minor[r][c] = A[row][col];
                    c++;
                }
                r++;
            }

            // Cofactor
            double cof = det2x2(minor);

            if ((i + j) % 2 != 0) //nur jeder zweite (Angefangen beim ersten)
                cof = -cof;

            
            SOL[i][j] = cof;
        }
    }
    mat_TRANS(SOL);
}

// Inverse
void mat_INV(double A[SIZE][SIZE], double B[SIZE][SIZE]){
    double det=mat_DET(A);
    if(det==0){
        printf("Matrix is not invertible, because determinant is 0 \n");
        return;
    }
    double adj[SIZE][SIZE];

    mat_ADJ(A, adj);

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            B[i][j] = adj[i][j] / det;
        }
    }
}