//
//  treePrivate.h
//  lab9_task3
//
//  Created by Hamza Rehman on 1/12/20.
//  Copyright © 2020 Hamza Rehman. All rights reserved.
//

#ifndef _TREE_PRIVATE_INCLUDED
#define _TREE_PRIVATE_INCLUDED

#include "treePublic.h"

struct node {
    data_t val;
    struct node *left;
    struct node *right;
};

#endif
