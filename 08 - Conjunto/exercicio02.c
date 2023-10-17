#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

typedef int elemento;

typedef struct nodo *conjunto;
typedef struct nodo *pt_nodo;
typedef struct nodo {
  elemento e;
  pt_nodo prox;
} tnodo;

// Função para criar um conjunto vazio
void CriarConjunto(conjunto *c) { *c = NULL; }

// Função para verificar se o conjunto está vazio
int ConjuntoVazio(conjunto *c) { return (*c == NULL); }

// Função para inserir um elemento no conjunto, garantindo que não haja
// duplicatas
void InserirNoConjunto(conjunto *c, elemento *x) {
  if (!ContemNoConjunto(c, x)) {
    pt_nodo p = (pt_nodo)malloc(sizeof(tnodo));
    p->e = *x;
    p->prox = *c;
    *c = p;
  }
}

// Função para pesquisar um elemento no conjunto
pt_nodo *PesquisarNoConjunto(conjunto *c, elemento *x) {
  pt_nodo *p = c;
  while (*p != NULL) {
    if ((*p)->e == *x) {
      return p;
    }
    p = &((*p)->prox);
  }
  return NULL;
}

// Função para remover um elemento do conjunto, se estiver presente
void RemoverDoConjunto(conjunto *c, elemento *x) {
  pt_nodo *p = PesquisarNoConjunto(c, x);
  if (*p != NULL) {
    pt_nodo temp = *p;
    *p = (*p)->prox;
    free(temp);
  }
}

// Função para verificar se um elemento pertence ao conjunto
int ContemNoConjunto(conjunto *c, elemento *x) {
  pt_nodo p = *c;
  while (p != NULL) {
    if (p->e == *x) {
      return VERDADEIRO;
    }
    p = p->prox;
  }
  return FALSO;
}

// Função para imprimir os elementos do conjunto
void ImprimirConjunto(conjunto *c) {
  pt_nodo p = *c;
  printf("{ ");
  while (p != NULL) {
    printf("%d ", p->e);
    p = p->prox;
  }
  printf("}\n");
}

int main() {
  conjunto c;
  CriarConjunto(&c);

  elemento e1 = 1, e2 = 2, e3 = 3, e4 = 4;

  InserirNoConjunto(&c, &e1);
  InserirNoConjunto(&c, &e2);
  InserirNoConjunto(&c, &e3);

  printf("Conjunto: ");
  ImprimirConjunto(&c);

  elemento busca = 2;
  if (ContemNoConjunto(&c, &busca)) {
    printf("%d pertence ao conjunto.\n", busca);
  } else {
    printf("%d não pertence ao conjunto.\n", busca);
  }

  busca = 4;
  if (ContemNoConjunto(&c, &busca)) {
    printf("%d pertence ao conjunto.\n", busca);
  } else {
    printf("%d não pertence ao conjunto.\n", busca);
  }

  busca = 3;
  RemoverDoConjunto(&c, &busca);
  printf("Após a remoção de %d: ", busca);
  ImprimirConjunto(&c);

  conjunto c2;
  CriarConjunto(&c2);

  elemento e5 = 2, e6 = 4, e7 = 5;

  InserirNoConjunto(&c2, &e5);
  InserirNoConjunto(&c2, &e6);
  InserirNoConjunto(&c2, &e7);

  printf("Conjunto 2: ");
  ImprimirConjunto(&c2);

  conjunto uniao;
  CriarConjunto(&uniao);
  pt_nodo p = c;
  while (p != NULL) {
    InserirNoConjunto(&uniao, &(p->e));
    p = p->prox;
  }
  p = c2;
  while (p != NULL) {
    InserirNoConjunto(&uniao, &(p->e));
    p = p->prox;
  }

  printf("União: ");
  ImprimirConjunto(&uniao);

  conjunto intersecao;
  CriarConjunto(&intersecao);
  p = c;
  while (p != NULL) {
    if (ContemNoConjunto(&c2, &(p->e))) {
      InserirNoConjunto(&intersecao, &(p->e));
    }
    p = p->prox;
  }

  printf("Interseção: ");
  ImprimirConjunto(&intersecao);

  conjunto diferenca;
  CriarConjunto(&diferenca);
  p = c;
  while (p != NULL) {
    if (!ContemNoConjunto(&c2, &(p->e))) {
      InserirNoConjunto(&diferenca, &(p->e));
    }
    p = p->prox;
  }

  printf("Diferença: ");
  ImprimirConjunto(&diferenca);

  return 0;
}
