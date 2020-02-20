#include<stdio.h>
#include<stdlib.h>

typedef struct list list_t;
struct list{
    int key;
    list_t *next;
};

void push(list_t *, int );
list_t *pop_head(list_t *);
list_t *pop_tail(list_t *);
void search(list_t *, int );
void print_list(list_t *);
void free_memory(list_t *);

int main(){
    list_t *head = NULL;

    head = (list_t *) malloc (sizeof(list_t));
    if(head == NULL){
        return EXIT_FAILURE;
    }

    head->key = 1;
    head->next = NULL;

    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    head = pop_head(head);
    head = pop_tail(head);
    search(head, 4);
    print_list(head);
    free_memory(head);

}

void push(list_t *head, int n){
    list_t *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = (list_t *) malloc (sizeof(list_t));
    if(temp->next == NULL){
        perror("Error in mempry allocation");
        exit(EXIT_FAILURE);
    }

    temp->next->key = n;
    temp->next->next = NULL;
}

list_t *pop_head(list_t *head){
    list_t *temp;

    if(head != NULL){
        temp = head->next;
        free(head);
        return temp;
    }

    return head;

}

list_t *pop_tail(list_t *head){
    list_t *temp, *current = head;
    
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

void search(list_t *head, int n){
    list_t *temp = head;
    int i = 0;

    while(temp != NULL){
        if(temp->key == n){
            printf("Value (%d) found at index %d in the list.\n", n, i);
            return;
        }
        else{
            temp = temp->next;
        }
        i++;
    }
    printf("Value %d isn't in the list.\n", n);

}

void print_list(list_t *head){
    list_t *temp = head;
    
    printf("\n");
    while(temp != NULL){
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

void free_memory(list_t *head){
    list_t *temp = head;
    free(temp->next);
    free(temp);
}

