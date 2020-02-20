#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define R 3
#define C 5

int factorial(int n);

int main(){
    int m1[R][C] = {{9, 23, 155, -1, 33},{0, -2, -4, 8, -6},{20, -1, 0, 0, 499}}, m2[R][C] = {0};
    int count, base = 10;

    printf("matrix m1[i][j]:\n\n");
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");


    // program logic
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(m1[i][j] < 0){
                m1[i][j] *= -1;
                m2[i][j] = factorial(m1[i][j]);
                m1[i][j] *= -1;
            }
            if(m1[i][j] > 0){
                count = log10(m1[i][j]) + 1;
                m2[i][j] = pow(base,count) + 0.5;
            }
        }
    }

    printf("matrix m2[i][j]:\n\n");
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return(n*factorial(n-1));
    }
}
