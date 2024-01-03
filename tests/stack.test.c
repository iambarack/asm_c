#include <stdio.h>
#include <stdlib.h>
#include "../stack.c"
#include "../include/mem_conf.h"

int main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    add();
    print();
    printf("\n");
    ifeq(3);
    push(44499);
    dup();
    pop();
    ifeq(1);
    print();

    // while(pop() != -1) pop();
    print();
    push(123);
    push(456);

    printf("freeing stack...\n");
    print();

    StackFree();
    printf("Freed. Goodbye!\n");

    return 0;
}