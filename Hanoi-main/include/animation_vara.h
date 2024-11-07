#ifndef ANIMATION_VARA_H_INCLUDED
#define ANIMATION_VARA_H_INCLUDED

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
        int *vara;
        int num_aros;
        int alto;
        int fila_pos;
        int col_pos;
} Vara_t;

void varaT_inicializar(Vara_t *, int, int);
void varaT_dibujar(Vara_t *, int, int);
void varaT_destruir(Vara_t *);
void varaT_quitar(Vara_t *);
int varaT_peek(Vara_t *);
void varaT_agregar(Vara_t *, int);
int calcularLongAro(int);
int varaT_calcularMitadAro(int);

#endif
