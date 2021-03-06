//
//  main.c
//  order_list
//
//  Created by Hamza Rehman on 12/26/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct order_list{
    int n;
    struct order_list *next;
}order_list_n;

void insert_value(order_list_n *head, int n);
void sort_list(order_list_n *head);
void search_list(order_list_n *head, int val);
order_list_n *remove_first(order_list_n *head);
order_list_n *remove_last(order_list_n *head);
order_list_n *remove_by_value(order_list_n *head, int val); // list needs to be ordered for this function
void print_list(order_list_n *head);
void free_memory(order_list_n *head);

int main(int argc, const char * argv[]) {
    order_list_n *head;
    head = (order_list_n *) malloc (sizeof(order_list_n));
    if(head == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }
    
    head->n = 1;
    head->next = NULL;
    
    insert_value(head, -1);
    insert_value(head, 0);
    insert_value(head, 3);
    insert_value(head, -19);
    sort_list(head);
    //search_list(head, 0);
    print_list(head);
    //head = remove_first(head);
    //print_list(head);
    //head = remove_last(head);
    //print_list(head);
    head = remove_by_value(head, 0);
    print_list(head);
    free_memory(head);
    
    return 0;
}

void insert_value(order_list_n *head, int val){
    order_list_n *temp;
    temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = malloc (sizeof(order_list_n));
    if(temp->next == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    temp->next->n = val;
    temp->next->next = NULL;
    
}

void sort_list(order_list_n *head){
    order_list_n *temp1, *temp2;
    int temp;
    
    for(temp1 = head; temp1 != NULL; temp1 = temp1->next){
        for(temp2 = head; temp2 != NULL; temp2 = temp2->next){
            if(temp1->n < temp2->n){
                temp = temp1->n;
                temp1->n = temp2->n;
                temp2->n = temp;
            }
        }
    }
    
}

void search_list(order_list_n *head, int val){
    order_list_n *temp = head;
    int i = 0;
    
    while(temp != NULL){
        if(temp->n == val){
            printf("Value (%d) found in the list at index %d.\n", val, i);
            return;
        }
        else{
            temp = temp->next;
        }
        i++;
    }
    printf("Value (%d) is NOT in the list.\n", val);
    
}

order_list_n *remove_first(order_list_n *head){
    order_list_n *temp;
    
    if(head != NULL){
        temp = head->next;
        free(head);
        return temp;
    }
    
    return head;
    
}

order_list_n *remove_last(order_list_n *head){
    order_list_n *temp, *current  = head;
    
    // if list has only one element
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    
    while(current->next->next != NULL){
        current = current->next;
    }
    
    temp = current->next;
    current->next = NULL;
    free(temp);
    
    return head;
    
}

order_list_n *remove_by_value(order_list_n *head, int val){
    order_list_n *temp, *current = head;
    
    // if value is in start of the list
    if(head->n == val){
        temp = head->next;
        free(head);
        return temp;
    }
    
    while(current->next != NULL && current->next->n < val){
        current = current->next;
    }
    
    if(current->next != NULL && current->next->n == val){
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    else{
        printf("Can't remove %d, NOT in the list.\n", val);
    }
    
    return head;
}

void print_list(order_list_n *head){
    order_list_n *temp = head;
    
    printf("\nList:\n");
    while(temp != NULL){
        printf("%d ", temp->n);
        temp = temp->next;
    }
    printf("\n");
    
    free(temp);
}

void free_memory(order_list_n *head){
    order_list_n *temp = head;
    free(temp->next);
    free(temp);
    
}
