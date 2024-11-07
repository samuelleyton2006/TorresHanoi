#include "hanoi.h"

void hanoiT_inicializar(Hanoi_t* hanoi, int num_aros, VHanoi_t *vhanoi)
{
        hanoi->fichas_movidas = 0;
        hanoi->num_aros = num_aros;
        hanoi->vhanoi = vhanoi;

        for (int i = 0; i < 3; i++) {
                hanoi->varas[i] = malloc(sizeof(Stack_t));
                stackT_inicializar(hanoi->varas[i]);
        }

        for (int i = num_aros - 1; i >= 0; i--)
                stackT_push(hanoi->varas[0], i);
}

void mover_tres(Hanoi_t *hanoi, int inicio, int fin)
{

}

void solucionar(Hanoi_t *hanoi, int objetivo, int vara)
{
        if (objetivo == 1) {
                hanoiT_mover_aro(hanoi, vara, (vara + 2) % 3);

                solucionar(hanoi, 3, (vara + 2) % 3);
        } else if (objetivo == 3) {
                mover_tres(hanoi, vara, (vara + 2) % 3);

                solucionar(hanoi, objetivo + 1, (vara + 2) % 3);
        } else if (objetivo == hanoi->num_aros + 1) {
                return;
        } else {
                solucionar(hanoi, 1, vara);
        }
}

void hanoiT_solucionar(Hanoi_t *hanoi)
{
        if (hanoi->num_aros & 1)
                solucionar(hanoi, 3, 0);
        else
                solucionar(hanoi, 3, 2);
}

void hanoiT_mover_aro(Hanoi_t *hanoi, int inicio, int fin)
{
        hanoi->fichas_movidas++;
        int dato = stackT_peek(hanoi->varas[inicio]);
        stackT_pop(hanoi->varas[inicio]);
        stackT_push(hanoi->varas[fin], dato);
}

void hanoiT_destruir(Hanoi_t *hanoi) {
        for (int i = 0; i < 3; i++) {
                stackT_destruir(hanoi->varas[i]);
                free(hanoi->varas[i]);
        }
}
