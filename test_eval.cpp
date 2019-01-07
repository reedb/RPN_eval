//*****************************************************************************
//
// test_eval.cpp - Test EvalRPN::DoEvalRPN.
//
// Author:  Reed Bement,  2019/1/6
//
//    Notes:
//    ------
//
//*****************************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <cassert>

#include "stack.h"
#include "eval_rpn.h"

using namespace std;

void assert_eval(const char *pszExpression, double dShouldBe, double x = 0.0)
{
    EvalRPN *e = new EvalRPN;
    double dRes = e->DoEvalRPN(pszExpression, x);
    assert(dRes == dShouldBe);
}

int main(void)
{
    printf("Starting test.");
    assert_eval("x 4 pow 2 x * - 1 +", 1.0,  0.0); printf(".");
    assert_eval("x 4 pow 2 x * - 1 +", 0.0,  1.0); printf(".");
    assert_eval("x 4 pow 2 x * - 1 +", 13.0, 2.0); printf(".");
    assert_eval("X 2 pow", 16.0, 4.0); printf(".");
    assert_eval("10 3 -", 7.0); printf(".");
    assert_eval("12 3 /", 4.0); printf(".");
    assert_eval("1 2 /", 0.5); printf(".");
    assert_eval("4 2 pow", 16.0); printf(".");
    assert_eval("25 sqrt", 5.0); printf(".");
    printf("\nTests pass!\n");

    return 0;
}
