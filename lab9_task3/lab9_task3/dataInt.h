//
//  dataInt.h
//  lab9_task3
//
//  Created by Hamza Rehman on 1/12/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#ifndef _DATA_INCLUDED
#define _DATA_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 20

typedef int data_t;

int readData (FILE *, data_t *);
void writeData (FILE *, data_t);
int compare (data_t, data_t);

#endif
