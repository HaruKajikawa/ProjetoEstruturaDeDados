#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void pilha_inicializar(Pilha* p)
{
    p->topo = NULL;
}

bool pilha_empilhar(Pilha* p, int v)
{
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (!novo) return false;

    novo->valor = v;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool pilha_desempilhar(Pilha* p, int* removido)
{
    if (pilha_vazia(p)) return false;

    NoPilha* temp = p->topo;
    *removido = temp->valor;

    p->topo = temp->prox;
    free(temp);
    return true;
}

bool pilha_vazia(const Pilha* p)
{
    return p->topo == NULL;
}

void pilha_imprimir(const Pilha* p)
{
    printf("Topo -> ");

    NoPilha* atual = p->topo;
    while(atual)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }

    printf("<- Base\n");
}

void pilha_destruir(Pilha* p)
{
    NoPilha* atual = p->topo;
    while(atual)
    {
        NoPilha* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    p->topo = NULL;
}