//
//  main.c
//  lab5_task2
//
//  Created by Hamza Rehman on 10/23/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

int main(int argc, const char * argv[]) {
    FILE *file;
    file = fopen("data.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    int r, c;
    fscanf(file, "%d %d", &r, &c);
    
    char ***mat;
    mat = (char ***) malloc (r * sizeof(char **));
    if(mat == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }
    for(int i=0; i<r; i++){
        mat[i] = (char **) malloc (c * sizeof(char *));
        if(mat[i] == NULL){
            perror("Error in memory allocation");
            return EXIT_FAILURE;
        }
    }
    
    char word[MAX];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            fscanf(file, "%s", word);
            mat[i][j] = strdup(word);
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%s ", mat[i][j]);
        }
        printf("\n");
    }
    
    int i=0, min_idx, *idx, count;
    char **array, *min_word;
    
    array = (char **) malloc (r*c * sizeof(char *));
    idx = (int *) malloc (r * sizeof(int));
    if(array == NULL || idx == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }
    
    for(int i=0; i<r; i++){
        idx[i] = 0;
    }
    
    while(i < r*c){
        min_idx = -1;
        for(int j=0; j<c; j++){
            if(idx[j] < c){
                if((min_idx == -1) || (strcmp(mat[j][idx[j]], min_word) < 0)){
                    min_idx = j;
                    min_word = mat[min_idx][idx[min_idx]];
                }
            }
        }
        count = min_idx;
        array[i++] = mat[min_idx][idx[count]];
        //i++;
        idx[count]++;
        
    }
    
    for(int i=0; i<r*c; i++){
        printf("%s\n", array[i]);
    }
    // freeing dynamically allocated memory
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
    
    return 0;
}
