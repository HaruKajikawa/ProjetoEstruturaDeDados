#include "../include/rpg_personagem.h"

#include <stdio.h>

int main()
{
    printf("Iniciando testes do modulo PERSONAGEM...\n");

    Personagem* p = personagem_criar("Lauma");

    if (!p)
    {
        printf("FALHA ao criar personagem!\n");
        return 1;
    }

    personagem_set_atributos(p, 120, 30, 20);

    printf("Imprimindo personagem:\n");
    personagem_imprimir(p);

    personagem_destruir(p);

    printf("Testes do PERSONAGEM finalizados com sucesso!\n");
    return 0;
}