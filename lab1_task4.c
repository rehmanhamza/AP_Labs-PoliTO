#include<stdio.h>

#define MAX_DIM 5

int main(){
    int m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM], m3[MAX_DIM][MAX_DIM], r1, c1, r2, c2;
    printf("Enter r1 & c1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter r2 & c2: ");
    scanf("%d %d", &r2, &c2);

    if(r1 < MAX_DIM && c1 < MAX_DIM && r2 < MAX_DIM && c2 < MAX_DIM && r1 == c2 && c1 == r2){
        m1[r1][c1];
        m2[r2][c2];
        m3[r1][c2];

        printf("Enter elements of m1\n");
        for(int i=0; i<r1; i++){
            for(int j=0; j<c1; j++){
                scanf("%d", &m1[i][j]);
            }
        }

        printf("Enter elements of m2\n");
        for(int i=0; i<r2; i++){
            for(int j=0; j<c2; j++){
                scanf("%d", &m2[i][j]);
            }
        }

        printf("\n\nm1:\n");
        for(int i=0; i<r1; i++){
            for(int j=0; j<c1; j++){
                printf("%0.2f ", (float) m1[i][j]);
            }
            printf("\n");
        }

        printf("\n\nm2:\n");
        for(int i=0; i<r2; i++){
            for(int j=0; j<c2; j++){
                printf("%0.2f ", (float) m2[i][j]);
            }
            printf("\n");
        }

        int sum = 0;
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                sum = 0;
                for(int k=0; k<r2; k++){
                    sum = sum + m1[i][k] * m2[k][j];
                }
                m3[i][j] = sum;
            }
        }

        printf("\n\nm3:\n");
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                printf("%0.2f ", (float) m3[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Matrices size aren't compatible for multiplication\n");
    }
}
