#ifndef STACK_H
#define STACK_H
#define ROOT NULL
#define EMPTY_STACK empty_stack

typedef struct Data {
    // piece starting and destination square
    // where (a->'1', ... h->'7'), so
    // a move like c2 to f5 is encoded to 3255.
    short from_to;
    // which figure was taken
    int figure;
    // ordinary move or
    // promotion or
    // castle (white, black, queen/king-side)
    unsigned int flag : 3;
} Data;

typedef struct StackNode {
    Data data;
    struct StackNode* next;
} StackNode;

extern const Data empty_stack;

// flag values
#define            ORDINARY 0
#define             PROMOTE 1
#define  W_KING_SIDE_CASTLE 2
#define W_QUEEN_SIDE_CASTLE 3
#define  B_KING_SIDE_CASTLE 4
#define B_QUEEN_SIDE_CASTLE 5

StackNode* newNode(Data data);
int isEmpty(StackNode* root);
void push(StackNode** root, Data data);
Data pop(StackNode** root);
Data peek(StackNode* root);
void destroy_stack (StackNode** root);
#endif