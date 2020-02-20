#include<stdio.h>
#include<stdlib.h>

#define N 21
#define M 10

int main(){
    int a[N] = {1,2,3,4,5,10,11,12,20,30,40,50,60,62,64,66,70,80,90,98};
    int count[M]={0};

    for(int i=0; i<N; i++){
        if(a[i] >= 1 && a[i] < 9){
            count[0]++;
        }
        if(a[i] >= 10 && a[i] < 19){
            count[1]++;
        }
        if(a[i] >= 20 && a[i] < 29){
            count[2]++;
        }
        if(a[i] >= 30 && a[i] < 39){
            count[3]++;
        }
        if(a[i] >= 40 && a[i] < 49){
            count[4]++;
        }
        if(a[i] >= 50 && a[i] < 59){
            count[5]++;
        }
        if(a[i] >= 60 && a[i] < 69){
            count[6]++;
        }
        if(a[i] >= 70 && a[i] < 79){
            count[7]++;
        }
        if(a[i] >= 80 && a[i] < 89){
            count[8]++;
        }
        if(a[i] >= 90 && a[i] < 99){
            count[9]++;
        }
    }

    for(int i=0; i<M; i++){
        printf("%2d-%2d ", i*M, (i+1) * M-1);
        for(int j=0; j<count[i]; j++){
            printf("#");
        }
        printf("\n");
    }
}
