#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8
#define M 5
#define O 10
#define MAX 4
#define BASE 2

void show(int x[], int l, int r);
int max(int y[], int l, int r);
long factorial(long n);
long fibonacci(long n);
int bin_search(int v[], int l, int r, int k);
void reverse_print(char *s);
void binary_r(int *array, int depth, int n);
void anagram_r(char *word, char *anagram, int *used, int length, int n);

int main(){
    /*int v1[N] = {1,5,6,3,4}, v2[N] = {-1,0,-4,8,1}, v3[10];
    int i, j, k;
    i = j = k = 0;
    
    while(i < N && j < N){
        if(v1[i] < v2[j]){
            v3[k++] = v1[i++];
        }
        else{
            v3[k++] = v2[j++];
        }
    }
    while(i < N){
        v3[k++] = v1[i++];
    }
    while(j < N){
        v3[k++] = v2[j++];
    }

    for(int i=0; i<N+N; i++){
        printf("%d ", v3[i]);
    }*/

    //int x[N] = {1,2,3,4,5,6,7,8};
    //show(x,0, 7);

    int y[M] = {10, 3, -1, 50, 0}, res;
    res = max(y, 0, 4);
    printf("Max = %d\n", res);
    //printf("Factorial of %d is %d\n", 5, factorial(5));
    //printf("Fibonacci of %d is %d\n", 9, fibonacci(9));

    int z[O] = {1,2,3,4,5,6,7,8,9,10};
    printf("Element found at index %d.\n", bin_search(z, 0, 9, 7));

    char str[MAX+1] = "ABCD";
    reverse_print(str);
    printf("\n");

    int *array;
    array = (int *) malloc (3 * sizeof(int));
    binary_r(array, 0, 3);
    free(array);

    /*char anagram[MAX], word[MAX];
    int used[MAX], length;
    printf("Enter a word: ");
    scanf("%s", word);
    length = strlen(word);
    anagram[length] = '\0';
    for(int i=0; i<length; i++){
        used[i] = 0;
    }
    printf("Anagrams:\n");
    //anagram_r(anagram, word, used, length, 0);*/
}

void show(int x[], int l, int r){
    int c;

    if (l >= r){
        return;
    }

    c = (l + r) / 2;

    for (int i = l; i <= c; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
    show(x, l, c);

    for (int i = c + 1; i <= r; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
    show(x, c + 1, r);

    return;
}

int max(int y[], int l, int r){
    int u, v, m;
    m = (l + r) / 2;
    if (l == r)
    {
        return y[l];
    }
    u = max(y, l, m);
    v = max(y, m + 1, r);
    if (u > v)
    {
        return u;
    }
    else
    {
        return v;
    }
}

long factorial(long n){
    if (n == 0){
        return 1;
    }
    else{
        return (n * factorial(n - 1));
    }
}

long fibonacci(long n){
    if(n == 0 || n == 1){
        return n;
    }
    else{
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

int bin_search(int v[], int l, int r, int k){
    int c;
    if(l > r){
        return (-1);
    }

    c = (l+r) / 2;

    if(k < v[c]){
        return (bin_search(v, l, c-1, k));
    }
    if(k > v[c]){
        return (bin_search(v, c+1, r, k));
    }

    return c;
}

void reverse_print(char *s){
    if(*s == '\0'){
        return;
    }
    reverse_print(s+1);
    printf("%c", *s);
    return;
}

void binary_r(int *array, int depth, int n){
    if(depth >= n){
        for(int i=0; i<n; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0; i<BASE; i++){
        array[depth] = i;
        binary_r(array, depth+1, n);
    }
}

void anagram_r(char *word, char *anagram, int *used, int length, int n){
    // termination condition
    if(n == length){
        printf(" %s\n", anagram);
        return;
    }

    for(int i=0; i<length; i++){
        if(used[i] == 0){
            used[i] = 1;
            anagram[n] = word[i];
            anagram_r(word, anagram, used, length, n+1);
            used[i] = 0;
        }
    }
}