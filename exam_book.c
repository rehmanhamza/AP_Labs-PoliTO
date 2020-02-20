#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void duplicate_erase(char *str);

int main(){
    char *str = "aa;;;bbbab;";
    duplicate_erase(str);
}

void duplicate_erase(char *str){
    for(int i=0; i<strlen(str); i++){
        for(int j=i+1; str[j] != '\0'; j++){
            if(str[i] == str[j]){
                for(int k=j; str[k] != '\0'; k++){
                    str[k] = str[k+1];
                }
            }
        }
    }
}