#include "animation_vara.h"

int calcularLongAro(int dato)
{
        return 2 * dato + 3;
}

int varaT_calcularMitadAro(int dato)
{
        return dato + 1;
}

void varaT_inicializar(Vara_t *vara, int num_aros, int alto) 
{
        vara->num_aros = num_aros;
        vara->vara = malloc(sizeof(int) * alto);

        for (int i = 0; i < num_aros; i++)
                vara->vara[i] = num_aros - i - 1;

        vara->alto = alto;
}

void varaT_destruir(Vara_t *vara)
{
        free(vara->vara);
}

char *generar_aro(int x)
{
        char *aro = malloc(sizeof(char) * (calcularLongAro(x) + 1));
        strcpy(aro, "<");

        for (int i = 0; i < x; i++)
                strcat(aro, "-");

        strcat(aro, "-");

        for (int i = 0; i < x; i++)
                strcat(aro, "-");

        strcat(aro, ">");
        return aro;
}

void varaT_dibujar(Vara_t *vara, int fila_pos, int col_pos)
{
        vara->col_pos = col_pos;
        vara->fila_pos = fila_pos;

        int vacio = vara->alto - vara->num_aros + 1;

        for (int i = 0; i < vacio; i++)
                mvaddch(fila_pos + i, col_pos, '|');

        for (int i = 0; i < vara->num_aros; i++) {
                char *aro = generar_aro(vara->vara[vara->num_aros - i - 1]);
                mvaddstr(fila_pos + i + vacio, col_pos - varaT_calcularMitadAro(i), aro);

                free(aro);
        }
}

void varaT_quitar(Vara_t *vara)
{
        int vacio = vara->alto - vara->num_aros + 1;
        int fila_pos = vara->fila_pos + vacio;

        int dato = vara->vara[vara->num_aros - 1];

        for (int i = 0; i < 4; i++) {
                mvaddch(fila_pos, vara->col_pos, '+');
                refresh();
                usleep(100000);
                mvaddch(fila_pos, vara->col_pos, '-');
                refresh();
                usleep(100000);
        }

        for (int i = 0; i < calcularLongAro(dato); i++)
                mvaddch(fila_pos, vara->col_pos + i - varaT_calcularMitadAro(dato), ' ');

        mvaddch(fila_pos, vara->col_pos, '|');

        vara->num_aros--;
}

void varaT_agregar(Vara_t *vara, int dato)
{
        int vacio = vara->alto - vara->num_aros;
        int fila_pos = vara->fila_pos + vacio;

        char *aro = generar_aro(dato);

        mvaddstr(fila_pos, vara->col_pos - varaT_calcularMitadAro(dato), aro);

        free(aro);
        vara->num_aros++;
        vara->vara[vara->num_aros - 1] = dato;
}

int varaT_peek(Vara_t *vara)
{
        int dato = -1;
        if (vara->num_aros > 0)
                dato = vara->vara[vara->num_aros - 1];

        return dato;
}
