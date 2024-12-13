#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu()
{

    int op;
    printf("\n\t\tMenu\t\t\n");
    printf("1.Registrar libro\n2.Mostrar Lista de libros\n3.Busqueda de libro\n4.Actualizar estado del libro\n5.Eliminar Libro\n6.Salir\n");
    scanf("%d", &op);

    return op;
}

void registrarLibros(struct Libro libro[maxlib], int *indice)
{
    int len;
    int idValido;

    // Validar el ID del libro
    do
    {
        idValido = 1; // Asumimos que el ID es válido
        printf("Ingrese el Id del libro %d\n", *indice + 1);

        // Verificamos que se ingrese un número
        if (scanf("%d", &libro[*indice].id) != 1 || (libro[*indice].id <= 0))
        {
            printf("Error: Debe ingresar un numero para el ID.\n");
            idValido = 0; // ID no válido
            while (getchar() != '\n')
                ;     // Limpiar el buffer de entrada
            continue; // Volver a pedir el ID
        }

        // Verificar si el ID ya existe
        for (int i = 0; i < *indice; i++)
        {
            if (libro[i].id == libro[*indice].id)
            {
                printf("Error: El ID %d ya existe. Por favor, ingrese un ID unico.\n", libro[*indice].id);
                idValido = 0; // ID no válido
                break;        // Salir del bucle
            }
        }
    } while (!idValido); // Repetir hasta que se ingrese un ID válido

    printf("Ingrese el titulo del libro %d\n", *indice + 1);
    fflush(stdin);
    fgets(libro[*indice].titulo, 100, stdin);
    len = strlen(libro[*indice].titulo) - 1;
    libro[*indice].titulo[len] = '\0';
    printf("Ingrese el Autor del libro %d\n", *indice + 1);
    fflush(stdin);
    fgets(libro[*indice].Autor, 50, stdin);
    len = strlen(libro[*indice].Autor) - 1;
    libro[*indice].Autor[len] = '\0';

    // Validar el año del libro
    while (1)
    {
        printf("Ingrese el anio del libro %d\n", *indice + 1);
        if (scanf("%d", &libro[*indice].anio) == 1 && (libro[*indice].anio) > 0)
        {
            break; // Salimos del bucle si se ingresó un número
        }
        else
        {
            printf("Error: Debe ingresar un numero para el anio.\n");
            while (getchar() != '\n') // Limpiar el buffer
                ;
        }
    }

    char aux[10] = "Disponible";
    strcpy(libro[*indice].Estado, aux);
    len = strlen(libro[*indice].Estado) - 1;
    libro[*indice].Estado[len] = '\0';
}

void mostrarLibros(struct Libro libro[maxlib], int *n)
{
    printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for (int i = 0; i < *n; i++)
    {
        if (libro[i].id != 0)
        {
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libro[i].id, libro[i].titulo, libro[i].Autor, libro[i].anio, libro[i].Estado);
        }
    }
}

void buscarLibroID(struct Libro libro[maxlib], int *indice)
{
    int buscarId;
    int encontrado = 0;
    while (1)
    {
        printf("Ingresa el ID del libro que deseas buscar\n");
        if (scanf("%d", &buscarId) == 1 && buscarId > 0) // Verificar que sea un número positivo
        {
            break; // Salimos del bucle si se ingresó un número válido
        }
        else
        {
            printf("Error: Debe ingresar un número positivo para el ID.\n");
            while (getchar() != '\n') // Limpiar el buffer
                ;
        }
    }

    for (int i = 0; i < *indice; i++)
    {
        if (libro[i].id == buscarId)
        {
            printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libro[i].id, libro[i].titulo, libro[i].Autor, libro[i].anio, libro[i].Estado);
            encontrado = 1;
        }
        else
        {
            continue;
        }
    }

    if (!encontrado)
    {
        printf("No se encontro el libro con el ID: %d\n", buscarId);
    }
}

void buscarLibroTi(struct Libro libro[maxlib], int *indice)
{
    char buscarTi[100];
    printf("Ingresa el Titulo del libro que deseas buscar\n");
    fflush(stdin);
    fgets(buscarTi, 100, stdin);
    // Eliminar el salto de línea al final de buscarTi
    buscarTi[strcspn(buscarTi, "\n")] = 0;

    int encontrado = 0; // Variable para verificar si se encontró el libro

    for (int i = 0; i < *indice; i++)
    {
        if (strcmp(libro[i].titulo, buscarTi) == 0)
        { // Comparar cadenas correctamente
            printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libro[i].id, libro[i].titulo, libro[i].Autor, libro[i].anio, libro[i].Estado);
            encontrado = 1; // Se encontró el libro
        }
    }

    if (!encontrado)
    {
        printf("No se encontró el libro con el titulo: %s\n", buscarTi);
    }
}

void buscarLibro(struct Libro libro[maxlib], int *indice)
{
    int opc;

    while (1)
    {
        printf("Por que medio deseas buscar\n1. ID\n2. Titulo\n");
        if (scanf("%d", &opc) == 1)
        {
            // Si se ingresó un número correctamente
            if (opc == 1 || opc == 2)
            {
                break; // Salimos del bucle si la opción es válida
            }
            else
            {
                printf("Opción no valida. Por favor, elige 1 o 2.\n");
            }
        }
        else
        {
            // Si no se ingresó un número, limpiamos el buffer
            printf("Entrada no valida. Por favor, ingrese un numero.\n");
            while (getchar() != '\n')
                ; // Limpiar el buffer
        }
    }

    switch (opc)
    {
    case 1:
        printf("Medio de busqueda: ID\n");
        buscarLibroID(libros, indice);
        break;
    case 2:
        printf("Medio de busqueda Titulo\n");
        buscarLibroTi(libros, indice);
        break;
    default:
        printf("No hay esa opcion\n");
        break;
    }
}

void actulizarEstad(struct Libro libro[maxlib], int *indice)
{
    int buscarId;
    int encontrado = 0;
    int opc = 0;
    char aux1[10] = "Disponible";
    char aux2[10] = "Prestado";
    int len;
    while (1)
    {
        printf("Ingresa el ID del libro que deseas cambiar el estado\n");
        if (scanf("%d", &buscarId) == 1 && buscarId > 0)
        {
            // Si se ingresó un número correctamente, salimos del bucle
            break;
        }
        else
        {
            // Si no se ingresó un número, limpiamos el buffer
            printf("Entrada no válida. Por favor, ingrese un número.\n");
            while (getchar() != '\n')
                ; // Limpiar el buffer
        }
    }
    for (int i = 0; i < *indice; i++)
    {
        if (libro[i].id == buscarId)
        {
            // Solicitar el estado
            while (1)
            {
                printf("Elige el estado:\n1. Disponible\n2. Prestado\n");
                if (scanf("%d", &opc) == 1 && (opc == 1 || opc == 2))
                {
                    break; // Salimos del bucle si se ingresó 1 o 2
                }
                else
                {
                    printf("Entrada no válida. Por favor, elige 1 o 2.\n");
                    while (getchar() != '\n')
                        ; // Limpiar el buffer
                }
            }
            switch (opc)
            {
            case 1:
                printf("Estado: Disponible\n");
                strcpy(libro[i].Estado, aux1);
                break;
            case 2:
                printf("Estado: Prestado\n");
                strcpy(libro[i].Estado, aux2);
                break;
            default:
                printf("Ese estado no existe\n");
                break;
            }
            encontrado = 1;
        }
        else
        {
            continue;
        }
    }

    if (!encontrado)
    {
        printf("No se encontró el libro con el ID: %d\n", buscarId);
    }
}

void eliminarLib(struct Libro libro[maxlib], int *indice)
{
    int buscarId;
    int encontrado = 0;

    while (1)
    {
        printf("Ingresa el ID del libro que deseas eliminar\n");
        if (scanf("%d", &buscarId) == 1  && buscarId > 0)
        {
            break; // Salimos del bucle si se ingresó un número
        }
        else
        {
            printf("Entrada no válida. Por favor, ingrese un número.\n");
            while (getchar() != '\n')
                ; // Limpiar el buffer
        }
    }

    for (int i = 0; i < *indice; i++)
    {
        if (libro[i].id == buscarId)
        {
            // Mover los libros restantes hacia adelante
            for (int j = i; j < *indice - 1; j++)
            {
                libro[j] = libro[j + 1];
            }
            libro[*indice - 1].id = 0; // Opcional: limpiar el último libro
            (*indice)--;               // Decrementar el índice
            printf("Libro eliminado.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("No se encontró el libro con el ID: %d\n", buscarId);
    }
}