#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pilha.h"

int jogada(pilha_t *compra, pilha_t *descarte, pilha_t *morto, int cartaProcurando)
{
  int *carta;
  pop(compra, (void **)&carta);
  // printf("Carta: %d\nCartaProcurando: %d\n", *carta, cartaProcurando);

  if (*carta == cartaProcurando)
  {
    push(morto, carta);
    return 2; // Morto
  }

  push(descarte, carta);
  return 1; // Descarte
}

void resetaJogada(pilha_t *compra, pilha_t *descarte)
{
  while (!isEmpty(descarte))
  {
    int *aux;
    pop(descarte, (void **)&aux);
    // printf("Aux: %d\n", *aux);
    push(compra, aux);
  }
}

int main()
{
  pilha_t *compra, *descarte, *morto;
  int numDeCartas, resultadoDaJogada = -1, cartaProcurando = 1;
  int numDeJogadas = 0, fimDeJogo = 0;
  int *cards;

  scanf("%d", &numDeCartas);
  cards = (int *)malloc(numDeCartas * sizeof(int));

  compra = create();
  descarte = create();
  morto = create();

  for (int i = 0; i < numDeCartas; i++)
  {
    scanf("%d", &cards[i]);
    // push(compra, &cards[i]);
    // int topo;
    // top(compra, &topo);
    // printf("Topo - %d\n", topo);
  }

  for (int i = numDeCartas - 1; i >= 0; i--)
  {
    push(compra, &cards[i]);
  }

  while (1)
  {
    numDeJogadas++;
    while (!isEmpty(compra))
    {
      resultadoDaJogada = jogada(compra, descarte, morto, cartaProcurando);
      // printf("Resultado da jogada: %d\n\n", resultadoDaJogada);

      if (resultadoDaJogada == 2 && cartaProcurando++ == numDeCartas)
      {
        // printf("Fim de jogo\n");
        fimDeJogo = 1;
        break;
      }
    }
    resetaJogada(compra, descarte);

    if (fimDeJogo == 1)
    {
      break;
    }

    if (numDeJogadas > 10000)
    {
      // printf("numDeJogadas > 5 no 1 whilen\n");
      break;
    }
  }

  // printf("\n-- Quantidade de jogadas: %d", numDeJogadas);
  printf("%d", numDeJogadas);

  destroy(compra);
  destroy(descarte);
  destroy(morto);
  free(cards);
  printf("\n");
}