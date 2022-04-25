#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;

void cargarcliente(Cliente *cliente, int cant);
void productos(Producto *producto, int cant);
float costototal(Producto *producto);
void listar(Cliente *cliente, int cant);


int main() {
    srand(time(NULL));
    int cantclientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&cantclientes);

    Cliente *cliente;
    cliente=(Cliente *)(malloc(sizeof(Cliente) * cantclientes ));

    cargarcliente(cliente, cantclientes);
    listar(cliente,cantclientes);
}

void cargarcliente(Cliente *cliente, int cant) {
    
    for (int i = 0; i < cant; i++)
    {
        printf("\n-------------CLIENTE[%d]-------------\n",i+1);
        cliente->ClienteID = i;

        cliente->NombreCliente = (char *) malloc(sizeof(char) * 100);
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(cliente->NombreCliente);

        cliente->CantidadProductosAPedir = rand() % 6 +1;

        cliente->Productos = (Producto *)malloc(sizeof(Producto) * cliente->CantidadProductosAPedir);
        productos(cliente->Productos,cliente->CantidadProductosAPedir);
        cliente++;
    }
    
}

void productos(Producto *producto, int cant){

    int indice;

    for (int i = 0; i < cant; i++)
    {
        producto->ProductoID = i;
        producto ->Cantidad = rand()%6+1;
        indice = rand()%5;
        producto->TipoProducto=(char *)malloc(sizeof(char)*50);
        producto->TipoProducto = TiposProductos[indice];
        producto->PrecioUnitario = rand()%101 + 10;
        producto++;
    }
}
float costototal(Producto *producto) {
    return producto->PrecioUnitario * producto->Cantidad;
}

void listar(Cliente *cliente, int cant) {
    float total=0;
    for (int i = 0; i < cant; i++)
    {
        printf("\n-------------CLIENTE[%d]-------------\n",i+1);
        printf("ID: %d\n",cliente->ClienteID);
        printf("Nombre: ");
        puts(cliente->NombreCliente);
        printf("Cantidad de productos: %d\n",cliente->CantidadProductosAPedir);
        for (int j = 0; j < cliente->CantidadProductosAPedir; j++)
        {
            printf("\n-------------PRODUCTO[%d]-------------\n",j+1);
            printf("\nID: %d\n",cliente->Productos->ProductoID);
            printf("\nCantidad: %d\n",cliente->Productos->Cantidad);
            printf("\nTipo de Producto: ");
            puts(cliente->Productos->TipoProducto);
            printf("\nPrecio unitario: %2.f",cliente->Productos->PrecioUnitario);
            total += costototal(cliente->Productos);
            cliente->Productos++;
        }
        printf("\n\nCOSTO TOTAL: %2.f\n\n",total);
        printf("\n\n---------------------------------------------------------------\n\n");
        cliente++;
    }
}



