//
//  main.c
//  lab4_task3_v2
//
//  Created by Hamza Rehman on 10/17/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15
#define N 4

typedef struct{
    int id;
    int laps;
    float *times;
    float average;
    char *name;
} ATHLETES;

void list_athlete(ATHLETES *, int n0);
void detail_athlete(ATHLETES *, int n1);
void best_athlete(ATHLETES *, int n2);

int main(int argc, const char * argv[]) {
    FILE *file;
    file = fopen("data.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    int n;
    while(fscanf(file, "%d", &n)){
        printf("1st line read successfully.\n\n");
    }
    
    ATHLETES *list;
    list = (ATHLETES *) malloc (n * sizeof(ATHLETES));
    
    if(list == NULL){
        perror("Error in memory allocation.");
        return EXIT_FAILURE;
    }
    
    char name[MAX];
    for(int i=0; i<n; i++){
        fscanf(file, "%s %d %d", name, &list[i].id, &list[i].laps);
        list[i].name = strdup(name);
        
        list[i].times = (float *) malloc (list[i].laps * sizeof(float));
        if(list[i].name == NULL || list[i].times == NULL){
            perror("Error in memory allocation.");
            return EXIT_FAILURE;
        }
        
        for(int j=0; j<list[i].laps; j++){
            fscanf(file, "%f", &list[i].times[j]);
        }
    }
    
    printf("\t\t\tAvailable Commands\n"
           "1. list\n"
           "2. details (gives details of athlete's)\n"
           "3. best\n"
           "4. stop (exit the program)\n");
    
    char cmd[N+1];
    do{
        printf("\nEnter command: ");
        scanf("%s", cmd);
        printf("\n");
        
        if(strcmp(cmd, "list") == 0){
            list_athlete(list, n);
        }
        
        if(strcmp(cmd, "best") == 0){
            best_athlete(list, n);
        }
        
        if(strcmp(cmd, "details") == 0){
            detail_athlete(list, n);
        }
        
    }while(strcmp(cmd, "stop") != 0);
    
    if(strcmp(cmd, "stop") == 0){
        printf("Program ended.\n");
        
        // freeing dynamically allocated memory
        for(int i=0; i<n; i++){
            free(list[i].name);
            free(list[i].times);
        }
        free(list);
    }

    return 0;
}

void list_athlete(ATHLETES *list, int n0){
    printf("Number of athletes : %d\n", n0);
    for(int i=0; i<n0; i++){
        printf("Name: %s #Id:%d #Laps:%d\n", list[i].name, list[i].id, list[i].laps);
    }
    
    printf("\n");
}

void detail_athlete(ATHLETES *list, int n1){
    char athlete_name[MAX];
    printf("Enter name:\n");
    scanf("%s", athlete_name);
    
    for(int i=0; i<n1; i++){
        if(strcmp(list[i].name, athlete_name) == 0){
            printf("#Id:%d #Laps:%d ", list[i].id, list[i].laps);
            printf("Times: ");
            for(int j=0; j<list[i].laps; j++){
                printf("%0.2f ", list[i].times[j]);
            }
            printf("\n");
        }
    }
    
    printf("\n");
}

void best_athlete(ATHLETES *list, int n2){
    for(int i=0; i<n2; i++){
        float sum = 0;
        for(int j=0; j<list[i].laps; j++){
            sum = sum + list[i].times[j];
            //list[i].average = (float) sum / list[i].laps;
        }
        list[i].average = (float) sum / list[i].laps;
    }
    
    // best athelete
    float best_avg = 10.0;
    int best_index = -1;
    for(int i=0; i<n2; i++){
        if(best_avg > list[i].average){
            best_avg = list[i].average;
            best_index = i;
        }
    }
    
    printf("Name:%s #Id:%d Laps:%d ", list[best_index].name, list[best_index].id, list[best_index].laps);
    printf("Times: ");
    for(int i=0; i<list[best_index].laps; i++){
        printf("%0.2f ", list[best_index].times[i]);
    }
    printf("(Average:%0.2f)\n\n", best_avg);
    
    printf("\n");
}
