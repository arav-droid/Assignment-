/**
 * @file stack_array.c
 * @brief Stack Implementation using Array in C
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("[ERROR] Stack Overflow! Cannot push %d. Capacity of %d reached.\n", value, MAX_SIZE);
        return;
    }
    s->items[++(s->top)] = value;
    printf("[SUCCESS] Pushed %d onto the stack.\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("[ERROR] Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    int poppedValue = s->items[(s->top)--];
    printf("[SUCCESS] Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("[WARNING] Stack is empty! No element to peek.\n");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("[INFO] Stack is empty.\n");
        return;
    }
    printf("\nCurrent Stack (Top to Bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("| %2d |\n", s->items[i]);
    }
    printf("------\n\n");
}

int main() {
    Stack s;
    initStack(&s);

    printf("=========================================\n");
    printf("   STACK OPERATIONS USING FIXED ARRAY    \n");
    printf("=========================================\n\n");

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    
    // Overflow test
    push(&s, 60); 

    display(&s);

    printf("Top element (PEEK): %d\n\n", peek(&s));

    pop(&s);
    pop(&s);

    display(&s);

    pop(&s);
    pop(&s);
    pop(&s);

    // Underflow test
    pop(&s);

    return 0;
}
