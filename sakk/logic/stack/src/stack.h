#ifndef STACK_H
#define STACK_H
#define ROOT NULL
#define EMPTY_STACK empty_stack

typedef struct Data {
    // honnan, hová léptünk
    short from_to;
    // which figure was taken
    int figure;
    // ordinary move or
    // castle (white, black, queen/king-side)
    int flag : 3;
} Data;

typedef struct StackNode {
    Data data;
    struct StackNode* next;
} StackNode;

extern const Data empty_stack;

#define            ORDINARY 0
#define  W_KING_SIDE_CASTLE 1
#define W_QUEEN_SIDE_CASTLE 2
#define  W_KING_SIDE_CASTLE 3
#define W_QUEEN_SIDE_CASTLE 4

StackNode* newNode(Data data);
int isEmpty(StackNode* root);
void push(StackNode** root, Data data);
Data pop(StackNode** root);
Data peek(StackNode* root);
void destroy_stack (StackNode** root);
#endif