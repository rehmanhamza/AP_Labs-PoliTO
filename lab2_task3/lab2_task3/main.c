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

int main(int argc, const char * argv[]) {
    FILE *file;
    file = fopen("test.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    char str[MAX], strOut[MAX], str1[4+1] = "test", str2[5+1] = "check", *start, *end;
    
    while(fgets(str, sizeof(str), file) != NULL){
        strOut[0] = '\0';
        start = str;
        do{
            end = strstr(start, str1);
            if(end == NULL){
                strcat(strOut, start);
            }
            else{
                strncat(strOut, start, end-start);
                strcat(strOut, str2);
                start = end + strlen(str1);
            }
        }while (end != NULL);
        
        printf("%s\n", strOut);
    }
    
    fclose(file);
    
    return 0;
}
