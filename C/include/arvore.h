#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

typedef struct NoArv
{
    int valor;
    struct NoArv* esquerda;
    struct NoArv* direita;
} NoArv;

typedef struct Arvore
{
    NoArv* raiz;
} Arvore;

void arvore_inicializar(Arvore* a);
bool arvore_inserir(Arvore* a, int v);
bool arvore_buscar(const Arvore* a, int v);
bool arvore_remover(Arvore* a, int v);
void arvore_imprimir(const Arvore* a);
void arvore_destruir(Arvore* a);

#endif