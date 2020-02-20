//
//  main.c
//  lab8_task1
//
//  Created by Hamza Rehman on 12/15/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int square_matrix(int **matrix, int dim, int *used, int k);
int check(int **matrix, int dim);

int main(int argc, const char * argv[]) {
    int **matrix, *used, n = 4;
    
    used = (int *) malloc ((n*n+1) * sizeof(int));
    matrix = (int **) malloc (n * sizeof(int *));
    if(used == NULL || matrix == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }
    for(int i=0; i<n; i++){
        matrix[i] = (int *) malloc (n * sizeof(int));
        if(matrix[i] == NULL){
            perror("Error in memory allocation");
            return EXIT_FAILURE;
        }
    }
    
    for(int i=0; i<=n*n; i++){
        used[i] = 0;
    }
    
    if(square_matrix(matrix, n, used, 0)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%2d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("No Magic Matrix found for %d.\n", n);
    }
    
    // freeing memory
    free(used);
    for(int i=0; i<n; i++){
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}

int square_matrix(int **matrix, int dim, int *used, int k){
    int i, j, val;
    
    if(k == dim*dim){
        return (check(matrix, dim));
    }
    
    i = k / dim;
    j = k % dim;
    
    for(val=1; val<=dim*dim; val++){
        if(used[val] == 0){
            matrix[i][j] = val;
            used[val] = 1;
            
            if(square_matrix(matrix, dim, used, k+1)){
                return 1;
            }
            used[val] = 0;
        }
    }
    
    return 0;
}

int check(int **matrix, int dim){
    int sum, target;
    target = dim * (dim*dim+1)/2;
    
    // checking rows
    for(int i=0; i<dim; i++){
        sum = 0;
        for(int j=0; j<dim; j++){
            sum += matrix[i][j];
        }
        if(sum != target){
            return 0;
        }
    }
    
    // checking columns
    for(int j=0; j<dim; j++){
        sum = 0;
        for(int i=0; i<dim; i++){
            sum += matrix[i][j];
        }
        if(sum != target){
            return 0;
        }
    }
    
    // checking diagonals
    sum = 0;
    for(int i=0; i<dim; i++){
        sum += matrix[i][i];
    }
    if(sum != target){
        return 0;
    }
    
    sum = 0;
    for(int i=0; i<dim; i++){
        sum += matrix[i][dim-1-i];
    }
    if(sum != target){
        return 0;
    }
    
    return 1;
}
