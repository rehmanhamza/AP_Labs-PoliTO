//
//  main.c
//  recursion_lecture
//
//  Created by Hamza Rehman on 12/16/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void anagram_r(char *anagram, char *word, int *used, int length, int n);

int main(int argc, const char * argv[]) {
    char anagram[MAX], word[MAX];
    int used[MAX], length;
    printf("Enter a word: ");
    scanf("%s", word);
    length = (int) strlen(word);
    anagram[length] = '\0';
    for(int i=0; i<length; i++){
        used[i] = 0;
    }
    printf("Anagrams:\n");
    anagram_r(anagram, word, used, length, 0);
    
    return 0;
}

void anagram_r(char *anagram, char *word, int *used, int length, int n){
    if(n == length){
        printf(" %s\n", anagram);
        return;
    }
    for(int i=0; i<length; i++){
        if(used[i] == 0){
            used[i] = 1;
            anagram[n] = word[i];
            anagram_r(anagram, word, used, length, n+1);
            used[i] = 0;
        }
    }
}
