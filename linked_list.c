#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}node_t;

void print_list(node_t *head);
void push(node_t *head, int val);

int main(){
    node_t *head = NULL;
    head = malloc (sizeof(node_t));
    if(head == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }

    head->value = 1;
    head->next = NULL;

    push(head, 1);
    print_list(head);

}

void print_list(node_t *head){
    node_t *current = head;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
}

void push(node_t *head, int val){
    node_t *current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = malloc (sizeof(node_t));
    current->next->value = val;
    current->next->next = NULL;
}
