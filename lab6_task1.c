#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct word{
    char *word;
    int count;
    struct word *next;
}word_list;

word_list *readFile(FILE *file);
word_list *wordFind(word_list *head, char *word);
void print_list(word_list *head);

int main(){
    word_list *head = NULL;
    FILE *file;
    file = fopen("text.txt", "r");

    head = readFile(file);
    fclose(file);

    print_list(head);
    return 0;

}

word_list *readFile(FILE *file){
    word_list *temp, *head = NULL;
    char buffer[MAX];

    while(fscanf(file, "%s", buffer) != EOF){
        for(int i=0; i<strlen(buffer); i++){
            buffer[i] = tolower(buffer[i]);
        }
        temp = wordFind(head, buffer);
        if(temp != NULL){
            temp->count++;
        }
        else{
            temp = (word_list *) malloc (sizeof(word_list));
            temp->word = strdup(buffer);
            temp->count = 1;
            temp->next = head;
            head = temp;
        }
    }
    return head;
}

word_list *wordFind(word_list *head, char *word){
    word_list *temp = head;
    
    while(temp != NULL){
        if(strcmp(temp->word, word) == 0){
            return temp;
        }
        else{
            temp = temp->next;
        }
    }
    return NULL;
}

void print_list(word_list *head){
    word_list *temp = head;
    while(temp != NULL){
        printf("%s %d\n", temp->word, temp->count);
        temp = temp->next;
    }
}