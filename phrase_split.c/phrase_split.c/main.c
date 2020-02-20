//
//  main.c
//  phrase_split.c
//
//  Created by Hamza Rehman on 1/17/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int phrase_split(char v[], char ***m);
int count_words(char v[]);

int main(int argc, const char * argv[]) {
    int n;
    char v[100] = "This is a phrase to split into sub-strings";
    char **m;
    n = phrase_split(v, &m);
    
    printf("Number of words = %d\n", n);
    for(int i=0; i<n; i++){
        printf("%s\n", m[i]);
    }
    
    return 0;
}

int phrase_split(char v[], char ***m){
    char *s;
    unsigned long str_len = strlen(v);
    int n;

    n = count_words(v);
    
    s = malloc (str_len * sizeof(char));
    if(s == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    s = strdup(v);
    
    char **mat;
    mat = (char **) malloc (n * sizeof(char *));
    for(int i=0; i<n; i++){
        mat[i] = (char *) malloc (n * sizeof(char));
        if(mat[i] == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
    }
    
    int j = 0, k = 0;
    for(int i=0; i<str_len; i++){
        if(s[i] == ' '){
            mat[k][j++] = '\0';
            k++;
            j = 0;
        }else{
            mat[k][j++] = s[i];
        }
        
    }
    
    *m = mat;
    
    return n;
}

int count_words(char v[]){
    int n = 0, i = 0, flag = 0;
    
    while(v[i] != '\0'){
        if(v[i] == ' '){
            flag = 0;
        }else if(flag == 0){
            ++n;
            flag = 1;
        }
        i++;
    }
    
    return n;
}
