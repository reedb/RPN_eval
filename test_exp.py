#!/usr/bin/env python

import eval_rpn as e

def f(x):
    return x**4 - 2*x + 1

expres = 'x 4 pow 2 x * - 1 +'

assert f(0.0) == e.eval_rpn(expres, 0.0)
assert f(1.0) == e.eval_rpn(expres, 1.0)
assert f(2.0) == e.eval_rpn(expres, 2.0)
print "Tests pass!"

#print e.eval_rpn('x 4 pow 2 x * - 1 +', 2)
