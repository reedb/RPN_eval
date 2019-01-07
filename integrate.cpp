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

double ExtTrapIntegral(char *fun_rpn, double a, double b, int N)
{
    EvalRPN *e = new EvalRPN;
    double h = (b - a) / (double) N;
    double s = 0.5 * e->DoEvalRPN(fun_rpn, a) + 0.5 * e->DoEvalRPN(fun_rpn, b);
    for (int k = 1; k < N; k++) {
        s += e->DoEvalRPN(fun_rpn, (a + k * h));
    }
    return h*s;
}

int main(void)
{
    // The following string is the RPN equivelent of x**4 - 2*x + 1
    //
    static char szExp[1024] = "x 4 pow 2 x * - 1 +";

    double dRes = ExtTrapIntegral(szExp, 0.0, 2.0, 1000);

    printf("Calculated: %lf\n", dRes);
    printf("Exact: 4.4\n");

    return 0;
}
