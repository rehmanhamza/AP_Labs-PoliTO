//
//  main.c
//  linked_list
//
//  Created by Hamza Rehman on 10/30/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}node_t;

void push(node_t *head, int val);
void push_head(node_t **head, int val);
int pop(node_t **head);
int remove_last(node_t *head);
int remove_by_index(node_t **head, int n);
void print_list(node_t *head);

int main(int argc, const char * argv[]) {
    node_t *head = NULL;
    head  = malloc (sizeof(node_t));
    if(head == NULL){
        perror("Error in mempry allocation");
        return EXIT_FAILURE;
    }
    
    head->value = 1;
    head->next = NULL;
    
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push_head(&head, 0);
    push_head(&head, -1);
    print_list(head);
    //pop(&head);
    //remove_last(head);
    remove_by_index(&head, 1);
    print_list(head);
    
    return 0;
}

// Adding an item to the end of the list
void push(node_t *head, int val){
    node_t *current = head;
    
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = malloc(sizeof(node_t));
    current->next->value = val;
    current->next->next = NULL;
}

// Adding an item to the beginning of the list
void push_head(node_t **head, int val){
    node_t *new_node;
    new_node = malloc (sizeof(node_t));
    
    new_node->value = val;
    new_node->next = *head;
    *head = new_node;
}

// Removing first item from the list
int pop(node_t **head){
    int retval=-1;
    node_t *next_node = NULL;
    
    if(*head == NULL){
        return -1;
    }
    
    next_node = (*head)->next;
    retval = (*head)->value;
    free(*head);
    *head = next_node;
    
    return retval;
}

// Removing last item from the list
int remove_last(node_t *head){
    int retval = 0;
    // if only one item is in the list
    if(head->next == NULL){
        retval = head->value;
        free(head);
        return retval;
    }
    
    node_t *current = head;
    while(current->next->next != NULL){
        current = current->next;
    }
    
    retval = current->next->value;
    free(current->next);
    current->next = NULL;
    return retval;
}

// Removing specific item from the list
int remove_by_index(node_t **head, int n){
    int i = 0, retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;
    
    if(n == 0){
        return pop(head);
    }
    
    for(i=0; i<n-1; i++){
        if(current->next == NULL){
            return -1;
        }
    }
    current = current->next;
    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);
    
    return retval;
}

void print_list(node_t *head){
    node_t *current = head;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
