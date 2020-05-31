#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

const Data empty_stack = {.from_to = -1, .figure = -1, .flag = 0};

StackNode* newNode(Data data) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = ROOT;
    return stackNode;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, Data data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    // printf("{%d, %d} pushed to stack\n", data.from_to, data.figure);
}

Data pop(StackNode** root) {
    if (isEmpty(*root))
        return EMPTY_STACK;
    StackNode* temp = *root;
    *root = (*root)->next;
    Data popped = temp->data;
    free(temp);

    return popped;
}

Data peek(StackNode* root) {
    if (isEmpty(root))
        return EMPTY_STACK;
    return root->data;
}

void destroy_stack (StackNode** root) {
    Data result;
    do {
        result = pop(root);
    } while (result.from_to != empty_stack.from_to &&
             result.figure != empty_stack.figure );
}

// StackNode* root = ROOT;

// Data data1 = {.from_to = 10, .figure = 10};
// Data data2 = {.from_to = 20, .figure = 20};
// Data data3 = {.from_to = 30, .figure = 30};

// push(&root, data1);
// push(&root, data2);
// push(&root, data3);

// Data popped = pop(&root);

// printf("%d popped from stack\n", popped.figure);

// Data peeked = peek(root);

// printf("Top element is %d\n", peeked.figure);
// destroy_stack(&root);
// return 0;