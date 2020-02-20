//
//  main.c
//  sorting_algorithms
//
//  Created by Hamza Rehman on 10/18/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int A[], int n);
void selection_sort(int A[], int n);
void bubble_sort(int A[], int n);
void shell_sort(int A[], int n);
void counting_sort(int A[], int n, int k);

int main(){
    time_t t;
    srand((unsigned) time(&t));

    int n = 6, k = n;
    int A[6] = {4,5,2,3,1,0};
    //printf("\n");
    //insertion_sort(A,n);
    //selection_sort(A, n);
    //bubble_sort(A, n);
    //shell_sort(A, n);
    counting_sort(A, n, k);
    
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    //free(A);
}

void insertion_sort(int A[], int n){
    int value, hole;
    for(int i=1; i<n; i++){
        value = A[i];
        hole = i;
        while(hole > 0 && A[hole-1] > value){
            A[hole] = A[hole-1];
            hole--;
        }
        A[hole] = value;
    }
    return;
}

void selection_sort(int A[], int n){
    int min, temp;
    
    for(int i=0; i<n-1; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    return;
}

void bubble_sort(int A[], int n){
    int temp;
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[i] > A[j]){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    return;
}

void shell_sort(int A[], int n){
    int value, hole, h=1;
    while(h < n/3){
        h = 3*h + 1;
    }
    while(h >= 1){
        for(int i=h; i<n; i++){
            value = A[i];
            hole = i-h;
            while(hole >= 0 && value < A[hole]){
                A[hole+h] = A[hole];
                hole -= h;
            }
            A[hole+h] = value;
        }
        h = h/3;
    }
    return;
}

void counting_sort(int A[], int n, int k){
    int *B, *C;
    B = (int *) malloc (n * sizeof(int));
    C = (int *) malloc (k * sizeof(int));
    if(B == NULL || C == NULL){
        perror("Error in memory allocation.");
        return;
    }
    
    for(int i=0; i<k; i++){
        C[i] = 0;
    }
    for(int i=0; i<n; i++){
        C[A[i]]++;
    }
    for(int i=1; i<=k; i++){
        C[i] += C[i-1];
    }
    for(int i=n-1; i>=0; i--){
        B[C[A[i] - 1]] = A[i];
    }
    for(int i=0; i<n; i++){
        A[i] = B[i];
    }
    
    free(B);
    free(C);
    return;
}

