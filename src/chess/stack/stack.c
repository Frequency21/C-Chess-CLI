#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* A simple stack implementation
 * to store player moves.
 */

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