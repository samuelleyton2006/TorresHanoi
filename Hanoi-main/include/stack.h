#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
        int data;
        void *next;
} Snode_t;

typedef struct
{
        Snode_t *top;
        int num;
} Stack_t;

void stackT_inicializar(Stack_t *);
_Bool stackT_is_empty(Stack_t *);
void stackT_pop(Stack_t *);
void stackT_push(Stack_t *, int);
int stackT_peek(Stack_t *);
void stackT_destruir(Stack_t *);
#endif

