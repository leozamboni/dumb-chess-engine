#ifndef STACK_H
#define STACK_H

typedef struct node {
    unsigned int *cb;
    struct node *next;
}Node;

typedef struct stack {
    Node *top;
}Stack;

Stack *create_stack(void);
void push_stack(Stack *s, const unsigned int cb[]);
void pull_stack(Stack *s);
void output_stack(Stack *s);

#endif