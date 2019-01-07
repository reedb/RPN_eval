//*****************************************************************************
//
// integrate.cpp - Use the extended trapezoidal rule to calculate integrals.
//
// Author:  Reed Bement,  2019/1/6
//
//    Notes:
//    ------
//
//    From "Computational Physics" by Mark Newman
//    http://www-personal.umich.edu/~mejn/cp/chapters/int.pdf
//
//*****************************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <cassert>

#include "stack.h"
#include "eval_rpn.h"

using namespace std;

int main(void)
{
    printf("Start\n");
    Stack *s = new Stack;
    double d = 3.1415;
    s->Push(d);
    printf("Pop: %lf\n", s->Pop());
#ifdef fool

    EvalRPN *e = new EvalRPN;

    printf("New object");

    assert(e->DoEvalRPN((char*)"10 3 -") == 7.0);
    assert eval_rpn('10 3 -') == 7
    assert eval_rpn('12 3 /') == 4
    assert eval_rpn('1 2 /') == 0.5
    assert eval_rpn('4 2 pow') == 16
    assert eval_rpn('X 2 pow', 4) == 16
    assert eval_rpn('25 sqrt') == 5
    assert eval_rpn('10 3 5 + *') == eval_rpn('3 5 + 10 *')

DoEvalRPN(char *pszExpression, double x = 0.0)

#endif
    printf("Tests pass!");

    return 0;
}
