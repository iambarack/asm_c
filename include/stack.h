// struct stack
// {
    
// };

//first: simple stack implementation

#ifndef STACK_H
#define STACK_H

#define LIMIT_1KB kilobyte

int push(int); // return:status
int pop(); //return: popped | -1
int add(); //return: sum | -1
int ifeq(int); // check top n jump to next stack if not return:status
int jump(int); // jump to addr return:status
int print(); //return: status
int dup(); //return: status


#endif