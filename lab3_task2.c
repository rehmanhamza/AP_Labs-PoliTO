//
//  main.c
//  lab3_task2
//
//  Created by Hamza Rehman on 9/26/19.
//  Copyright © 2019 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 4
#define N 5

typedef struct{
    char name[MAX+1];
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

    int limit;
    while(fscanf(file, "%d", &limit) != NULL){
        printf("First line read successfully.\n\n");
    }

    RECTANGLE temp, *list;
    list = (int *) malloc (sizeof(limit));

    temp.x = 0.0;
    temp.y = 0.0;
    strcpy(temp.name, "NA");

    int i = 0;
    while(!feof(file)){
        fscanf(file, "%s %f %f", list[i].name, &list[i].x, &list[i].y);

        i++;

    }

    fclose(file);

    float area[N], perimeter[N];
    char rect_name[MAX][MAX+1];

    /*char **rect_name = malloc (limit/2 * sizeof(char *));
    for(int i=0; i<limit/2; i++){
        rect_name[i] = malloc (limit/2 * sizeof(char));
    }

    area = (float *) malloc ((limit/2) * sizeof(float));
    perimeter = (float *) malloc ((limit/2) * sizeof(float));*/

    int index = 0;
    for(int i=0; i<limit; i++){
        for(int j=i+1; j<limit; j++){
            if(strcmp(list[i].name, list[j].name) == 0){
                strcpy(rect_name[index], list[i].name);
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
    char temp_sort[MAX+1], area_sort[MAX][MAX+1], perimeter_sort[MAX][MAX+1];
    /*char *temp_sort = malloc (limit/2 * sizeof(char));
    char **area_sort = malloc (limit/2 * sizeof(char *));
    for(int i=0; i<limit/2; i++){
        area_sort = malloc (limit/2 * sizeof(char));
    }*/

    for(int i=0; i<index; i++){
        strcpy(area_sort[i], rect_name[i]); // after using ** Xcode gives error and won't copy the contents
        strcpy(perimeter_sort[i], rect_name[i]);
    }

    for(int i=0; i<index; i++){
        for(int j=i; j<index-1; j++){
            if(area[i] < area[j]){
                temp_var = area[i];
                area[i] = area[j];
                area[j] = temp_var;

                strcpy(temp_sort, area_sort[i]);
                strcpy(area_sort[i], area_sort[j]);
                strcpy(area_sort[j], temp_sort);
            }

            if(perimeter[i] < perimeter[j]){
                temp_var = perimeter[i];
                perimeter[i] = perimeter[j];
                perimeter[j] = temp_var;

                strcpy(temp_sort, perimeter_sort[i]);
                strcpy(perimeter_sort[i], perimeter_sort[j]);
                strcpy(perimeter_sort[j], temp_sort);
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
