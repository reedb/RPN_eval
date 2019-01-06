#!/usr/bin/env python
import math  as m
import eval_rpn as e

'''

Use the extended trapezoidal rule to calculate integrals.
From "Computational Physics" by Mark Newman
http://www-personal.umich.edu/~mejn/cp/chapters/int.pdf

'''
def f(x):
    return x**4 - 2*x + 1

N = 5
a = 0.0
b = 2.0
h = (b-a)/N

s = 0.5*f(a) + 0.5*f(b)
for k in range(1,N):
    s += f(a+k*h)

print(h*s)



if __name__ == '__main__':
#    assert eval_rpn('10 3 5 + *') == eval_rpn('3 5 + 10 *')
#    qsimp("", 0, 0)
    print "Tests pass!"
