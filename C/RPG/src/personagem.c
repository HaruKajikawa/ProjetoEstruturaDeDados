#include "rpg_personagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Personagem* personagem_criar(const char* nome)
{
    Personagem* p = (Personagem*)malloc(sizeof(Personagem));
    if(!p) return NULL;

    strncpy(p->nome, nome, sizeof(p->nome));
    p->nome[sizeof(p->nome) - 1] = '\0';

    p->hp = 0;
    p->ataque = 0;
    p->defesa = 0;

    return p;
}

void personagem_set_atributos(Personagem* p, int hp, int atk, int def)
{
    if (!p) return;
    p->hp = hp;
    p->ataque = atk;
    p->defesa = def;
}

void personagem_imprimir(const Personagem* p)
{
    if (!p) return;

    printf("=== Personagem ===\n");
    printf("Nome: %s\n", p->nome);
    printf("HP: %d\n", p->hp);
    printf("Ataque: %d\n", p->ataque);
    printf("Defesa: %d\n", p->defesa);
}

void personagem_destruir(Personagem* p)
{
    free(p);
}