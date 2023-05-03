#include "funcionesArchivos.h"
#define NOMBRE_ARCHIVO "E:\\progra1\\ejercicios\\ArchivosBinarios\\productos.bin"
#include <conio.h>

void continuar(){
    printf("Presione una tecla para continuar \n");
    getch();
};

int contarRegistros(){
    FILE* p_archivo_bin;
    int resultado = 0;
    p_archivo_bin = fopen(NOMBRE_ARCHIVO, "rb");
     if (p_archivo_bin == NULL) {
        printf("No se ha encontrado el archivo. \n");
        return -1;
    }

    fseek(p_archivo_bin, 0, SEEK_END);
    long tamanio = ftell(p_archivo_bin);
    resultado = tamanio / sizeof(t_product);
    fclose(p_archivo_bin);

    return resultado;

}

int crearArchivoBinario(){
    FILE *p_archivo_bin;
    p_archivo_bin = fopen(NOMBRE_ARCHIVO, "wb");
    if (p_archivo_bin == NULL)
        {return 0;}

    fclose(p_archivo_bin);
    return 1;
};

int cargarProductos(){
    t_product producto;
    FILE *p_archivo_bin;

    p_archivo_bin = fopen(NOMBRE_ARCHIVO, "ab");
    if(p_archivo_bin == NULL)
        return 0;

    printf("\nIngrese el id del producto: ");
    scanf("%d", &producto.id);
    printf("\nIngrese la descripcion del producto: ");
    fflush(stdin);
    fgets(producto.descripcion, TAM, stdin);
    printf("\nIngrese el precio del producto: ");
    scanf("%f", &producto.precio);


    fwrite(&producto, sizeof(producto), 1, p_archivo_bin); //variable, sizeof de la variable, 1, puntero al archivo
    fclose(p_archivo_bin);
    return 1;
};

int listarProductos(){
    t_product producto;
    FILE *p_archivo_bin;

    p_archivo_bin = fopen(NOMBRE_ARCHIVO, "rb");
    if (p_archivo_bin == NULL)
        {return 0;}

     while (fread(&producto, sizeof(t_product), 1, p_archivo_bin) == 1) {
        printf("ID: %d\n", producto.id);
        printf("Descripcion: %s\n", producto.descripcion);
        printf("Precio: %.2f\n", producto.precio);
        printf("-----------------------------\n");
    }

    fclose(p_archivo_bin);

    return 1;
}

int consultarProducto(int id){
    t_product producto;
    FILE *p_archivo_bin;
    int encontro = 0;
    p_archivo_bin = fopen(NOMBRE_ARCHIVO,"rb");
    if (p_archivo_bin == NULL) {
        printf("No se ha encontrado el archivo. \n");
        return 0;
    }

    while(fread(&producto, sizeof(producto), 1, p_archivo_bin) == 1){
        if(producto.id == id){
             printf("ID: %d\n", producto.id);
            printf("Descripcion: %s\n", producto.descripcion);
            printf("Precio: %.2f\n", producto.precio);
            printf("-----------------------------\n");
            encontro++;
        }

    }

    if (encontro == 0 ){
        printf("No se ha podido encontrar el id deseado, vuelva a intentarlo nuevamente. \n");
    }

    fclose(p_archivo_bin);
    return 1;
}

int cambiarPrecioProducto(int id, float precio){
    t_product producto;
    FILE* p_archivo_bin;
    int encontro = 0;

    p_archivo_bin = fopen(NOMBRE_ARCHIVO, "r+b");
     if (p_archivo_bin == NULL) {
        printf("No se ha encontrado el archivo. \n");
        return 0;
    }

    while( !feof(p_archivo_bin) ){

        if (producto.id == id){
            producto.precio = precio;
            int pos = ftell(p_archivo_bin) - sizeof(t_product);
            printf("This is pos: %d", pos);
            fseek(p_archivo_bin,pos, SEEK_SET);
            fwrite(&producto, sizeof(t_product), 1, p_archivo_bin);
            printf("ID: %d\n", producto.id);
            printf("Precio nuevo del producto: %.2f\n", producto.precio);
            printf("-----------------------------\n");
            encontro++;
            break;
        }

        fread(&producto, sizeof(t_product), 1, p_archivo_bin);

    }

    if (encontro == 0 ){
        printf("No se ha podido encontrar el id deseado, vuelva a intentarlo nuevamente. \n");
    }

    fclose(p_archivo_bin);
    return 1;

}

int ordenarArchivoId(){
    int cant_reg = contarRegistros();
    if (cant_reg == -1){
        return 0;
    }

    FILE* p_archivo_bin;
    t_product productos[cant_reg], aux;

    p_archivo_bin = fopen(NOMBRE_ARCHIVO, "rb");
    if (p_archivo_bin == NULL) {
        return 0;
    }

    fread(&productos, sizeof(t_product), cant_reg, p_archivo_bin);

    for(int i = 0; i < cant_reg - 1; i++){
        for(int j = 0 ; j < cant_reg ; i++){
            if(productos[j].id > productos[j+1].id){
                aux = productos[j];
                productos[j] = productos[j+1];
                productos[j+1] = aux;
            }
        }
    }

    fseek(p_archivo_bin,0, SEEK_SET);
    fwrite(&productos, sizeof(productos), cant_reg, p_archivo_bin);
    printf("llego");
    fclose(p_archivo_bin);

    listarProductos();
    return cant_reg;
}
