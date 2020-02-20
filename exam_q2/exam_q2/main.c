//
//  main.c
//  exam_q2
//
//  Created by Hamza Rehman on 1/28/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node node_t;
struct node{
    int key;
    node_t *next;
};

void int2list(int n, node_t **head);
void insert(node_t *head1, int key);
void print_list(node_t *head1);
int listSize(node_t *head);

int main(int argc, const char * argv[]) {
    int n = 1357;
    node_t *head;
    
    int2list(n, &head);
    print_list(head);
    
    printf("Size of Linked List = %d\n", listSize(head));
    return 0;
}

void int2list(int n, node_t **head){
    int size, *a;
    
    size = floor(log10(n) + 1);
    
    a = malloc (size * sizeof(int));
    
    for(int i=size-1; i>=0; i--){
        a[i] = n % 10;
        n = n / 10;
    }
    
    node_t *head1;
    head1 = (node_t *) malloc (sizeof(node_t));
    if(head1 == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    head1->key = a[0];
    head1->next = NULL;
    
    for(int i=1; i<size; i++){
        insert(head1, a[i]);
    }
    
    // I forgot only this assignment in exam
    *head = head1;
}

void insert(node_t *head1, int k){
    node_t *temp = head1;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = malloc (sizeof(node_t));
    if(temp->next == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    temp->next->key = k;
    temp->next->next = NULL;
    
}

void print_list(node_t *head1){
    node_t *temp = head1;
    
    while(temp != NULL){
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
    
}

int listSize(node_t *head){
    int size = 0;
    node_t *temp = head;
    
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    
    return size;
}
