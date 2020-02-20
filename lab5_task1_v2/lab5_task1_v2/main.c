//
//  main.c
//  lab5_task1_v2
//
//  Created by Hamza Rehman on 10/21/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memory_allocation(char ***, int );
void sort_string(char ***, int );
void free_memory(char ***, int );

int main(int argc, const char * argv[]) {
    FILE *file;
    file = fopen("data.txt","r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    int n;
    while(fscanf(file, "%d", &n)){
        printf("1st line read successfully.\n\n");
    }
    
    char **mat;
    memory_allocation(&mat, n);
    
    // reading data from file
    for(int i=0; i<n; i++){
        fscanf(file, "%s", mat[i]);
    }
    
    sort_string(&mat, n);
    printf("Sorted file:\n");
    for(int i=0; i<n; i++){
        printf("%s\n", mat[i]);
    }
    
    free_memory(&mat, n);
    
    return 0;
}

void memory_allocation(char ***mat, int n){
    char **m;
    m = (char **) malloc (n * sizeof(char *));
    for(int i=0; i<n; i++){
        m[i] = (char *) malloc (n * sizeof(char));
        if(m[i] == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
    }
    
    *mat = m;
    
    return;
}

void sort_string(char ***mat, int n){
    char *temp;
    temp = (char *) malloc (n * sizeof(char));
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(strcmp((*mat)[i], (*mat)[j]) > 0){
                temp = strdup((*mat)[i]);
                (*mat)[i] = strdup((*mat)[j]);
                (*mat)[j] = strdup(temp);
                
            }
        }
    }
    
    free(temp);
    return;
}

void free_memory(char ***mat, int n){
    for(int i=0; i<n; i++){
        free((*mat)[i]);
    }
    free((*mat));
    
    return;
}
