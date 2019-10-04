//------------------------------------------------------------------------
// NAME: Georgi Lyubenov
// CLASS: XIb
// NUMBER: 10
// PROBLEM: #6
// FILE NAME: stack.c
// FILE PURPOSE:
// имплементация на stack 
// ...
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t size;
    size_t capacity;
    int *elements;
} stack;

void stack_init( stack *stack ){

    stack->size = 0;
    stack->elements = (int*)malloc(sizeof(int));
}

void stack_destroy( stack *stack ){

    free(stack);
}

int stack_empty( stack *stack ){

    return stack->size;
}
void stack_push( stack *stack, int n){

    stack->elements = (int*)realloc(stack->elements, (stack->size+1) * sizeof(int));
    stack->elements[stack->size] = n;
    stack->size++;
}

int stack_top( stack *stack ){

    return stack->elements[stack->size];
}

void stack_pop( stack *stack ){

    stack->elements = (int*)realloc(stack->elements, (--stack->size) * sizeof(int));
}

int main () {

    stack stack;
    stack_init(&stack);
    printf("stack is empty -> %d\n", stack_empty(&stack));

    stack_push(&stack, 1);
    //stack_push(&stack, 2);
    //stack_push(&stack, 3);

    printf("stack is empty -> %d\n", stack_empty(&stack));

    stack_pop(&stack);
    
    printf("top element in stack -> %d\n", stack_top(&stack));

    stack_destroy(&stack);

    return 0;
}
