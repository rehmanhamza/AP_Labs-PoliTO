#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node node_t;
struct node{
    int val;
    node_t *next;
};

void int2list(int n, node_t **head);
void insert(node_t *head_t, int k);
void print_list(node_t *head);

int main(){
    int n = 1357;
    node_t *head = NULL;
    int2list(n, &head);
    print_list(head);
}

void int2list(int n, node_t **head){
    int size, *a;
    size = floor(log10(n) + 1);
    a = (int *) malloc (size * sizeof(int));

    for(int i=size-1; i>=0; i--){
        a[i] = n % 10;
        n = n / 10;
    }

    node_t *head_t = NULL;
    head_t = (node_t *) malloc (sizeof(node_t));
    if(head_t == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    head_t->val = a[0];
    head_t->next = NULL;

    for(int i=1; i<size; i++){
        insert(head_t, a[i]);
    }

    *head = head_t;
}

void insert(node_t *head_t, int k){
    node_t *temp = head_t;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = malloc (sizeof(node_t));
    if(temp->next == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    temp->next->val = k;
    temp->next->next = NULL;

}

void print_list(node_t *head){
    node_t *temp = head;

    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}
