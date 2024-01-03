#include <stdlib.h>
#include "include/stack.h"
#include "include/mem_conf.h"
#include <stdio.h>

// dynamic memory
// LIFO (Last-in First-out)
struct node {
    int data;
    struct node* next;
};

struct node* head;

int push(int token){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("PUSH(%d)\n", token);
    if (newNode == NULL)
    {
        return -1;
    }
    else
    {
        newNode->data = token;
        if(head == NULL)
        {
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head; //push the head
        }
        head = newNode; // LIFO
    }
    return 0;
}  // return:status (0 : -1)
int pop(){
    int pop;
    struct node* ptr;

    if(head == NULL) return -1;
    else
    {
        pop = head->data;
        ptr = head;
        head = head->next;
        printf("POP(%d)\n", pop);
        free(ptr);
        return pop;
    } 
}   // return: popped | -1

void StackFree() {
    // int n = pop();
    // while (n != -1)
    // {
    //     n = pop();
    // }
    struct node *ptr;
    while (head != NULL)
    {
        ptr = head;
        head = head->next;
        free(ptr);
        /* code */
    }    
    //free(ptr);
}
int add(){
    if(head == NULL || head->next == NULL) return -1;
    int sum = pop() + pop();
    push(sum);
    printf("ADD(%d)\n", sum);

    return sum;
}   // return: sum | -1
int ifeq(int addr){
    if(head == NULL) return -1;
    if(head->data == 0) return 0;
    else
    {
        for (int i = 0; i < addr; i++)
        {
           pop();
        }
        printf("ifeq(%d)\n", head ? head->data : -1);

        return head ? head->data : 1;
    }
} // check top n jump to next stack if not return:status
int jump(int addr){
    if(head == NULL) return -1;
    else
    {
        for (int i = 0; i < addr; i++)
        {
            pop(); //TODO: check if exceeds stack size
        }
        printf("jump(%d)\n", head ? head->data : -1);

        return head ? head->data : 0;   
    }
} // jump to addr return:status
int print(){
    struct node* temp;
    temp = head;
    if(temp == NULL)
    {
        return -1;
    }
    else
    {
        printf("[\n");

        while (temp !=NULL)
        {
            printf(" addr:%p->%d\n", &temp->data, temp->data);
            temp = temp->next;
        }
    }
    printf("]\n");

    return 0;
}   // return: status
int dup() {
    if(head == NULL) return -1;
    else
    {
        struct node *d = (struct node *)malloc(sizeof(struct node));
        if (d == NULL)
        {
            return -1;
        }
        else
        {
            d->data = head->data;
            printf("dup(%d)\n", head ? head->data : -1);

            d->next = head; // push the head
            head = d; // LIFO
        }
        return 0;
    }
}   // return: status
