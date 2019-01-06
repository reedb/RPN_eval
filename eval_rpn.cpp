//*****************************************************************************
//
// eval_rpn.cpp - Implementation of a simple Reverse Polish Noation (RPN)
//                 expression parser/evaluator.
//
// Author:  Reed Bement,  2019/1/6
//
//    Notes:
//    ------
//
//*****************************************************************************

#include <stdlib.h>
#include <math.h>

#include "stack.h"
#include "eval_rpn.h"

using namespace std;

#ifdef fool

def eval_rpn(expression, x = 0):
    """ Evaluate a reverse polish notation expression. """

    stack = s.Stack()

    for word in expression.lower().split(' '):
        if word in ['-', '+', '*', '/', '%', 'pow']: # binary operators
            op1 = stack.pop()
            op2 = stack.pop()
            if word=='-'  : result = op2 - op1
            if word=='+'  : result = op2 + op1
            if word=='*'  : result = op2 * op1
            if word=='/'  : result = op2 / op1
            if word=='%'  : result = op2 % op1
            if word=='pow': result = m.pow(op2, op1)
            stack.push(result)
        elif word in ['sqrt', 'sin', 'cos']: # unary operators
            op1 = stack.pop()
            if word=='sqrt': result = m.sqrt(op1)
            if word=='sin' : result = m.sin(op1)
            if word=='cos' : result = m.cos(op1)
            stack.push(result)
        elif word in ['pi', 'e', 'x']: # constants, variables
            if word=='pi' : stack.push(m.pi)
            if word=='e'  : stack.push(m.e)
            if word=='x'  : stack.push(x)
        else:
            stack.push(float(word))

    return stack.pop()
#endif

//*****************************************************************************
//
// EvalRPN::eval_rpn() - Evaluate a RPN expression.
//
// Paramaters - None.
//
// Returns - None.
//
//*****************************************************************************

double EvalRPN::eval_rpn(char *expression, double x = 0.0)
{
    s.Pop();
    return 0.0;
}
