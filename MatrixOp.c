#include "MatrixOp.h"
#include<stdlib.h>

#define SIZE 3

void mat_trans(double A[3][3], int size){
    
int A_copy[size][size];
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            A_copy[i][j]=A[i][j];
        }
        
    }
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            A[i][j]=A_copy[j][i];
        }
        
    }


}


void mat_mul(double A[3][3], double B[3][3],double C[3][3], int size){

  

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


double mat_det(double A[3][3], int size)
{
    double det = 0.0;

    // Positive Diagonalen
    for (int start_col = 0; start_col < size; start_col++) {
        double mult = 1.0;

        for (int i = 0; i < size; i++) {
            int col = (start_col + i) % size;
            mult *= A[i][col];
        }

        det += mult;
    }

    // Negative Diagonalen
    for (int start_col = 0; start_col < size; start_col++) {
        double mult = 1.0;

        for (int i = 0; i < size; i++) {
            int col = (start_col - i + size) % size;
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

void mat_adj(double A[3][3], double SOL[3][3], int size)
{
    double minor[2][2];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            // Build minor matrix (skip row i and col j)
            int r = 0;
            for (int row = 0; row < size; row++) {
                if (row == i) continue;

                int c = 0;
                for (int col = 0; col < size; col++) {
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
    mat_trans(SOL,3);
}