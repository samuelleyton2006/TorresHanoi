#ifndef HANOI_H_INCLUDED
#define HANOI_H_INCLUDED

#include "stack.h"
#include "animation_hanoi.h" // :(
#include <stdio.h>

typedef struct 
{
        int fichas_movidas;
        int num_aros;
        Stack_t *varas[3];
        VHanoi_t *vhanoi;
} Hanoi_t;

void hanoiT_inicializar(Hanoi_t *, int, VHanoi_t *);
void hanoiT_mover_aro(Hanoi_t *, int, int);
void hanoiT_solucionar(Hanoi_t *);
void hanoiT_destruir(Hanoi_t *);

#endif
