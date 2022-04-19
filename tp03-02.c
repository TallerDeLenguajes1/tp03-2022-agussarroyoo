#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char *V[5];

    for (int i = 0; i < 5; i++)
    {
        V[i] = (char *)malloc(sizeof(char) * 50);
        printf("Ingrese el nombre: ");
        gets(V[i]);
    }
    
    for (int j = 0; j < 5; j++)
    {
        puts(V[j]);
    }
}