#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void lista_inicializar(Lista* l)
{
    l->cabeca = NULL;
}

void lista_inserir_fim(Lista* l, int v)
{
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return;

    novo->valor = v;
    novo->prox = NULL;
    if (l->cabeca == NULL)
    {
        l->cabeca = novo;
        return;
    }
    No* atual = l->cabeca;
    while(atual->prox) atual = atual->prox;
    atual->prox = novo;
}

bool lista_remover(Lista* l, int v)
{
    No* atual = l->cabeca;
    No* anterior = NULL;
    while (atual)
    {
        if (atual->valor == v)
        {
            if (anterior) anterior->prox = atual->prox;
            else l->cabeca = atual->prox;
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return false;
}

bool lista_vazia(const Lista* l)
{
    return l->cabeca == NULL;
}

void lista_imprimir(const Lista* l)
{
    printf("[");
    No* atual = l->cabeca;
    bool primeiro = true;
    while(atual)
    {
        if (!primeiro) printf(", ");
        printf("%d", atual->valor);
        primeiro = false;
        atual = atual->prox;
    }
    printf("]\n");
}

void lista_destruir(Lista* l)
{
    No* atual = l->cabeca;
    while(atual)
    {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    l->cabeca = NULL;
}