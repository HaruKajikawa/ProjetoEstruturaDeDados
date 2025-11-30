#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>

typedef struct NoAdj
{
    int vertice;
    struct NoAdj* prox;
} NoAdj;

typedef struct Grafo
{
    int num_vertices;
    int max_vertices;
    NoAdj** lista_adj;
    bool* ativo;
} Grafo;

void grafo_inicializar(Grafo* g, int max_vertices);
void grafo_inserir_vertice(Grafo* g, int id);
bool grafo_vertice_existe(const Grafo* g, int id);
void grafo_inserir_aresta(Grafo* g, int origem, int destino);
bool grafo_existe_aresta(const Grafo* g, int origem, int destino);
void grafo_remover_aresta(Grafo* g, int origem, int destino);
void grafo_remover_vertice(Grafo* g, int id);
void grafo_imprimir(const Grafo* g);
void grafo_destruir(Grafo* g);

#endif