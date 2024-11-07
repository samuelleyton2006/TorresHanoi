#include <stdio.h>
#include "jugar.h"
#include "solucionar.h"

void print_menu()
{
        puts("0. Menú");
        puts("1. Salir");
        puts("2. Jugar");
        puts("3. Ver solución");
}

int main()
{
        int opcion = 0;
        print_menu();

        int num;

        while (opcion != 1) {
                printf("> ");
                scanf("%d", &opcion);

                switch (opcion) {
                case 0:
                        print_menu();
                        break;
                case 2:
                        printf("Número de aros >> "); 
                        scanf("%d", &num);

                        jugar(num);
                        break;
                case 3:
                        printf("Número de aros >> "); 
                        scanf("%d", &num);

                        solucionar(num);
                        break;
                default:
                        break;
                }
                printf("\n");
        }


        return 0;
}
