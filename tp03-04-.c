#include <stdio.h>
#include <stdlib.h>

int main() {

    char **nombres;
    int cant;

    printf("Ingrese la cantidad de nombres a anotar: ");
   
    scanf("%d", &cant);

    nombres = (char **)malloc(sizeof(char *) * cant);

    for (int i = 0; i < cant; i++)
    {
        nombres[i] = (char *)malloc(sizeof(char) * 50);
        printf("\nIngrese el nombre: "); 
        fflush(stdin);
        gets(nombres[i]);
    }
    for (int j = 0; j < cant; j++)
    {
        puts(nombres[j]);
    }
    for (int h = 0; h<cant; h++)
    {
        free(nombres[h]);
    }
    free(nombres);
    

}