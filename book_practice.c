#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

#define true 1
#define false 0

#define DEBUG true * false

typedef struct list{
    int data;
    struct list *next;
}node;

void push(node *head, int val);
void find_element(node *head, int key);
void print_list(node *head);

int main(){
/*    int i=1, j=0;
    if(i==1){
        j=5;
    }
    else{
        j=6;
    }

    j = i == 1 ? 5 : 6;
    printf("1. %d\n", ++j);
    #ifdef AVOID
    printf("2. %d\n", j++);
    printf("3. %d\n", ++j);
    #else
    printf("4. %d\n", j);
    #endif
    printf("5. %d\n", ++j);
*/
    /*int l1, l2;
    char c, *result;
    // don't ever underestimate the power of pointers, they are the essence of C Programming
    l1 = sizeof(char);
    l2 = sizeof(c);
    //printf("l1 and l2 are %s\n", (l1 == l2 ? "equal" : "not equal"));
    result = l1 == l2 ? "Equal" : "Not equal";
    #if DEBUG
        printf("%s\n", result);
    #else
        printf("%p\n", result);
        printf("%lu\n", result);
    #endif

    double a = 10, n = 3;
    printf("Power  = %Lf\n", pow(a,n));*/

    /*char a[5][100] = {"watch your thoughts, they become words .",
                      "watch your words they become actions .",
                      "watch your actions ; they become habits .",
                      "watch your habits ; they become character .",
                      "watch your character ; it become your destiny ."};
    char b[3][10] = {"watch", "words", "become"};
    char *start, *end;
    int count[3] = {0}, i = 0;

    do{
        start = a[i];
        end = strstr(start, b[i]);
        if(end != NULL){
            if(end[strlen(b[i])] == ' '){
                count[i]++;

            }
            start = end + strlen(b[i]);
        }

        i++;
    }while (end != NULL);

    for(int i=0; i<3; i++){
        printf("%d\n", count[i]);
    }*/

    //printf("%d\n", (strcmp("milano", "torino")));

    node *head;
    head = (node *) malloc (sizeof(node));
    if(head == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }

    head->data = 0;
    head->next = NULL;
    push(head, 2);
    push(head, 4);
    push(head, 6);
    push(head, 8);

    print_list(head);

    find_element(head, 8);

}

void push(node *head, int val){
    node *new_node = head;
    
    while(new_node->next != NULL){
        new_node = new_node->next;
    }

    new_node->next = malloc (sizeof(node));
    new_node->next->data = val;
    new_node->next->next = NULL;

}

void find_element(node *head, int key){
    int flag = 1;
    node *p = head;
    while(p != NULL && flag == 1){
        if(p->data == key){
            printf("Found %d in list.\n", key);
            flag = 0;
        }
        else{
            p = p->next;
        }
    }
}

void print_list(node *head){
    node *current = head;
    while(current != NULL){
        printf(" %d", current->data);
        current = current->next;
    }
    printf("\n");
}
