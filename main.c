#include <stdio.h>
#include "funciones.h"

int main()
{
    struct Libro libros[maxlib];
    int opc;
    int i = 0;
    
    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            printf("Entro caso 1\n");
            registrarLibros(libros, &i);
            i++;
            break;
        case 2:
            printf("Entro caso 2\n");
            mostrarLibros(libros, &i);
            break;
        case 3:
            printf("Entro caso 3\n");
            buscarLibro(libros, &i);
            break;
        case 4:
            printf("Entro caso 4\n");
            actulizarEstad(libros, &i);
            break;
        case 5:
            printf("Entro caso 5\n");
            eliminarLib(libros, &i);
            break;
        case 6:
            break;
        default:
            printf("Esa opcion no se encuentra en el menu");
            break;
        }
        if (i > maxlib)
        {
            i = i - 1;
            printf("No se puede agregar mas de 20 libros");
        }
    } while (opc != 6);

    return 0;
}