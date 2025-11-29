#include "fila.h"
#include <stdlib.h>

void fila_inicializar(Fila* f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

bool fila_vazia(Fila* f)
{
    return f->inicio == NULL;
}

void fila_enfileirar(Fila* f, int v)
{
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return;

    novo->valor = v;
    novo->prox = NULL;

    if (fila_vazia(f))
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

bool fila_desenfileirar(Fila* f, int* removido)
{
    if (fila_vazia(f)) return false;

    No* temp = f->inicio;
    *removido = temp->valor;

    f->inicio = temp->prox;

    if (f->inicio == NULL) f->fim == NULL;

    free(temp);
    return true;
}

void fila_imprimir(const Fila* f)
{
    printf("[");
    No* atual = f->inicio;
    bool primeiro = true;
    while (atual)
    {
        if (!primeiro) printf(", ");
        printf("%d", atual->valor);
        primeiro = false;
        atual = atual->prox;
    }
    printf("]\n");
}

void fila_destruir(Fila* f)
{
    No* atual = f->inicio;
    while(atual)
    {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    f->inicio = NULL;
    f->fim = NULL;
}