#ifndef MATRIXOP_H
#define MATRIXOP_H

// Basic


// Linear
void mat_mul(double A[3][3], double B[3][3],double C[3][3], int size);
void mat_trans(double A[3][3], int size);
// Advancded
double det2x2(double m[2][2]);
double mat_det_3x3(double A[3][3],int size);
void mat_adj(double A[3][3], double SOL[3][3], int size);

// Inverse

#endif