//
//  main.c
//  lab2_task2
//
//  Created by Hamza Rehman on 9/21/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define N 10

int main(int argc, const char * argv[]) {
    
    FILE *file;
    file = fopen("seq.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    //char str[N][MAX+1], line[MAX+1];
    char main_str[MAX], str[N][MAX];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<MAX; j++){
            str[i][j] = '0';
        }
    }
    int i = 0, limit;
    
    while(fgets(main_str, sizeof(str), file)){
        //fputs(main_str, stdout);
        //fputs("",stdout);
        strcpy(str[i], main_str);
        
        i++;
    }
    
    limit = i;
    int h_seq = 0, v_seq = 0;
    for(int i = 0; i<limit; i++){
        for(int j = 0; j<MAX; j++){
            if(str[i][j] == 'h' && str[i][j+1] == 'h' && str[i][j+2] && str[i][j+3] == 'h' && str[i][j+4] == 'h'){
                h_seq++;
            }
            if(str[i][j] == 'v' && str[i+1][j] == 'v' && str[i+2][j] == 'v' && str[i+3][j] == 'v' && str[i+4][j] == 'v'){
                v_seq++;
            }
        }
    }
    
    printf("Horizontal Sequence: %d\nVertical Sequence  : %d\n", h_seq, v_seq);
    
    return 0;
}
