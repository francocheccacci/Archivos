#include <stdio.h>
#include <stdlib.h>
#include "funcionesArchivos.h"



int main(){

    int opcion, res, id;
    float precioNuevo;

    do {

    printf("1- Crear archivo binario llamado productos.dat. \n");
    printf("2- Cargar nuevos productos. \n");
    printf("3- Listado de todos los productos. \n");
    printf("4- Consultar producto por id. \n");
    printf("5- Modificar precio de un producto \n");
    printf("6- Ordenar el archivo por ID. \n");
    printf("7- Eliminar duplicados. *ordena el archivo*.\n");
    printf("8- Finalizar \n");

    printf("Ingrese la opcion deseada: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            res = crearArchivoBinario();
                if (res == 0){
                    printf("\n El archivo no se ha podido generar\n");
                }else{
                    printf("\n El archivo se ha generado correctamente. \n");
                };

            break;
        case 2:
            res = cargarProductos();
            if(res == 0){
                printf("No se ha encontrado el archivo, intente nuevamente. \n");
            }
            continuar();
            break;
        case 3:
                res = listarProductos();
                if(res == 0){
                    printf("No existe el archivo. \n");
                }

            break;
        case 4:
                printf("Ingrese el id del producto deseado: ");
                scanf("%d", &id);
                printf("\n");
                res = consultarProducto(id);
                if(res == 0){
                    printf("El id ingresado no existe. \n");
                };
                printf("\n");
                continuar();
            break;
        case 5:
            printf("Ingrese el id del producto a modificar: ");
            scanf("%d", &id);
            printf("\nIngrese el precio: ");
            scanf("%f", &precioNuevo);

            res = cambiarPrecioProducto(id, precioNuevo);
            if(res == 0){
                printf("El id ingresado no existe. \n");
            };

            continuar();
            break;
        case 6:
            ordenarArchivoId();
            continuar();
            break;

        case 7:
            eliminarDuplicados();
            continuar();
            break;


        case 8:

            break;

        };
    }while(opcion != 8);

    return 0;
}
