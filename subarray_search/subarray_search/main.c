//
//  main.c
//  subarray_search
//
//  Created by Hamza Rehman on 12/17/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>

int subarray_search(int *v1, int *v2, int n1, int n2);

int main(int argc, const char * argv[]) {
    int v1[15] = {2, 3, 4, -1, -10, 5, 6, 8, 11, -9, 8, -10, 9, 3, 0};
    int v2[5] = {-10, 5, 6, 8, 11};
    int n1 = 15, n2 = 5, res;
    
    res = subarray_search(v1, v2, n1, n2);
    
    if(res == 0){
        printf("Subarray found.\n");
    }
    if(res < 0){
        printf("Subarray not found.\n");
    }
    
    return 0;
}

int subarray_search(int *v1, int *v2, int n1, int n2){
    int i = 0, j = 0;
    
    while(i < n1 && j < n2){
        if(v1[i] == v2[j]){
            i++;
            j++;
            
            if(j == n2){
                return 0;
            }
        }
        else{
            i++;
            j = 0;
        }
    }
    return -1;
}
