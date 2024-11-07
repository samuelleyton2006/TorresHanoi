#include "solucionar.h"
#include "animation_hanoi.h"
#include "hanoi.h"

void solucionar(int num_aros) 
{
        initscr();
        cbreak();
        noecho();
        curs_set(0);
        clear();

        VHanoi_t *vhanoi = malloc(sizeof(VHanoi_t));
        vhanoiT_inicializar(vhanoi, num_aros);
        Hanoi_t *hanoi = malloc(sizeof(Hanoi_t));
        hanoiT_inicializar(hanoi, num_aros, vhanoi);

        int fila_pos = (LINES - vhanoi->num_aros - 1) / 2;
        int col_pos = COLS / 3 - varaT_calcularMitadAro(vhanoi->num_aros);
        vhanoiT_dibujar(vhanoi, fila_pos, col_pos);
        printw("Movimientos: 0");

        hanoiT_solucionar(hanoi);

        vhanoiT_destruir(vhanoi);
        free(vhanoi);
        hanoiT_destruir(hanoi);
        free(hanoi);

        getch();

        refresh();
        endwin();
}
