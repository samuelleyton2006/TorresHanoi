#include "jugar.h"

void print_menu_jugar(int max_filas) {
        mvaddstr(max_filas - 5, 1, "p: seleccionar primero");
        mvaddstr(max_filas - 4, 1, "s: seleccionar segundo");
        mvaddstr(max_filas - 3, 1, "t: seleccionar tercero");
        mvaddstr(max_filas - 2, 1, "q: salir");
}

bool revisar_movimiento(VHanoi_t *vhanoi, int origen, int destino)
{
        bool movimiento_permitido = false;

        int dato = varaT_peek(vhanoi->varas[origen]);
        bool origen_con_dato = dato != -1;
        if (origen_con_dato) {
                int dato_debajo = varaT_peek(vhanoi->varas[destino]);

                if (dato_debajo == -1)
                        movimiento_permitido = true;
                else if (dato_debajo > dato)
                                movimiento_permitido = true;
        }

        return movimiento_permitido;
}

bool mover_aro(VHanoi_t *vhanoi, int origen)
{
        bool movimiento = false;
        int destino = origen;

        switch (getch()) {
        case 'd':
                destino = (origen + 1) % 3;
                break;
        case 'a':
                destino = (3 + origen - 1) % 3;
                break;
        default:
                break;
        }

        move(LINES - 6, 1);
        clrtoeol();

        if (origen != destino) {
                bool movimiento_valido = revisar_movimiento(vhanoi, origen, destino);

                if (movimiento_valido) {
                        vhanoiT_mover(vhanoi, origen, destino);
                        movimiento = true;
                }
        }

        return movimiento;
}

void jugar(int num_aros)
{
        initscr();
        cbreak();
        noecho();
        curs_set(0);
        clear();
        printw("Movimientos: 0");

        VHanoi_t *vhanoi = malloc(sizeof(VHanoi_t));
        vhanoiT_inicializar(vhanoi, num_aros);

        int fila_pos = (LINES - vhanoi->num_aros - 1) / 2;
        int col_pos = COLS / 3 - varaT_calcularMitadAro(vhanoi->num_aros);
        vhanoiT_dibujar(vhanoi, fila_pos, col_pos);
        print_menu_jugar(LINES);

        int jugadas = 0;
        char opcion = 'a';
        int origen = 0;
        bool movimiento_valido = false;

        while (opcion != 'q') {
                opcion = getch();

                switch (opcion) {
                case 'p':
                        origen = 0;
                        mvaddstr(LINES - 6, 1, "Primero");
                        movimiento_valido = mover_aro(vhanoi, origen);
                        break;
                case 's':
                        origen = 1;
                        mvaddstr(LINES - 6, 1, "Segundo");
                        movimiento_valido = mover_aro(vhanoi, origen);
                        break;
                case 't':
                        origen = 2;
                        mvaddstr(LINES - 6, 1, "Tercero");
                        movimiento_valido = mover_aro(vhanoi, origen);
                        break;
                default:
                        break;
                }

                if (movimiento_valido) {
                        jugadas++;
                        movimiento_valido = false;

                        move(0, 0);
                        clrtoeol();
                        printw("Movimientos: %d", jugadas);
                        refresh();
                }
        }

        vhanoiT_destruir(vhanoi);
        free(vhanoi);

        refresh();
        endwin();
}
