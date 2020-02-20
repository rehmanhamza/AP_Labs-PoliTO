
/*
 *  20.01.2020
 *  Shabbir Bilal
 *   id-> s258509
 *   sol of 18 point exam
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
 --> no change in wrapper(find_sol), recursive(play),check and dispose functions
 --> only changes that I made from my onPaper solution to this solution is in read_file function and are mentioned in comments
 
 -->I was in rush and forgot to define data structure,second requirement of exam, and stored whole data
 in mat,vari and claude.
 this could be the data structure to store data
 typedef struct data_s{
 int **mat;
 int cla;
 int var;
 }data_t;
 
 in main  we can declare it as
 data_t datum;
 
 datum.mat = read_file(argv[1],&clause,&vari);
 datum.var = vari;
 datum.cla = clause
 
 then passing just datum.mat , datum.var and datum.cla to call functions in main.
 
 */

int **read_file(char*,int*,int*);
void find_sol(int**,int,int);
int play(int**,int*,int,int,int);
int check(int**,int*,int,int);
void dispose(int **,int);

int main(int argc,char *argv[])
{
    int clause,vari;
    int **mat;
    
    mat = read_file("input.txt",&clause,&vari);
    find_sol(mat,clause,vari);
    dispose(mat,clause);
    
    
    
    return 0;
}


int **read_file(char* fil,int* clause,int* vari){
    
    int **mat,i,m,j,n,c,x;
    char *str;
    FILE *fp;
    fp = fopen(fil,"r");
    if(fp == NULL){
        printf("error opening file\n");
        exit(-1);
    }
    
    if(fscanf(fp,"%d %d ",clause,vari) != 2){
        printf("error reading file\n");
        exit(-1);                                       //missing this exit statement on paper
    }
    str = (char*) malloc((*vari*2 + 1) * sizeof(char));
    mat = (int **) malloc(*clause * sizeof(int*));
    if(str == NULL || mat == NULL){
        printf("memory error\n");
        exit(-1);
    }
    x = *clause *2 +1;
    for(i=0; i<*clause; i++){
        fgets(str,x,fp);                                  // str and fp are put in right position
        
        m =  atoi(&str[0]);                              // use of atoi function to make char to int
        mat[i] = (int *) malloc((m+1) *sizeof(int));
        if(mat[i] == NULL){
            printf("memory error\n");
            exit(-1);
        }
        
        
        c = 0;
        j = 1;
        mat[i][c++] = m;    //  <- missing initilizing of n  and assigning vale to mat
        n = 0 ;
        
        while(str[j] != '\0'){
            
            if(str[j] == '-'){
                n = 1;
                j++;
                continue;
            }
            if(isdigit(str[j])){                        // isdigit instead of isintiger to check either character is of digit type
                if(n){
                    mat[i][c] = (atoi(&str[j]) * -1);       // use of &
                    j++;
                    c++;
                    n=0;
                }else{                                   //else statement missing on paper
                    mat[i][c] = atoi(&str[j]);
                    j++;
                    c++;
                }
            }
            j++;                                       // incriment in case of space
        }
    }
    free(str);
    return mat;
}


void find_sol(int** mat,int clause,int vari){
    
    int *sol,i;
    sol = (int*) malloc(vari *sizeof(int));
    if(sol == NULL){
        printf("memory error\n");
        exit(-1);
    }
    
    for(i=0; i<vari; i++){
        sol[i] =0;
    }
    
    if(play(mat,sol,0,vari,clause)){
        printf("a possoble mapping is\n{");
        for(i=0; i<vari; i++){
            printf("x%d=%d ",i+1,sol[i]);
        }
        printf("}\n");
    }else{
        printf("mapping not found(UNSAT)\n");
    }
    free(sol);
}

int play(int** mat,int* sol,int pos,int vari,int clause){
    
    int i;
    if(pos >= vari){
        if(check(mat,sol,vari,clause)){
            return 1;
        }
        return 0;
    }
    
    for(i=0; i<=1; i++){
        sol[pos] = i;
        if(play(mat,sol,pos+1,vari,clause)){
            return 1;
        }
    }
    return 0;
}


int check(int** mat,int* sol,int vari,int clause){
    int i,n,j,res,sin;
    
    for(i=0; i<clause; i++){
        n = mat[i][0];
        res =0;
        for(j=1; j<=n; j++){
            if(mat[i][j] > 0 && sol[mat[i][j]-1]){
                res = 1;
            }else if(mat[i][j] < 0){
                sin = abs(mat[i][j]);
                if(!sol[sin-1]){
                    res = 1;
                }
            }
        }
        if(!res){
            return 0;
        }
    }
    return 1;
}

void dispose(int ** mat,int r){
    int i;
    for(i=0; i<r; i++){
        free(mat[i]);
    }
    free(mat);
    return;
}



