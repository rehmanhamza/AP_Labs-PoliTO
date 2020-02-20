//
//  main.c
//  lab2_task1
//
//  Created by Hamza Rehman on 9/20/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <time.h>

#define MAX_DIM 5

void readDIM(int *r, int *c);
int checkDIM(int r1, int c1, int r2, int c2);
void readMatrix(int mat[][MAX_DIM], int R, int C);
void computeProduct(int mat1[][MAX_DIM], int row1, int col1, int mat2[][MAX_DIM], int row2, int col2, int mat3[][MAX_DIM], int *rows1, int *cols2);
void writeMatrix(int matrix1[][MAX_DIM], int ROW1, int COL1, int matrix2[][MAX_DIM], int ROW2, int COL2, int matrix3[][MAX_DIM], int ROWS1, int COLS2);

int main(int argc, const char * argv[]) {
    
    clock_t begin = clock();
    
    int r1, c1, r2, c2, verify_dim;
    int m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM], m3[MAX_DIM][MAX_DIM];
    
start:
    readDIM(&r1, &c1);
    readDIM(&r2, &c2);
    
    verify_dim = checkDIM(r1, c1, r2, c2);
    
    if(verify_dim == 0){
        printf("Invalid Dimensions!!!\n");
        goto start;
    }
    
    m1[r1][c1];
    m2[r2][c2];
    m3[r1][c2];
    readMatrix(&m1[r1][c1], r1, c1);
    readMatrix(&m2[r2][c2], r2, c2);
    
    computeProduct(&m1[r1][c1], r1, c1, &m2[r2][c2], r2, c2, &m3[r1][c2], r1, c2);
    writeMatrix(&m1[r1][c1], r1, c1, &m2[r2][c2], r2, c2, &m3[r1][c2], r1, c2);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("time_spent = %f\n", time_spent);
    return 0;
}

void readDIM(int *r, int *c){
    printf("Enter No. of Rows & Cols for matrix:");
    scanf("%d %d", r, c);
}

int checkDIM(int r1, int c1, int r2, int c2){
    if(r1 < MAX_DIM && c1 < MAX_DIM && r2 < MAX_DIM && c2 < MAX_DIM && r1 == c2 && c1 == r2){
        return 1;
    }
    else{
        return 0;
    }
}

void readMatrix(int mat[][MAX_DIM], int R, int C){
    printf("Enter matrix elements:\n");
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
}

void computeProduct(int mat1[][MAX_DIM], int row1, int col1, int mat2[][MAX_DIM], int row2, int col2, int mat3[][MAX_DIM], int *rows1, int *cols2){
    int sum = 0;
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            sum = 0;
            for(int k=0; k<row2; k++){
                sum = sum + mat1[i][k] * mat2[k][j];
            }
            mat3[i][j] = sum;
        }
    }
}

void writeMatrix(int matrix1[][MAX_DIM], int ROW1, int COL1, int matrix2[][MAX_DIM], int ROW2, int COL2, int matrix3[][MAX_DIM], int ROWS1, int COLS2){
    printf("m1:\n");
    for(int i=0; i<ROW1; i++){
        for(int j=0; j<COL1; j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\nm2:\n");
    for(int i=0; i<ROW2; i++){
        for(int j=0; j<COL2; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\nm3:\n");
    for(int i=0; i<ROWS1; i++){
        for(int j=0; j<COLS2; j++){
            printf("%0.2f ", (float) matrix3[i][j]);
        }
        printf("\n");
    }
}
