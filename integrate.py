#!/usr/bin/env python
import sys

import eval_rpn as e

'''

Use the extended trapezoidal rule to calculate integrals.
From "Computational Physics" by Mark Newman
http://www-personal.umich.edu/~mejn/cp/chapters/int.pdf

Default function: f(x) = x**4 - 2*x + 1

'''

# Default function (RPN format) and parameters.
#
fun_rpn = 'x 4 pow 2 x * - 1 +'
a       = 0.0
b       = 2.0
N       = 1000

def ExtTrapIntegral(fun_rpn, a, b, N):
    h  = (b - a) / N
    s = 0.5 * e.eval_rpn(fun_rpn, a) + 0.5 * e.eval_rpn(fun_rpn, b)
    for k in range(1, N):
        s += e.eval_rpn(fun_rpn, (a + k * h))
    return h*s

argc = len(sys.argv)
if (argc < 4) or (argc > 5):
    print
    print "Less than 3 arguments passed. Using defaults."
    print 'Usage: integrate "fun" lower upper [steps]'
    print "  fun     - Function in RPN. Default: " + '"' + fun_rpn + '"'
    print "  lower   - Lower limit. Default: " + str(a)
    print "  Upper   - Upper limit. Default: " + str(b)
    print "  [steps] - Optional number of steps. Default: " + str(N)
    print

# Parse user supplied arguments
#
if (argc >= 3):
    fun_rpn = sys.argv[1]
    a       = float(sys.argv[2])
    b       = float(sys.argv[3])
    if (argc > 4): N = int(sys.argv[4])

print "Integrating function (RPN format): " + '"' + fun_rpn + '"'
print "Lower limit: " + str(a)
print "Upper limit: " + str(b)
print "Number of steps: " + str(N)

print "Calculated: " +  str(ExtTrapIntegral(fun_rpn, a, b, N))
if (argc == 1): print "Exact value of default function: 4.4"


