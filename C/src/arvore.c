#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

static NoArv* novo_no(int v)
{
    NoArv* n = (NoArv*)malloc(sizeof(NoArv));
    if (!n) return NULL;

    n->valor = v;
    n->esquerda = NULL;
    n->direita = NULL;
    return n;
}

void arvore_inicializar(Arvore* a)
{
    a->raiz = NULL;
}

static NoArv* inserir_rec(NoArv* r, int v, bool* sucesso)
{
    if(!r)
    {
        *sucesso = true;
        return novo_no(v);
    }

    if (v < r->valor) r->esquerda = inserir_rec(r->esquerda, v, sucesso);
    else if (v > r->valor) r->direita = inserir_rec(r->direita, v, sucesso);
    else *sucesso = false;

    return r;
}

bool arvore_inserir(Arvore* a, int v)
{
    bool ok = false;
    a->raiz = inserir_rec(a->raiz, v, &ok);
    return ok;
}

bool arvore_buscar(const Arvore* a, int v)
{
    NoArv* atual = a->raiz;

    while(atual)
    {
        if (v < atual->valor) atual = atual->esquerda;
        else if (v > atual->valor) atual = atual->direita;
        else return true;
    }
    return false;
}

static NoArv* remover_rec(NoArv* r, int v, bool* sucesso)
{
    if (!r) return NULL;

    if (v < r->valor) r->esquerda = remover_rec(r->esquerda, v, sucesso);
    else if (v > r->valor) r->direita = remover_rec(r->direita, v, sucesso);
    else
    {
        *sucesso = true;

        if (!r->esquerda && !r->direita)
        {
            free(r);
            return NULL;
        }

        if (!r->esquerda)
        {
            NoArv* temp = r->direita;
            free(r);
            return temp;
        }
        else if (!r->direita)
        {
            NoArv* temp = r->esquerda;
            free(r);
            return temp;
        }

        NoArv* sucessor = r->direita;
        while (sucessor->esquerda) sucessor = sucessor->esquerda;

        r->valor = sucessor->valor;
        r->direita = remover_rec(r->direita, sucessor->valor, sucesso);
    }
    return r;
}

bool arvore_remover(Arvore* a, int v)
{
    bool ok = false;
    a->raiz = remover_rec(a->raiz, v, &ok);
    return ok;
}

static void imprimir_rec(const NoArv* r)
{
    if (!r) return;

    imprimir_rec(r->esquerda);
    printf("%d ", r->valor);
    imprimir_rec(r->direita);
}

void arvore_imprimir(const Arvore* a)
{
    imprimir_rec(a->raiz);
    printf("\n");
}

static void destruir_rec(NoArv* r)
{
    if (!r) return;

    destruir_rec(r->esquerda);
    destruir_rec(r->direita);
    free(r);
}

void arvore_destruir(Arvore* a)
{
    destruir_rec(a->raiz);
    a->raiz = NULL;
}