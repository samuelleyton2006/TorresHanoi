#include "stack.h"

void stackT_inicializar(Stack_t *stck)
{
        stck->top = NULL;
        stck->num = 0;
}

_Bool stackT_is_empty(Stack_t *stck)
{
        _Bool empty = true;
        if (stck->top != NULL)
                empty = false;

        return empty;
}

void stackT_pop(Stack_t *stck)
{
        if (!stackT_is_empty(stck)) {
                stck->num--;

                Snode_t *old = stck->top;
                stck->top = stck->top->next;
                free(old);
        }
}

void stackT_push(Stack_t *stck, int data)
{
        Snode_t *new = malloc(sizeof(Snode_t));
        new->data = data;
        new->next = stck->top;
        stck->top = new;

        stck->num++;
}

int stackT_peek(Stack_t *stck)
{
        int data = -1;

        if (!stackT_is_empty(stck))
                data = stck->top->data;

        return data;
}

void stackT_destruir(Stack_t *stck)
{
        while (stck->top != NULL)
                stackT_pop(stck);
}
