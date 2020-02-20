//
//  main.c
//  lab4_task2
//
//  Created by Hamza Rehman on 10/15/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 4
#define N 5

typedef struct{
    char *name;
    float x;
    float y;

} RECTANGLE;

float calculate_area(float a, float b, float c, float d);
float calculate_perimeter(float a, float b, float c, float d);

int main(int argc, const char * argv[]) {
    FILE *file;
    file = fopen("data.txt","r");
    if(file == NULL){
        perror("Error opening file:");
        return EXIT_FAILURE;
    }

    int n_tot;
    while(fscanf(file, "%d", &n_tot)){
        printf("First line read successfully.\n\n");
    }


    RECTANGLE *list;
    list = (RECTANGLE *) malloc (n_tot * sizeof(RECTANGLE));

    char name[MAX+1];

    int i = 0;
    while(!feof(file)){
        fscanf(file, "%s %f %f", name, &list[i].x, &list[i].y);

        list[i].name = strdup(name);
        if(list[i].name == NULL){
            perror("Error in memory allocation.");
            return EXIT_FAILURE;
        }

        i++;

    }

    fclose(file);
    int n = n_tot/2;

    float *area, *perimeter;
    //char rect_name[MAX][MAX+1];

    char **rect_name = malloc (n * sizeof(char *));
     for(int i=0; i<n; i++){
         rect_name[i] = malloc (n * sizeof(char));
     }

    area = (float *) malloc (n * sizeof(float));
    perimeter = (float *) malloc (n * sizeof(float));
    if(area == NULL || perimeter == NULL){
        perror("Error in memory allocation.");
        return EXIT_FAILURE;
    }

    int index = 0;
    for(int i=0; i<n_tot; i++){
        for(int j=i+1; j<n_tot; j++){
            if(strcmp(list[i].name, list[j].name) == 0){
                rect_name[index] = strdup(list[i].name); //strcpy(rect_name[index], list[i].name);
                area[index] = calculate_area(list[j].x, list[j].y, list[i].x, list[i].y);
                perimeter[index] = calculate_perimeter(list[j].x, list[j].y, list[i].x, list[i].y);

                index++;
            }
        }
    }

    for(int i=0; i<index; i++){
        printf("%s: area = %0.2f perimeter = %0.2f\n", rect_name[i], area[i], perimeter[i]);
    }

    printf("\n\n");

    float temp_var;
    //char temp_sort[MAX+1], area_sort[MAX][MAX+1], perimeter_sort[MAX][MAX+1];
    char *temp_sort = malloc (n * sizeof(char));
    char **area_sort = malloc (n * sizeof(char *)), **perimeter_sort = malloc (n* sizeof(char *));
    for(int i=0; i<n; i++){
        area_sort = malloc (n * sizeof(char));
        perimeter_sort = malloc (n * sizeof(char));
    }

    for(int i=0; i<index; i++){
        area_sort[i] = strdup(rect_name[i]);//strcpy(area_sort[i], rect_name[i]); // after using ** Xcode gives error won't copy the contents
        perimeter_sort[i] = strdup(rect_name[i]);//strcpy(perimeter_sort[i], rect_name[i]);
    }

    for(int i=0; i<index; i++){
        for(int j=i; j<index; j++){
            if(area[i] < area[j]){
                temp_var = area[i];
                area[i] = area[j];
                area[j] = temp_var;

                temp_sort = strdup(area_sort[i]); //strcpy(temp_sort, area_sort[i]);
                area_sort[i] = strdup(area_sort[j]); //strcpy(area_sort[i], area_sort[j]);
                area_sort[j] = strdup(temp_sort); //strcpy(area_sort[j], temp_sort);
            }

            if(perimeter[i] < perimeter[j]){
                temp_var = perimeter[i];
                perimeter[i] = perimeter[j];
                perimeter[j] = temp_var;

                temp_sort = strdup(perimeter_sort[i]); //strcpy(temp_sort, perimeter_sort[i]);
                perimeter_sort[i] = strdup(perimeter_sort[j]); //strcpy(perimeter_sort[i], perimeter_sort[j]);
                perimeter_sort[j] = strdup(temp_sort); //strcpy(perimeter_sort[j], temp_sort);
            }
        }
    }

    for(int i=0; i<index; i++){
        printf("%s: area = %0.2f\n", area_sort[i], area[i]);
    }
    printf("\n\n");
    for(int i=0; i<index; i++){
        printf("%s: perimeter = %0.2f\n", perimeter_sort[i], perimeter[i]);
    }

    // freeing dynamically allocated structures and arrays
    for(int i=0; i<n_tot; i++){
        free(list[i].name);
    }
    free(list);
    free(area);
    free(perimeter);
}

float calculate_area(float a, float b, float c, float d){

    float x3=c, y3=b, x4=a, y4=d, x=0.0, y=0.0, area = 0.0;
    x = sqrt((pow((a-x3),2)) + (pow((b-y3),2)));
    y = sqrt((pow((a-x4),2) + (pow((b-y4),2))));
    area = x*y;

    return area;
}

float calculate_perimeter(float a, float b, float c, float d){

    float x3=c, y3=b, x4=a, y4=d, x=0.0, y=0.0, perimeter = 0.0;
    x = sqrt((pow((a-x3),2)) + (pow((b-y3),2)));
    y = sqrt((pow((a-x4),2) + (pow((b-y4),2))));
    perimeter = 2*x+2*y;

    return perimeter;
}
