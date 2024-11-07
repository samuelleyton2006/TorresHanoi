#include "animation_hanoi.h"

void vhanoiT_inicializar(VHanoi_t *vhanoi, int num_aros)
{
        vhanoi->num_aros = num_aros;

        for (int i = 0; i < 3; i++)
                vhanoi->varas[i] = malloc(sizeof(Vara_t));

        varaT_inicializar(vhanoi->varas[0], num_aros, num_aros);
        varaT_inicializar(vhanoi->varas[1], 0, num_aros);
        varaT_inicializar(vhanoi->varas[2], 0, num_aros);
}

void vhanoiT_destruir(VHanoi_t *vhanoi)
{
        for (int i = 0; i < 3; i++) {
                varaT_destruir(vhanoi->varas[i]);
                free(vhanoi->varas[i]);
        }
}

void vhanoiT_dibujar(VHanoi_t *vhanoi, int fila_pos, int col_pos)
{
        vhanoi->fila_pos = fila_pos;
        vhanoi->col_pos = col_pos;

        for (int i = 0; i < 3; i++)
                varaT_dibujar(vhanoi->varas[i], fila_pos, col_pos + i * (vhanoi->num_aros + 20));
}

void vhanoiT_mover(VHanoi_t *vhanoi, int origen, int destino)
{
        int dato = varaT_peek(vhanoi->varas[origen]);
        varaT_quitar(vhanoi->varas[origen]);
        varaT_agregar(vhanoi->varas[destino], dato);
}
