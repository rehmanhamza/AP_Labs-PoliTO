//
//  main.c
//  lab6_task1
//
//  Created by Hamza Rehman on 12/5/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct words{
    char *word;
    int count;
    struct words *next;
}word_list;

word_list *readFile(FILE *file);
word_list *findWord(word_list *head, char *word);
void print_list(word_list *head);
void free_memory(word_list *head);

int main(int argc, const char * argv[]) {
    word_list *head = NULL;
    FILE *file;
    
    file = fopen("text.txt", "r");
    
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    head = readFile(file);
    fclose(file);
    print_list(head);
    free_memory(head);
    
    return 0;
}

word_list *readFile(FILE *file){
    word_list *temp, *head = NULL;
    char buffer[MAX];
    int i=0;
    
    while(fscanf(file, "%s", buffer) != EOF){
        for(i=0; i<strlen(buffer); i++){
            buffer[i] = tolower(buffer[i]);
        }
        temp = findWord(head, buffer);
        
        if(temp != NULL){
            temp->count++;
        }
        else{
            temp = (word_list *) malloc (sizeof(word_list));
            temp->word = strdup(buffer);
            temp->count = 1;
            temp->next = head;
            head = temp;
        }
    }
    return head;
}

word_list *findWord(word_list *head, char *word){
    word_list *temp = head;
    
    while(temp != NULL){
        if(strcmp(temp->word, word) == 0){
            return temp;
        }
        else{
            temp = temp->next;
        }
    }
    return NULL;
}

void print_list(word_list *head){
    word_list *current = head;
    
    while(current != NULL){
        printf("%s %d\n", current->word, current->count);
        current = current->next;
    }
}

void free_memory(word_list *head){
    word_list *temp;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}
