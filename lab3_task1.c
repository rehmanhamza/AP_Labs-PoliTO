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

#define MAX 100
#define M 20
#define N 3

char *strlwr(char *str);

int main(int argc, const char * argv[]) {
    FILE *file1, *file2;

    file1 = fopen("words.txt", "r");
    if(file1 == NULL){
        perror("Error opening file1");
        return EXIT_FAILURE;
    }

    file2 = fopen("text.txt", "r");
    if(file2 == NULL){
        perror("Error opening file2");
        return EXIT_FAILURE;
    }

    char words[N][M], str[MAX];
    int i = 0;
    while(fgets(str, sizeof(str), file1)){
        strcpy(words[i], strlwr(str));
        //strcpy(words[i],strlwr(words[i]));
        i++;
    }

    fclose(file1);

    /*for(int i=0; i<3; i++){
        printf("%s", words[i]);
    }*/

    char buffer[10][MAX];
    int count[3] = {0}, j = 0, limit;
    while (fgets(str, sizeof(str), file2)) {
        strcpy(buffer[j], strlwr(str));

        j++;
    }

    limit = j;

    fclose(file2);

    for(int i=0; i<limit; i++){
        for(int j=0; j<3; j++){
            if(strstr(buffer[i], words[j]) != NULL){
                printf("%s\n", words[j]);//count[i]++;
            }
        }
    }

    for(int i=0; i<3; i++){
        printf("%d\n", count[i]);
    }
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
