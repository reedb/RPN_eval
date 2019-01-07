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
#define _USE_MATH_DEFINES   // for M_PI
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

//*****************************************************************************
//
// HandleBinary - Handle binary operators.
//
// Paramaters:
//   pszVal - String pointer to current word being parsed.
//
// Returns - Nothing
//
//*****************************************************************************

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
// HandleUnary - Handle unary operators.
//
// Paramaters:
//   pszVal - String pointer to current word being parsed.
//
// Returns - Nothing
//
//*****************************************************************************

void EvalRPN::HandleUnary(char *pszWord)
{
    double dRes;
    double dOp1 = s.Pop();

    if (strcasecmp("sqrt", pszWord) == 0) dRes = sqrt(dOp1);
    if (strcasecmp("sin",  pszWord) == 0) dRes = sin(dOp1);
    if (strcasecmp("cos",  pszWord) == 0) dRes = cos(dOp1);

    s.Push(dRes);
}

//*****************************************************************************
//
// HandleConVar - Handle constant and variable operands.
//
// Paramaters:
//   pszVal - String pointer to current word being parsed.
//
// Returns - Nothing
//
//*****************************************************************************

void EvalRPN::HandleConVar(char *pszWord, double x)
{
    if (strcasecmp("pi", pszWord) == 0) s.Push(M_PI);
    if (strcasecmp("e",  pszWord) == 0) s.Push(M_E);
    if (strcasecmp("x",  pszWord) == 0) s.Push(x);
}

//*****************************************************************************
//
// Str2D - Convert a floating point string value into a double.
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
// DoEvalRPN - Evaluate a RPN expression.
//
// Paramaters:
//   pszExpression - Pointer to string containing RPN expression
//   x             - Optional parameter for expressions with variable x.
//
// Returns: Value of expression.
//
//*****************************************************************************

double EvalRPN::DoEvalRPN(const char *pszExpression, double x)
{
    if (strlen(pszExpression) > MAX_EXP_LEN) {
        cout << "Expression string to long. Max: " << MAX_EXP_LEN << "\n";
        exit(EXIT_FAILURE);
    }
    strncpy(szExp, pszExpression, MAX_EXP_LEN);
    char *pszWord = strtok(szExp, szDelimiter);
    while (pszWord != NULL) {
        if (strcasestr(szBinOp, pszWord) != NULL) HandleBinary(pszWord);
        else if (strcasestr(szUnaryOp, pszWord) != NULL) HandleUnary(pszWord);
        else if (strcasestr(szConVarOp, pszWord) != NULL) HandleConVar(pszWord, x);
        else s.Push(Str2D(pszWord));
        pszWord = strtok(NULL, szDelimiter);
    }
    return s.Pop();
}
