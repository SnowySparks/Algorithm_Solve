#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int element;

typedef struct int_tStackNode {
    element data;
    struct int_tStackNode *next;
} Stacknode, *pStacknode;

typedef struct {
    int count;
    Stacknode *top;
} Stack, *pStack;


pStack init_Stack(int size) {
    pStack p=(pStack)malloc(sizeof(Stack));
    if (p==NULL) {
        return NULL;
    }
    p->count=0;
    p->top=NULL;
    return p;
}

int isEmptyStack(pStack p) {
    return (p->count==0)?1:0;
}


bool push(pStack p,element item) {
    pStacknode pNew=(pStacknode)malloc(sizeof(Stacknode));
    if (pNew==NULL) {
        printf("\n Appropriate memory allocation is not made. \n");
        return false;
    }
    pNew->data=item;
    pNew->next=p->top;
    p->top=pNew;
    p->count++;
    return true;
}

element pop(pStack p) {
    if (isEmptyStack(p)) {
        printf("\n stack is empty \n");
        while (p->top!=NULL) {
        pop(p);
        }
        free(p);
        exit(1);
    }
    else {
        element r=(p->top)->data;
        pStacknode dltPtr=p->top;
        p->top=(p->top)->next;
        --p->count;
        free(dltPtr);
        return r;
    }
}

element top(pStack p) {
    if (isEmptyStack(p)) {
        printf("\n stack is empty \n");
    } else {
        return p->top->data;
    }
}

void delete_stack(pStack p) {
    while (p->top!=NULL) {
        int_pop(p);
    }
    free(p);
}

void clearStack(pStack p) {
    while (p->top!=NULL) {
        int_pop(p);
    }
}

int CountStackItem(pStack p) {
    return p->count;
}
