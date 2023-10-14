#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node* next;
};

struct node* Push(struct node* stack, int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = stack;
    return tmp;
}

struct node* Pop(struct node* stack){
    if(stack == NULL){
        return NULL;
    }
    struct node* tmp = stack->next;
    free(stack);
    return tmp;
}

int Top(struct node* stack){
    if(stack == NULL){
        return INT_MIN;
    }

    return stack->data;
}

int main(int argc, char** argv){
    struct node* stack_head = NULL;
    printf("Value on top of stack: %d\n", Top(stack_head)); // 4
    stack_head = Push(stack_head, 1); // 1
    printf("Value on top of stack: %d\n", Top(stack_head)); // 4
    stack_head = Push(stack_head, 2); // 2 1
    printf("Value on top of stack: %d\n", Top(stack_head)); // 4
    stack_head = Push(stack_head, 3); // 3 2 1
    printf("Value on top of stack: %d\n", Top(stack_head)); // 4
    stack_head = Push(stack_head, 4); // 4 3 2 1

    printf("Value on top of stack: %d\n", Top(stack_head)); // 4
    stack_head = Pop(stack_head); // 3 2 1

    printf("Value on top of stack: %d\n", Top(stack_head)); // 3
    stack_head = Pop(stack_head); // 2 1

    printf("Value on top of stack: %d\n", Top(stack_head)); // 2
    stack_head = Pop(stack_head); // 1

    printf("Value on top of stack: %d\n", Top(stack_head)); // 1
    stack_head = Pop(stack_head); // NULL
    
    printf("Value on top of stack: %d\n", Top(stack_head)); // ?
    stack_head = Pop(stack_head); // NULL
    printf("Value on top of stack: %d\n", Top(stack_head)); // ?

    return 0;
}