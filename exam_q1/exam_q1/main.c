//
//  main.c
//  exam_q1
//
//  Created by Hamza Rehman on 1/28/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void invert_sequence(int *v1, int n, int *v2);

int main(int argc, const char * argv[]) {
    int n = 10, *v2;
    int v1[10] = {1,2,3,4,5,0,12,13,14,2};
    v2 = malloc (n * sizeof(int));
    if(v2 == NULL){
        perror("Error in memory allocation");
        return (EXIT_FAILURE);
    }
    
    invert_sequence(v1, n, v2);
    
    for(int i=0; i<n; i++){
        printf("%d ", v2[i]);
    }
    printf("\n");
    
    free(v2);
    
    return 0;
}

void invert_sequence(int *v1, int n, int *v2){
    int i, j, k;
    
    for(i=0, k=1; k<n; k++){
        if(v1[k] <= v1[k-1]){
            for(j=0; j<(k-i); j++){
                v2[i+j] = v1[k-j-1];
            }
            i = k;
        }
    }
    
    for(j=0; j<(k-i); j++){
        v2[i+j] = v1[k-j-1];
    }
}
