//
//  main.c
//  lab5_task1
//
//  Created by Hamza Rehman on 10/20/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    char *str;
} STRING;

STRING *file_read(int *n);
void sort_string(STRING *list, int n);

int main(int argc, const char * argv[]) {
    int n;
    
    STRING *list = file_read(&n);
    sort_string(list, n);
    
    printf("Sorted file:\n");
    for(int i=0; i<n; i++){
        printf("%s", list[i].str);
    }
    printf("\n");
    
    // freeing dynamically allocated memory
    for(int i=0; i<n; i++){
        free(list[i].str);
    }
    free(list);
    
    return 0;
}

STRING *file_read(int *n){
    FILE *file;
    file = fopen("data.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    while(fscanf(file, "%d", n)){
        printf("1st line read successfullly.\n\n");
    }
    
    STRING *list;
    list = (STRING *) malloc (*n * sizeof(STRING));
    if(list == NULL){
        perror("Error in memory allocation.");
        exit(EXIT_FAILURE);
    }
    
    char word[MAX];
    /*word = malloc (*n * sizeof(char));
    if(word == NULL){
        perror("Error in memory allocation.");
        exit(EXIT_FAILURE);
    }*/
    
    for(int i=0; i<*n; i++){
        fgets(word, sizeof(word), file);
        list[i].str = strdup(word);
    }
    
    //free(word);
    fclose(file);
    
    return list;
}

void sort_string(STRING *list, int n){
    char *temp;
    temp = (char *) malloc (n * sizeof(char));
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(strcmp(list[i].str, list[j].str) > 0){
                temp = strdup(list[i].str);
                list[i].str = strdup(list[j].str);
                list[j].str = strdup(temp);            }
        }
    }
    
    free(temp);
    return;
}
