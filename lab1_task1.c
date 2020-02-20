#include<stdio.h>
#include<stdlib.h>
#include "ap.h"

#define DIM 15

//void bubble_sort(int arr[], int n);

int main(){
    int a[DIM] = {2, 3, 4, -1, -10, 5, 6, 8, 11, -9, 8, -10, 9, 3, 0};
    int j, found, count, pos, len = 0;

    for(int i=0; i<DIM; i++){
        j=i;
        count = 0;
        found = 1;

        while(found && j<DIM){
            if(a[j] < a[j+1]){
                count++;
            }
            else{
                found = 0;
            }
            j++;
        }
        if(count > len){
            len = count;
            pos = i;
        }
    }
    while(count <= len){
        printf("%d ", a[pos]);
        pos++;
        count++;
    }
}

/*void bubble_sort(int arr[], int n){
    if(n == 1){
        return;
    }

    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            SWAP(int, arr[i], arr[i+1]);
        }
    }

    bubble_sort(arr, n-1);
}*/
