#ifndef STACK_H
#define STACK_H

#define EMPTY_STACK -1
#define ROOT NULL

struct StackNode {
    short data;
    struct StackNode* next;
};

struct StackNode* newNode(short data);
int isEmpty(struct StackNode* root);
void push(struct StackNode** root, short data);
short pop(struct StackNode** root);
short peek(struct StackNode* root);
void destroy_stack (struct StackNode** root);
#endif