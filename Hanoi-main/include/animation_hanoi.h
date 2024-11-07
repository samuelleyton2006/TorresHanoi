#ifndef ANIMATION_HANOI_INCLUDED
#define ANIMATION_HANOI_INCLUDED

#include <curses.h>
#include "animation_vara.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
        Vara_t *varas[3];
        int num_aros;
        int fila_pos;
        int col_pos;
} VHanoi_t;

void vhanoiT_inicializar(VHanoi_t *, int);
void vhanoiT_destruir(VHanoi_t *);
void vhanoiT_dibujar(VHanoi_t *, int, int);
void vhanoiT_mover(VHanoi_t *, int, int);

#endif
