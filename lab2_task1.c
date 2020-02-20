#include<stdio.h>
#include<stdlib.h>

#define MAX_DIM 5

void readDIM(int *r, int *c);
int checkDIM(int R1, int C1, int R2, int C2);
void readMatrix(int mat[][MAX_DIM], int R, int C);
void computeMatrix(int mat1[][MAX_DIM], int row1, int col1, int mat2[][MAX_DIM], int row2, int col2, int mat3[][MAX_DIM], int *rows1, int *cols2);
void writeMatrix(int matrix1[][MAX_DIM], int ROW1, int COL1, int matrix2[][MAX_DIM], int ROW2, int COL2, int matrix3[][MAX_DIM], int ROWS1, int COLS2);

int main(){
  int r1, c1, r2, c2;
  int m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM], m3[MAX_DIM][MAX_DIM];

  readDIM(&r1, &c1);
  m1[r1][c1];
  readDIM(&r2, &c2);
  m2[r2][c2];
  checkDIM(r1, c1, r2, c2);
  m3[r1][c2];
  readMatrix(&m1[r1][c1], r1, c1);
  readMatrix(&m2[r2][c2], r2, c2);

  computeMatrix(&m1[r1][c1], r1, c1, &m2[r2][c2], r2, c2, &m3[r1][c2], r1, c2);
  writeMatrix(&m1[r1][c1], r1, c1, &m2[r2][c2], r2, c2, &m3[r1][c2], r1, c2);
}

void readDIM(int *r, int *c){
  printf("Enter Number of Rows & Columns for matrix: ");
  scanf("%d %d", r, c);

  //return (r, c);
}

int checkDIM(int R1, int C1, int R2, int C2){
  if(R1 < MAX_DIM && C1 < MAX_DIM && R2 < MAX_DIM && C2 < MAX_DIM && R1 == C2 && C1 == R2){
    printf("Dimensions are in order.\n\n");
    return 1;
  }
  else{
    printf("Invalid Dimensions!!!\n");
    return 0;
  }

}

void readMatrix(int mat[][MAX_DIM], int R, int C){
  printf("Enter Matrix values:\n");
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      scanf("%d", &mat[i][j]);
    }
  }
  printf("\n");

}

void computeMatrix(int mat1[][MAX_DIM], int row1, int col1, int mat2[][MAX_DIM], int row2, int col2, int mat3[][MAX_DIM], int *rows1, int *cols2){
  int sum = 0;
  for(int i=0; i<row1; i++){
    for(int j=0; j<col2; j++){
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
