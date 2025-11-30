#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

void grafo_inicializar(Grafo* g, int max_vertices)
{
    g->num_vertices = 0;
    g->max_vertices = max_vertices;

    g->lista_adj = (NoAdj**)calloc(max_vertices, sizeof(NoAdj*));
    g->ativo = (bool*)calloc(max_vertices, sizeof(bool));
}

bool grafo_vertice_existe(const Grafo* g, int id)
{
    return id >= 0 && id < g->max_vertices && g->ativo[id];
}

void grafo_inserir_vertice(Grafo* g, int id)
{
    if (id < 0 || id >= g->max_vertices) return;
    if (!g->ativo[id])
    {
        g->ativo[id] = true;
        g->num_vertices++;
    }
}

static void grafo_inserir_na_lista(NoAdj** lista, int destino)
{
    NoAdj* novo = malloc(sizeof(NoAdj));
    if (!novo) return;

    novo->vertice = destino;
    novo->prox = *lista;
    *lista = novo;
}

bool grafo_existe_aresta(const Grafo* g, int origem, int destino)
{
    if (!grafo_vertice_existe(g, origem) || !grafo_vertice_existe(g, destino)) return false;

    NoAdj* atual = g->lista_adj[origem];
    while(atual)
    {
        if (atual->vertice == destino) return true;
        atual = atual->prox;
    }
    return false;
}

void grafo_inserir_aresta(Grafo* g, int origem, int destino)
{
    if (!grafo_vertice_existe(g, origem) || !grafo_vertice_existe(g, destino)) return;

    if (!grafo_existe_aresta(g, origem, destino))
    {
        grafo_inserir_na_lista(&g->lista_adj[origem], destino);
        grafo_inserir_na_lista(&g->lista_adj[destino], origem);
    }
}

static void grafo_remover_da_lista(NoAdj** lista, int destino)
{
    NoAdj* atual = *lista;
    NoAdj* ant = NULL;

    while(atual)
    {
        if (atual->vertice == destino)
        {
            if (ant) ant->prox = atual->prox;
            else *lista = atual->prox;
            free(atual);
            return;
        }
        ant = atual;
        atual = atual->prox;
    }
}

void grafo_remover_aresta(Grafo* g, int origem, int destino)
{
    if (!grafo_existe_aresta(g, origem, destino)) return;

    grafo_remover_da_lista(&g->lista_adj[origem], destino);
    grafo_remover_da_lista(&g->lista_adj[destino], origem);
}

void grafo_remover_vertice(Grafo* g, int id)
{
    if (!grafo_vertice_existe(g, id)) return;

    NoAdj* atual = g->lista_adj[id];
    while(atual)
    {
        grafo_remover_aresta(g, id, atual->vertice);
        atual = g->lista_adj[id];
    }

    g->ativo[id] = false;
    g->num_vertices--;
}

void grafo_imprimir(const Grafo* g)
{
    for (int i = 0; i < g->max_vertices; i++)
    {
        if (g->ativo[i])
        {
            printf("%d ->", i);

            NoAdj* atual = g->lista_adj[i];
            bool primeiro = true;

            while (atual)
            {
                if (!primeiro) printf(", ");
                printf("%d", atual->vertice);
                primeiro = false;
                atual = atual->prox;
            }
            printf("\n");
        }
    }
}

void grafo_destruir(Grafo* g)
{
    for (int i = 0; i < g->max_vertices; i++)
    {
        NoAdj* atual = g->lista_adj[i];
        while (atual)
        {
            NoAdj* prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }

    free(g->lista_adj);
    free(g->ativo);
}