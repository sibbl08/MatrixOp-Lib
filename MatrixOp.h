#ifndef MATRIXOP_H
#define MATRIXOP_H
#define SIZE 3

// Basic Operations
void mat_ADD(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_SUB(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_MUL_EW(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);   // element-wise mulitplication


// Linear
void mat_MUL(double A[SIZE][SIZE], double B[SIZE][SIZE],double C[SIZE][SIZE]);
void mat_TRANS(double A[SIZE][SIZE]);


// Advancded
double det2x2(double m[2][2]);
double mat_DET(double A[SIZE][SIZE]);
void mat_ADJ(double A[SIZE][SIZE], double SOL[SIZE][SIZE]);

// Inverse
void mat_INV(double A[SIZE][SIZE], double B[SIZE][SIZE]);

#endif