//
//  main.c
//  lab7_task1
//
//  Created by Hamza Rehman on 12/6/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define MAX_NAME 10
#define MAX_ID 5

typedef struct producer{
    char *name;
    char id1[MAX_ID+1];
    struct producer *next1;
}PRODUCER;

typedef struct product{
    char id2[MAX_ID+1];
    char *model;
    int price;
    struct product *next2;
}PRODUCT;

PRODUCER *readFile_producer(PRODUCER *head, FILE *file);
void print_list_producer(PRODUCER *head);

PRODUCT *readFile_product(PRODUCT *head, FILE *file);
void print_list_product(PRODUCT *head);

void find_ID(PRODUCER *producer_head, PRODUCT *product_head);
void free_memory(PRODUCER *producer_head, PRODUCT *product_head);

int main(int argc, const char * argv[]) {
    PRODUCER *head1 = NULL;
    PRODUCT *head2 = NULL;
    FILE *file1, *file2;
    
    file1 = fopen("producer.txt", "r");
    file2 = fopen("product.txt", "r");
    if(file1 == NULL || file2 == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    head1 = readFile_producer(head1, file1);
    fclose(file1);
    //print_list_producer(head1);
    
    head2 = readFile_product(head2, file2);
    fclose(file2);
    //print_list_product(head2);
    
    find_ID(head1, head2);
    free_memory(head1, head2);
    
    return 0;
}

PRODUCER *readFile_producer(PRODUCER *head, FILE *file){
    char buffer[MAX], name[MAX_NAME];
    PRODUCER *temp;
    
    while(fgets(buffer, MAX, file) != NULL){
        temp = (PRODUCER *) malloc (sizeof(PRODUCER));
        if(temp == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
        sscanf(buffer, "%s %s", name, temp->id1);
        temp->name = (char *) malloc (strlen(name)+1 * sizeof(char));
        if(temp->name == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
        sprintf(temp->name, "%s", name);
        temp->next1 = head;
        head = temp;
    }
    return head;
}

void print_list_producer(PRODUCER *head){
    PRODUCER *temp = head;
    
    while(temp != NULL){
        printf("%s %s\n", temp->name, temp->id1);
        temp = temp->next1;
    }
}

PRODUCT *readFile_product(PRODUCT *head, FILE *file){
    char buffer[MAX], model[MAX_NAME];
    PRODUCT *temp = head;
    
    while(fgets(buffer, MAX, file) != NULL){
        temp = (PRODUCT *) malloc (sizeof(PRODUCT));
        if(temp == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
        sscanf(buffer, "%s %s %d", temp->id2, model, &temp->price);
        temp->model = (char *) malloc (strlen(model)+1 * sizeof(char));
        if(temp->model == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
        sprintf(temp->model, "%s", model);
        temp->next2 = head;
        head = temp;
    }
    return head;
}

void print_list_product(PRODUCT *head){
    PRODUCT *temp = head;
    
    while(temp != NULL){
        printf("%s %s %d\n", temp->id2, temp->model, temp->price);
        temp = temp->next2;
    }
}

void find_ID(PRODUCER *producer_head, PRODUCT *product_head){
    PRODUCER *temp1;
    PRODUCT *temp2;
    
    for(temp1 = producer_head; temp1 != NULL; temp1 = temp1->next1){
        for(temp2 = product_head; temp2 != NULL; temp2 = temp2->next2){
            if(strcmp(temp1->id1, temp2->id2) == 0){
                printf("%s - %s || %s - %s - €%d\n", temp1->id1, temp1->name, temp2->id2, temp2->model, temp2->price);
            }
        }
        
    }
    
}

void free_memory(PRODUCER *producer_head, PRODUCT *product_head){
    PRODUCER *temp1, *free_temp1;
    PRODUCT *temp2, *free_temp2;
    
    temp1 = producer_head;
    temp2 = product_head;
    
    while(temp1 != NULL){
        free(temp1->name);
        free_temp1 = temp1->next1;
        free(temp1);
        temp1 = free_temp1;
    }
    while(temp2 != NULL){
        free(temp2->model);
        free_temp2 = temp2->next2;
        free(temp2);
        temp2 = free_temp2;
    }
    
    printf("\n\nfree_memory() -> successful.\n\n");
}
