#!/usr/bin/env python

import eval_rpn as e

'''

Use the extended trapezoidal rule to calculate integrals.
From "Computational Physics" by Mark Newman
http://www-personal.umich.edu/~mejn/cp/chapters/int.pdf

def f(x): return x**4 - 2*x + 1

'''

# The following string is the RPN equivelent of above.
#
fun_rpn = 'x 4 pow 2 x * - 1 +'

def ExtTrapIntegral(fun_rpn, a, b, N):
    h = (b - a) / N
    s = 0.5 * e.eval_rpn(fun_rpn, a) + 0.5 * e.eval_rpn(fun_rpn, b)
    for k in range(1, N):
        s += e.eval_rpn(fun_rpn, (a + k * h))
    return h*s

print "Calculated: " +  str(ExtTrapIntegral(fun_rpn, 0.0, 2.0, 1000))
print "Exact: 4.4"


