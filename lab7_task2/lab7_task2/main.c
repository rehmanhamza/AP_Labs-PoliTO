//
//  main.c
//  lab7_task2
//
//  Created by Hamza Rehman on 12/11/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int mult(int x, int y);
void d2b(int d, int *b, int n);
int countSpaces(char *s, int count);
void triangle(int n, int r);
void triangle_r(int n, int r, int c);
int catalan(int n);

int main(int argc, const char * argv[]) {
    int res;
    res = mult(2,3);
    printf("%d\n", res);
    
    int n = 23, *bin, bits;
    bits = (log(n+1) / log(2)) + 1;
    //printf("bits = %d\n", bits);
    bin = (int *) calloc (0, bits * sizeof(int));
    printf("%d in binary: (read in reverse order)\n", n);
    d2b(n, bin, bits);
    free(bin);
    printf("\n");
    
    int count = 0;
    char str[] = "This is a string with spaces.";
    printf("countSpaces = %d\n", countSpaces(str, count));
    
    //triangle(4, 1);
    triangle_r(5, 1, 1);
    printf("\n");
    printf("Catalan of %d = %d", 6, catalan(6));
    printf("\n");
    return 0;
}

// performing multiplication by addition through recursion
int mult(int x, int y){
    if(y == 0){
        return 0;
    }
    if(y == 1){
        return (x);
    }
    return (x+mult(x, y-1));
    
}

// converting binary into decimal using recursion
void d2b(int d, int *b, int n){
    if(n == 0){
        return;
    }
    else{
        b[n] = d%2;
        printf("%d ", b[n]);
        d2b(d/2, b, --n);
    }
}

int countSpaces(char *s, int count){
    if(*s == '\0'){
        return count;
    }
    if(isspace(*s)){
        count++;
    }
    return countSpaces(s+1, count);
}

void triangle(int n, int r){
    if(r > n){
        return;
    }
    for(int i = 0; i<r; i++){
        printf("%d ", r);
    }
    printf("\n");
    triangle(n, r+1);
}

void triangle_r(int n, int r, int c){
    if(r > n || c > n){
        return;
    }
    if(r >= c){
        printf("%d ", r);
        return triangle_r(n, r, c+1);
    }
    printf("\n");
    return triangle_r(n, r+1, 1);
}

int catalan(int n){
    if(n == 0){
        return 1;
    }
    
    int res = 0;
    for(int i=0; i<n; i++){
        res += catalan(i) * catalan(n-1-i);
    }
    return res;
}
