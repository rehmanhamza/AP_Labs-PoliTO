#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define R 2
#define C 3

int main(){
    char str[R][10] = {"12345", "abcdefgh"};
    int **mat;
    mat = (char **) malloc (R * sizeof(char *));
    if(mat == NULL){
        perror("Error in memory allocation");
        return EXIT_FAILURE;
    }

    for(int i=0; i<R; i++){
        mat[i] = (char *) malloc (strlen(str+1) * sizeof(char));
        if(mat[i] == NULL){
            perror("Error in memory allocation");
            return EXIT_FAILURE;
        }
        strcpy(mat[i], str[i]);
    }

    printf("- &mat             %lx\n", (long unsigned int) (&mat));
    printf("- mat              %lx\n", (long unsigned int) (mat));
    printf("- *mat             %lx\n", (long unsigned int) (*mat));

    for(int i=0; i<R; i++){
        printf("+ &(mat[%d])        %lx\n", i, (long unsigned int) (&(mat[i])));
        printf("+ mat+%d            %lx\n", i, (long unsigned int) (mat+i));
    }

}
