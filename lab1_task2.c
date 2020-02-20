#include<stdio.h>
#include<stdlib.h>

#define N1 10
#define N2 2
int main(){
    int a[N1] = {0, 2, 3, 4, -1, -10, 5, 1, 8, 3};
    int n = 0, sum = 0;
    float b[N1] = {0};

    for(int i=0; i<N1; i++){
        n = 0;
        sum = 0;
        for(int j=i-N2; j<N1; j++){
            if(j >= 0 && j<=i+N2){
                sum = sum + a[j];
                n++;
            }
        }
        b[i] = (float) sum/n;
    }

    for(int i=0; i<N1; i++){
        printf("%0.2f ", b[i]);
    }
}
