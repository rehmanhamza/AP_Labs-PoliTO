//
//  main.c
//  exam_book
//
//  Created by Hamza Rehman on 1/20/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Examination 3 - Exercise 1
int search(int *a, int *b, int n1, int n2);

// Examination 4 - Exercise 1
void string_search(char *str, int *start, int *length);

// Examination 4 - Exercise 2
typedef struct node node_t;
struct node{
    char *str;
    node_t *next;
};

int split(char *str, char ***m);
void insert_head(node_t **head, char *str);
void print_list(node_t *head);

// Examination 5 - Exercise 1
void duplicate_erase(char *str);

// Examination 5 - Exercise 2
typedef struct bst bst_t;
struct bst{
    int value;
    bst_t *left;
    bst_t *right;
};

bst_t *insert_bst(bst_t *root, int n);
int height_bst(bst_t *root);
void levelByLevel_visit(bst_t *root, int height);
void levelByLevel_visit_r(bst_t *root, int level);

// Examination 6 - Exercise 2
void path_write(bst_t *root, int height);
void path_write_r(bst_t *root, int height, int level, bst_t **path);

// Examination 7 - Exercise 2
void tree_dup(bst_t *root);

int main(int argc, const char * argv[]) {
    // Driver program for Examination 3 - Exercise 1
    /*int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[5] = {4,5,6,7,8};
    int n1 = 10, n2 = 5, startIndex;
    
    startIndex = search(a, b, n1, n2);
    
    printf("startIndex = %d\n", startIndex);*/
    
    // Driver program for Examination 4 - Exercise 1
    /*char *str = "abbcccddddddeeee";
    int *start, *length;
    
    string_search(str, start, length);*/
    
    // Driver program for Examination 4 - Exercise 2
    /*node_t *head;
    char *str = "a.bb.ccc.dddd.eeeee.ffffff";
    char **m;
    int n;
    n = split(str, &m);
    
    head = (node_t *) malloc (sizeof(node_t));
    if(head == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }
    
    head->str = m[0];
    head->next = NULL;
    
    for(int i=1; i<n; i++){
        insert_head(&head, m[i]);
    }
    
    print_list(head);*/
    
    // Driver program for Examination 5 - Exercise 1
    /*char *str = "aa;;;bbbab;";
    duplicate_erase(str);*/
    
    // Driver program for Examination 5 - Exercise 2
    /*int n = 13, *a;
    a = malloc (n * sizeof(int));
    FILE *file;
    file = fopen("tree.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &a[i]);
    }
    fclose(file);
    
    bst_t *root = NULL;
    for(int i=0; i<n; i++){
        root = insert_bst(root, a[i]);
    }
    
    int height;
    height = height_bst(root);
    
    //printf("height = %d\n", height);
    
    //levelByLevel_visit(root, height);
    
    //free(a);
    //free(root);
    
    // Driver program for Examination 6 - Exercise 2
    path_write(root, height);
    
    free(a);
    free(root);*/
    
    return 0;
}

int search(int *a, int *b, int n1, int n2){
    int i = 0, j = 0, startIndex;
    
    while(i < n1 && j < n2){
        if(a[i] == b[j]){
            i++;
            j++;
            
            if(j == n2){
                startIndex = i - j;
                return startIndex;
            }
        }else{
            i++;
            j = 0;
        }
    }
    return -1;
}

void string_search(char *str, int *start, int *length){
    int i = 0, j = 0;
    *start = *length = i = 0;
    
    while(i < strlen(str)-1){
        j = i;
        while(j < strlen(str) && str[j] == str[i]){
            j++;
        }
        if((j - i) > (*length)){
            *length = j - i;
            *start = i;
        }else{
            i++;
        }
    }
    
    printf("start = %d\nlength = %d\n", *start, *length);
}

int split(char *str, char ***m){
    int i = 0, words = 0, flag = 0;
    
    while(str[i] != '\0'){
        if(str[i] == '.'){
            flag = 0;
        }else if(flag == 0){
            words++;
            flag = 1;
        }
        i++;
    }
    
    char **mat;
    mat = (char **) malloc (words * sizeof(char *));
    for(int i=0; i<words; i++){
        mat[i] = (char *) malloc (words * sizeof(char));
        if(mat[i] == NULL){
            perror("Error in memory allocation");
            exit(EXIT_FAILURE);
        }
    }
    
    int k = 0, j =0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '.'){
            mat[k][j++] = '\0';
            k++;
            j = 0;
        }else{
            mat[k][j++] = str[i];
        }
    }
    
    *m = mat;
    
    return words;
}

void insert_head(node_t **head, char *str){
    node_t *temp;
    temp = malloc (sizeof(node_t));
    
    temp->str = str;
    temp->next = *head;
    *head = temp;
}

void print_list(node_t *head){
    node_t *temp = head;
    
    while(temp != NULL){
        printf(" -> %s", temp->str);
        temp = temp->next;
    }
    printf("\n");
}

void duplicate_erase(char *str){
    char *m;
    m = malloc ((strlen(str)) * sizeof(char));
    if(m == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    m = strdup(str);
    
    for(int i=0; i<strlen(m); i++){
        for(int j=0; m[j] != '\0'; j++){
            if(m[i] == m[j]){
                for(int k=j; m[k] != '\0'; k++){
                    m[k] = m[k+1];
                }
            }
        }
    }
    
    //printf("%s\n", m);
}

bst_t *insert_bst(bst_t *root, int n){
    if(root == NULL){
        root = malloc (sizeof(bst_t));
        root->value = n;
        root->left = NULL;
        root->right = NULL;
    }else if(n < root->value){
        root->left = insert_bst(root->left, n);
    }else{
        root->right = insert_bst(root->right, n);
    }
    
    return root;
}

int height_bst(bst_t *root){
    int l, r;
    
    if(root == NULL){
        return 0;
    };
    
    l = height_bst(root->left);
    r = height_bst(root->right);
    
    if(l > r){
        return (l+1);
    }else{
        return (r+1);
    }
}

void levelByLevel_visit(bst_t *root, int height){
    for(int i=0; i<=height; i++){
        levelByLevel_visit_r(root, i);
        printf("\n");
    }
}

void levelByLevel_visit_r(bst_t *root, int level){
    if(root == NULL){
        return;
    }
    
    if(level == 1){
        printf("%d ", root->value);
    }else if(level > 1){
        levelByLevel_visit_r(root->left, level-1);
        levelByLevel_visit_r(root->right, level-1);
    }
}

void path_write(bst_t *root, int height){
    bst_t **path;
    
    path = (bst_t **) malloc (height * sizeof(bst_t *));
    if(path == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    path_write_r(root, height, 0, path);
    
    free(path);
    return;
}

void path_write_r(bst_t *root, int height, int level, bst_t **path){
    if(root == NULL){
        printf("Path: ");
        for(int i=0; i<level; i++){
            printf("%d ", path[i]->value);
        }
        printf("\n");
        return;
    }
    
    path[level] = root;
    path_write_r(root->left, height, level+1, path);
    path_write_r(root->right, height, level+1, path);
    
    return;
}

void tree_dup(bst_t *root){
    if(root == NULL){
        return;
    }
    
    tree_dup(root->left);
    tree_dup(root->right);
    
    bst_t *temp;
    temp = (bst_t *) malloc (1 * sizeof(bst_t));
    if(temp == NULL){
        perror("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    temp->value = root->value;
    // Link from new node to children
    temp->left = root->left;
    temp->right = NULL;
    // Link from parent to new node
    root->left = temp;
    
    return;
}
