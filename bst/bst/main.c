//
//  main.c
//  bst
//
//  Created by Hamza Rehman on 1/13/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

// declaring struct using C++ style coding, much better than C
typedef struct node node_t;
struct node{
    int val;
    node_t *left;
    node_t *right;
};

node_t *insert(node_t * , int );
void traverse(node_t * );
void pre_order(node_t * );
void in_order(node_t * );
void post_order(node_t * );
void countNode(node_t * , int * );
void search(node_t * , int );
node_t *search_node(node_t *, int );
int height_bst(node_t *);

int main(){
    node_t *root = NULL, *temp = NULL;
    FILE *file;
    int lines = 1;
    file = fopen("tree.txt", "r");
    if(file == NULL){
        perror("Error in opening file");
        return EXIT_FAILURE;
    }
    
    for(char chr = getc(file); chr != EOF; chr = getc(file)){
        if(chr == '\n'){
            lines++;
        }
    }
    fclose(file);
    
    //printf("Lines = %d\n", lines);
    int *a = malloc (sizeof(int) * lines);
    
    file = fopen("tree.txt", "r");
    for(int i=0; i<lines; i++){
        fscanf(file, "%d", &a[i]);
    }
    fclose(file);
    
    for(int i=0; i<lines; i++){
        root = insert(root, a[i]);
    }
    
    pre_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    post_order(root);
    printf("\n\n");
    
    //search(root, 45);
    //temp = search_node(root, 55);
    int depthBST = height_bst(root);
    printf("depthBST = %d\n", depthBST);
    
    free(a);
    free(root);
    free(temp);
    return 0;
}

node_t *insert(node_t *root, int n){
    if(root == NULL){
        root = malloc (sizeof(node_t));
        root->val = n;
        root->left = NULL;
        root->right = NULL;
    }else if(n < root->val){
        root->left = insert(root->left, n);
    }else{
        root->right = insert(root->right, n);
    }
    
    return root;
}

void traverse(node_t *root){
    
    // if tree is empty then return
    if(root == NULL){
        return;
    }
    
    traverse(root->left);
    traverse(root->right);
}

void pre_order(node_t *root){
    // if tree is empty then return
    if(root == NULL){
        return;
    }
    
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
    
    return;
}

void in_order(node_t *root){
    // if tree is empty then return
    if(root == NULL){
        return;
    }
    
    in_order(root->left);
    printf("%d ", root->val);
    in_order(root->right);
    
    return;
}

void post_order(node_t *root){
    // if tree is empty then return
    if(root == NULL){
        return;
    }
    
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->val);
    
    return;
}

void countNode(node_t *root, int *count_child){
    node_t *child_l, *child_r;
    
    // termination condition
    if(root == NULL){
        return;
    }
    
    child_l = root->left;
    child_r = root->right;
    
    if(child_l != NULL && child_r != NULL){
        ++count_child[2];
    }else if(child_l == NULL && child_r == NULL){
        ++count_child[0];
    }else{
        ++count_child[1];
    }
    
    // recur left
    if(child_l != NULL){
        countNode(root->left, count_child);
    }
    // recur right
    if(child_r != NULL){
        countNode(root->right, count_child);
    }
    
    return;
}

void search(node_t *root, int n){
    if(root == NULL){
        printf("Value %d not found in BST.\n", n);
        return;
    }
    
    if(root->val == n){
        printf("Value %d found in BST.\n", n);
        return;
    }
    
    if(n < root->val){
        search(root->left, n);
    }else{
        search(root->right, n);
    }
}

node_t *search_node(node_t *root, int n){
    if(root == NULL){
        return NULL;
    }
    
    if(n < root->val){
        return search_node(root->left, n);
    }
    if(n > root->val){
        return search_node(root->right, n);
    }
    
    return root;
}

int height_bst(node_t *root){
    int l, r;
    
    if(root == NULL){
        return 0;
    }
    
    l = height_bst(root->left);
    r = height_bst(root->right);
    
    if(l > r){
        return (l+1);
    }else{
        return (r+1);
    }
}
