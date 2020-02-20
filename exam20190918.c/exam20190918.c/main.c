//
//  main.c
//  exam20190918.c
//
//  Created by Hamza Rehman on 1/16/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct list list_t;
struct list{
    char *surname;
    char *name;
    list_t *next;
};

// Examination 1 - Exercise 2
void insert(list_t *head, char *surname, char *name);
int look_up(list_t *head, char *surname, char *name);
void order_list(list_t *head);
void print_list(list_t *head);

// Examination 20190918
void longest(char *in, int n, char ***out);

int main(int argc, const char * argv[]) {
    char *in = "THIS is a STring incLUDing small and capITAL lETTERS";
    int n = 5;
    char **out;
    
    longest(in, n, &out);
    
    /*for(int i=0; i<n; i++){
        printf("%s\n", out[i]);
    }*/
    
    for(int i=0; i<n; i++){
        free(out[i]);
    }
    free(out);
    
    list_t *head;
    head = (list_t *) malloc (sizeof(list_t));
    if(head == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }
    
    head->surname = "Muhammad";
    head->name = "Ali";
    head->next = NULL;
    
    
    insert(head, "Rehman", "Hamza");
    insert(head, "Hamzai", "Noor");
    insert(head, "Ali", "Ahmad");
    //insert(head, "Hamzai", "Noor");
    order_list(head);
    
    printf("Sorted List:\n");
    print_list(head);
    
    return 0;
}

void longest(char *in, int n, char ***out){
    char **m;
    m = (char **) malloc (n * sizeof(char *));
    for(int i=0; i<n; i++){
        m[i] = (char *) malloc (n * sizeof(char));
        if(m[i] == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
    }
    
    int k = 0, j = 0;
    for(int i=0; in[i] != '\0'; i++){
        if(in[i] >= 'A' && in[i] <= 'Z'){
            m[k][j++] = in[i];
        }
        if((in[i] == ' ' || islower(in[i])) && (i > 0) && (isupper(in[i-1]))){
            m[k][j] = '\0';
            k++;
            j = 0;
        }
    }
    
    *out = m;
    
}

void insert(list_t *head, char *surname, char *name){
    int n;
    n = look_up(head, surname, name);
    
    if(n == 0){
        list_t *temp = head;
    
        while(temp->next != NULL){
            temp = temp->next;
        }
    
        temp->next = malloc (sizeof(list_t));
        if(temp->next == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
    
        temp->next->surname = strdup(surname);
        temp->next->name = strdup(name);
        temp->next->next = NULL;
    }else{
        printf("Can't insert '%s %s' already present in the list.\n", surname, name);
    }
}

int look_up(list_t *head, char *surname, char *name){
    list_t *temp = head;
    int flag = 0;
    
    while(temp != NULL && flag == 0){
        if((strcmp(temp->surname, surname) == 0) && (strcmp(temp->name, name) == 0)){
            flag = 1;
        }
        
        temp = temp->next;
    }
    
    return flag;
}

void order_list(list_t *head){
    list_t *temp1, *temp2;
    char *temp_surname, *temp_name;
    
    temp_surname = malloc(20 * sizeof(char));
    temp_name = malloc (20 * sizeof(char));
    
    for(temp1 = head; temp1 != NULL; temp1 = temp1->next){
        for(temp2 = head; temp2 != NULL; temp2 = temp2->next){
            if(strcmp(temp1->surname, temp2->surname) < 0){
                temp_surname = strdup(temp1->surname);
                temp_name = strdup(temp1->name);
                temp1->surname = strdup(temp2->surname);
                temp1->name = strdup(temp2->name);
                temp2->surname = strdup(temp_surname);
                temp2->name = strdup(temp_name);
            }
        }
    }
    
}

void print_list(list_t *head){
    list_t *temp = head;
    
    while(temp != NULL){
        printf("%s %s\n", temp->surname, temp->name);
        temp = temp->next;
    }
}
