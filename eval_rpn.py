#!/usr/bin/env python
import math  as m
import stack as s

'''
Implementation of a simple Reverse Polish Noation (RPN) expression
parser/evaluator.
'''

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

if __name__ == '__main__':
    assert eval_rpn('10 3 -') == 7
    assert eval_rpn('12 3 /') == 4
    assert eval_rpn('1 2 /') == 0.5
    assert eval_rpn('4 2 pow') == 16
    assert eval_rpn('X 2 pow', 4) == 16
    assert eval_rpn('25 sqrt') == 5
    assert eval_rpn('10 3 5 + *') == eval_rpn('3 5 + 10 *')
    print "Tests pass!"
