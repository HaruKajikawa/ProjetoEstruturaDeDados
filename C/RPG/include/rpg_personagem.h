#ifndef RPG_PERSONAGEM_H
#define RPG_PERSONAGEM_H

typedef struct Personagem
{
    char nome[50];
    int hp;
    int ataque;
    int defesa;
} Personagem;

Personagem* personagem_criar(const char* nome);
void personagem_set_atributos(Personagem* p, int hp, int atk, int def);
void personagem_imprimir(const Personagem* p);
void personagem_destruir(Personagem* p);

#endif