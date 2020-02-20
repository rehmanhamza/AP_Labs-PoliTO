#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct node node_t;
struct node{
    int val;
    node_t *left;
    node_t *right;
};

node_t *insert(node_t * , int );
void traverse(node_t * );
void preorder(node_t * );
void inorder(node_t * );
void postorder(node_t * );
void countNode(node_t * , int * );

int main(){
    node_t *root = NULL;
    const int size = 2000;
    int *a = malloc (sizeof(int) * size);
    clock_t start, end;
    srand(time(NULL));

    printf("Generating array with %d random values.\n", size);

    start = clock();
    for(int i=0; i<size; i++){
        a[i] = rand() % 100;
    }
    end = clock();

    printf("Done. Took %f seconds\n\n", (double) (end - start) / CLOCKS_PER_SEC);
    printf("Filling the tree with %d nodes.\n", size);

    start = clock();
    for(int i=0; i<size; i++){
        root = insert(root, a[i]);
    }
    end = clock();

    printf("Done. Took %f seconds\n\n", (double) (end - start) / CLOCKS_PER_SEC);
    printf("Traversing all %d nodes in the tree.\n", size);

    start = clock();
    traverse(root);
    end = clock();

    printf("Done. Took %f seconds\n\n", (double) (end - start) / CLOCKS_PER_SEC);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    int *count_child = malloc (sizeof(int) * 3);
    countNode(root, count_child);
    for(int i=0; i<3; i++){
        printf("Node(s) with %d child(s) -> %d\n", i, *count_child+i);
    }

    free(a);
    free(root);
    free(count_child);
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

void preorder(node_t *root){
    // if tree is empty then return
    if(root == NULL){
        return;
    }

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);

    return;
}

void inorder(node_t *root){
    // if tree is empty then return
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);

    return;
}

void postorder(node_t *root){
    // if tree is empty then return
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
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