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
#include <cstdio>
#include <string.h>
#include <math.h>
#include <iostream>

#include "stack.h"
#include "eval_rpn.h"

using namespace std;

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

const char szDelimiter[] = " ";
const char szBinOp[] = "- + * / % pow";
const char szUnaryOp[] = "sqrt sin cos";
const char szConVarOp[] = "pi e x";

#ifdef fool

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

#endif

void EvalRPN::HandleBinary(char *pszWord)
{
    double dRes;
    double dOp1 = s.Pop();
    double dOp2 = s.Pop();

    if (strcasecmp("-",   pszWord) == 0) dRes = dOp2 - dOp1;
    if (strcasecmp("+",   pszWord) == 0) dRes = dOp2 + dOp1;
    if (strcasecmp("*",   pszWord) == 0) dRes = dOp2 * dOp1;
    if (strcasecmp("/",   pszWord) == 0) dRes = dOp2 / dOp1;
    if (strcasecmp("%",   pszWord) == 0) dRes = fmod(dOp2, dOp1);
    if (strcasecmp("pow", pszWord) == 0) dRes = pow(dOp2, dOp1);

    s.Push(dRes);
}

//*****************************************************************************
//
// EvalRPN::Str2D() - Convert a floating point string value into a double.
//
// Paramaters:
//   pszVal - Pointer to  a floating point string value.
//
// Returns: Value of floating point string.
//
//*****************************************************************************
double EvalRPN::Str2D(char *pszVal)
{
    double dRes;
    if (sscanf(pszVal, "%lf", &dRes) == 1) return dRes;
    cout << "Error: converting " << pszVal << " to double\n";
    exit(EXIT_FAILURE);
}

//*****************************************************************************
//
// EvalRPN::eval_rpn() - Evaluate a RPN expression.
//
// Paramaters:
//   pszExpression - Pointer to string containing RPN expression
//   x             - Optional parameter for expressions with variable x.
//
// Returns: Value of expression.
//
//*****************************************************************************

double EvalRPN::eval_rpn(char *pszExpression, double x = 0.0)
{
    char *pszWord = strtok(pszExpression, szDelimiter);
    while (pszWord != NULL) {
        if (strcasestr(szBinOp, pszWord) != NULL) HandleBinary(pszWord);
        else if (strcasestr(szUnaryOp, pszWord) != NULL) {
        }
        else if (strcasestr(szUnaryOp, pszWord) != NULL) {
        }
        else s.Push(Str2D(pszWord));
        pszWord = strtok(NULL, szDelimiter);
    }
    return s.Pop();
}
