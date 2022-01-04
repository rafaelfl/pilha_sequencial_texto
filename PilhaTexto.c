
#include <stdio.h>
#include <stdlib.h>
#include "PilhaTexto.h"

PilhaTexto * criar_pilha() {
  PilhaTexto *p = malloc(sizeof(PilhaTexto));
  p->topo = -1;

  return p;
}

void destruir_pilha(PilhaTexto *p) {
  free(p);
}

int empilhar(PilhaTexto *p, char *texto) {
  if (esta_cheia(p)) {
    return -1;
  }

  p->topo++;
  p->v[p->topo] = texto;

  return 0;
}

char * desempilhar(PilhaTexto *p) {
  char *texto_removido;

  if (esta_vazia(p)) {
    return NULL;
  }

  texto_removido = p->v[p->topo];
  p->topo--;

  return texto_removido;
}

char * topo(PilhaTexto *p) {
  if (esta_vazia(p)) {
    return NULL;
  }

  return p->v[p->topo];
}

int esta_cheia(PilhaTexto *p) {
  // se tiver espaço no vetor....
  if (p->topo < TAM-1) {
    return FALSE;
  } else {
    return TRUE;
  }
}

int esta_vazia(PilhaTexto *p) {
  // se NÃO existe nenhum elemento na pilha...
  if (p->topo < 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}

void imprimir_pilha(PilhaTexto *p) {
  int i;
  printf("base [");

  for (i = 0; i <= p->topo; i++) {
    printf(" (%s) ", p->v[i]);
  }

  printf(". topo\n");

}