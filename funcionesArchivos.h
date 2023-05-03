
#ifndef FUNCIONESARCHIVOS_H_INCLUDED
#define FUNCIONESARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 40

typedef struct {
    int id;
    char descripcion[TAM];
    float precio;
}t_product;

int crearArchivoBinario();
int cargarProductos();
int listarProductos();
int consultarProducto(int codigo);
int cambiarPrecioProducto(int id,float precioN);
int ordenarArchivoId();
int contarRegistros();
void continuar();

#endif // FUNCIONESARCHIVOS_H_INCLUDED
