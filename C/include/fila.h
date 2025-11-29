#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct No
{
    int valor;
    struct No* prox;
} No;

typedef struct Fila
{
    No* inicio;
    No* fim;
} Fila;

void fila_inicializar(Fila* f);
bool fila_vazia(Fila* f);
void fila_enfileirar(Fila* f, int v);
bool fila_desenfileirar(Fila* f, int* removido);
void fila_imprimir(const Fila* f);
void fila_destruir(Fila* f);

#endif