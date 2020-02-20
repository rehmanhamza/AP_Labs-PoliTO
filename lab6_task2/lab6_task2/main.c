//
//  main.c
//  lab6_task2
//
//  Created by Hamza Rehman on 12/6/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_ID 16+1
#define MAX_DATE 10+1
#define MAX_NAME 21

typedef struct employee{
    char *name;
    char id[MAX_ID];
    char date[MAX_DATE];
    int salary;
    struct employee *right;
    struct employee *left;
}employee_list;

employee_list *readFile(employee_list *head, FILE *file);
void print_list(employee_list *head, char *name, char *command);
void free_memory(employee_list *head);

int main(int argc, const char * argv[]) {
    employee_list *head = NULL;
    char *name = "Giallo_Antonio";
    char *command = "---+";
    
    FILE *file;
    file = fopen("data.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    head = readFile(head, file);
    fclose(file);
    
    print_list(head, name, command);
    free_memory(head);
    
    return 0;
}

employee_list *readFile(employee_list *head, FILE *file){
    char buffer[MAX], name[MAX_NAME];
    employee_list *temp;
    
    while(fgets(buffer, MAX, file) != NULL){
        temp = (employee_list *) malloc (sizeof(employee_list));
        if(temp == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
        sscanf(buffer, "%s %s %s %d", name, temp->id, temp->date, &temp->salary);
        temp->name = (char *) malloc ((strlen(name)+1) * sizeof(char));
        if(temp->name == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
        sprintf(temp->name, "%s", name);
        temp->right = head;
        temp->left = NULL;
        if(head != NULL){
            head->left = temp;
        }
        head = temp;
    }
    
    return head;
}

void print_list(employee_list *head, char *name, char *command){
    employee_list *temp;
    
    for(temp=head; temp != NULL; temp=temp->right){
        if(strcmp(temp->name, name) == 0){
            break;
        }
    }
    
    if(temp == NULL){
        return;
    }
    
    printf("%s %s %s %d\n", temp->name, temp->id, temp->date, temp->salary);
    
    for(int i=0; i<strlen(command); i++){
        if(command[i] == '+'){
            if(temp->right != NULL){
                temp = temp->right;
            }
        }
        else{
            if(temp->left != NULL){
                temp = temp->left;
            }
        }
        printf("%s %s %s %d\n", temp->name, temp->id, temp->date, temp->salary);
    }
    return;
}

void free_memory(employee_list *head){
    employee_list *temp1, *temp2;
    
    temp1 = head;
    while(temp1 != NULL){
        free(temp1->name);
        temp2 = temp1->right;
        free(temp1);
        temp1 = temp2;
    }
}
