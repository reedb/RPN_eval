//*****************************************************************************
//
// stack.cpp - Implements simple FILO storage system.
//
// Author:  Reed Bement,  2019/1/6
//
//    Notes:
//    ------
//
//
//*****************************************************************************

#include <stdlib.h>
#include <iostream>

#include "stack.h"

using namespace std;

void Stack::Push(double d)
{
    if (size < STACK_MAX) data[size++] = d;
    else {
        cout << "Error: stack full\n";
        exit(EXIT_FAILURE);
    }
}

double Stack::Pop(void) {

    if (size == 0) {
        cout << "Error: stack empty\n";
        exit(EXIT_FAILURE);
    }
    size--;
    return data[size];
}
