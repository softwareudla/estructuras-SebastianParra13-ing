#define maxlib 20

struct Libro
{
    int id;
    char titulo[100];
    char Autor[50];
    int anio;
    char Estado[10];
};

int menu();
void actulizarEstad(struct Libro libro[maxlib], int *indice);
void registrarLibros(struct Libro libro[maxlib], int *indice);
void mostrarLibros(struct Libro libro[maxlib], int *n);
void buscarLibroID(struct Libro libro[maxlib], int *indice);
void buscarLibroTi(struct Libro libro[maxlib], int *indice);
void buscarLibro(struct Libro libro[maxlib],int *indice);
void eliminarLib(struct Libro libro[maxlib], int *indice);