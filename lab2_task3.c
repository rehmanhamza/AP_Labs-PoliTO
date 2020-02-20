//
//  main.c
//  lab2_task3
//
//  Created by Hamza Rehman on 10/7/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define N 5

int main(int argc, const char * argv[]) {
    FILE *file;
    file = fopen("test.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char main_str[MAX+1], str[N][MAX+1];

    for(int i=0; i<N; i++){
        for(int j=0; j<MAX; j++){
            str[i][j] = '0';
        }
    }

    int i = 0, limit;

    while(fgets(main_str, sizeof(main_str), file)){
        strcpy(str[i], main_str);

        i++;
    }
    limit = i;

    char new_str[N][MAX+1];

    for(int i=0; i<limit; i++){
        for(int j=0; j<MAX; j++){
            if(str[i][j] == 't' && str[i][j+1] == 'e' && str[i][j+2] == 's' && str[i][j+3] == 't'){
                str[i][j] = 'c';
                str[i][j+1] = 'h';
                str[i][j+2] = 'e';
                str[i][j+3] = 'c';
            }
            /*else{
                strcpy(new_str[i], str[i]);
            }*/
        }
    }

    //printf("here\n");
    for(int i=0; i<limit; i++){
        printf("%s", str[i]);
     }

    return 0;
}
