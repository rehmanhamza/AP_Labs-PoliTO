//
//  dataInt.c
//  lab9_task3
//
//  Created by Hamza Rehman on 1/12/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#include <stdio.h>
#include "dataInt.h"

int
readData (
          FILE *fp,
          data_t *data
          )
{
    int retValue;
    
    retValue = fscanf (fp, "%d", data);
    
    return (retValue);
}


void
writeData (
           FILE *fp,
           data_t data
           )
{
    fprintf(fp, "%d\n", data);
    
    return;
}


int
compare (
         data_t d1,
         data_t d2
         )
{
    if (d1 < d2) {
        return (-1);
    } else {
        if (d1 == d2) {
            return (0);
        } else {
            return (1);
        }
    }
}
