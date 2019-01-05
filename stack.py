#!/usr/bin/env python

'''
Implement stack (LIFO) data structure.
The end of the list will hold the top element of the stack.
'''

class Stack:
     def __init__(self):
         self.stack = []

     def isEmpty(self):
         return self.stack == []

     def push(self, item):
         self.stack.append(item)

     def pop(self):
         return self.stack.pop()

if __name__ == '__main__':
    stack=Stack()
    assert stack.isEmpty() == True
    stack.push(666)
    assert stack.isEmpty() == False
    assert stack.pop() == 666
    assert stack.isEmpty() == True
    print "Tests pass!"
