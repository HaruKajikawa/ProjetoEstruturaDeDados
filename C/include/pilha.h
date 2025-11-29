#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct NoPilha
{
    int valor;
    struct NoPilha* prox;
} NoPilha;

typedef struct Pilha
{
    NoPilha* topo;
} Pilha;

void pilha_inicializar(Pilha* p);
bool pilha_empilhar(Pilha* p, int v);
bool pilha_desempilhar(Pilha* p, int* removido);
bool pilha_vazia(const Pilha* p);
void pilha_imprimir(const Pilha* p);
void pilha_destruir(Pilha* p);

#endif