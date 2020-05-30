#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct StackNode* newNode(short data)
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = ROOT;
    return stackNode;
}

int isEmpty(struct StackNode* root)
{
    return !root;
}

void push(struct StackNode** root, short data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

short pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return EMPTY_STACK;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    short popped = temp->data;
    free(temp);

    return popped;
}

short peek(struct StackNode* root)
{
    if (isEmpty(root))
        return EMPTY_STACK;
    return root->data;
}

void destroy_stack (struct StackNode** root) {
    int result;
    do
    {
        result = pop(root);
    } while (result != EMPTY_STACK);
}

// struct StackNode* root = ROOT;

// push(&root, 10);
// push(&root, 20);
// push(&root, 30);

// printf("%d popped from stack\n", pop(&root));

// printf("Top element is %d\n", peek(root));
// destroy_stack(&root);