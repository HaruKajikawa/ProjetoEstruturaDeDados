#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct No
{
    int valor;
    struct No* prox;
} No;

typedef struct Lista
{
    No* cabeca;
} Lista;

void lista_inicializar(Lista* l);
void lista_inserir_fim(Lista* l, int v);
bool lista_remover(Lista* l, int v);
bool lista_vazia(const Lista* l);
void lista_imprimir(const Lista* l);
void lista_destruir(Lista* l);

#endif