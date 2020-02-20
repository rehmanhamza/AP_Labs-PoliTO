//
//  main.c
//  lab3_task1
//
//  Created by Hamza Rehman on 10/8/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIM 100
#define MAX 20

typedef struct {
    char words[MAX+1];
    int occurrence;
}TEXT_SEARCH;

char *strlwr(char *str);

int main(int argc, const char * argv[]) {
    FILE *file1, *file2;
    file1 = fopen("words.txt", "r");
    file2 = fopen("text.txt", "r");
    
    if(file1 == NULL || file2 == NULL){
        perror("Error opening file:");
        return EXIT_FAILURE;
    }
    
    int n;
    while(fscanf(file1, "%d", &n)){
        printf("1st line read successfully.\n\n");
    }

    TEXT_SEARCH temp, *list;
    
    strcpy(temp.words, "NA");
    temp.occurrence = -1;
    
    list = (TEXT_SEARCH *) malloc (sizeof(n));
    if(list == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }
    
    for(int i=0; i<n; i++){
        list[i].occurrence = 0;
    }
    
    int i = 0;
    while(!feof(file1)){
        fscanf(file1, "%s", list[i].words);
        
        i++;
    }
    
    
    char line[DIM+1], *start, *end;
    while(fgets(line, sizeof(line), file2) != NULL){
        strlwr(line);

        for(int i=0; i<n; i++){
            start = line;
            do{
                end = strstr(start, list[i].words);
                
                if(end != NULL){
                    if(end[strlen(list[i].words)] == ' '){
                        list[i].occurrence++;
                    }
                    start = end + strlen(list[i].words);
                }
            }while(end != NULL);
        }
    }
    
    for(int i=0; i<n; i++){
     printf("%s - %d occurrence(s)\n", list[i].words, list[i].occurrence);
     }
    
    free(list);
    list = NULL;
    
    return 0;
}

char *strlwr(char *str)
{
    unsigned char *p = (unsigned char *)str;
    
    while (*p) {
        *p = tolower((unsigned char)*p);
        p++;
    }
    
    return str;
}
