#include <stdio.h>
#include <stdlib.h>

struct tipo_lista {
  int *vet;
  int inicio, fim;
};
typedef struct tipo_lista lista;

#define TAM 100

void CriarDeque(lista *l) {
  l->inicio = 0;
  l->fim = 0;
}

int DequeVazio(lista *l) { return (l->inicio == l->fim); }

int DequeCheio(lista *l) { return (l->fim == TAM); }

void InserirInicio(lista *l, int e) {
  if (DequeCheio(l)) {
    printf("\n ERRO: Deque cheio!");
    return;
  }
  l->inicio--;
  l->vet[l->inicio] = e;
}

void InserirFim(lista *l, int e) {
  if (DequeCheio(l)) {
    printf("\n ERRO: Deque cheio!");
    return;
  }
  l->vet[l->fim] = e;
  l->fim++;
}

int RemoverInicio(lista *l) {
  int i;
  int e;
  if (DequeVazio(l)) {
    printf("\n ERRO: Deque vazio!");
    return -1;
  }
  e = l->vet[l->inicio];
  for (i = l->inicio; i < (l->fim - 1); i++)
    l->vet[i] = l->vet[i + 1];
  l->fim--;
  return e;
}

int RemoverFim(lista *l) {
  if (DequeVazio(l)) {
    printf("\n ERRO: Deque vazio!");
    return -1;
  }
  l->fim--;
  return l->vet[l->fim];
}

int AcessarInicio(lista *l) {
  if (DequeVazio(l)) {
    printf("\n ERRO: Deque vazio!");
    return -1;
  }
  return l->vet[l->inicio];
}

int AcessarFim(lista *l) {
  if (DequeVazio(l)) {
    printf("\n ERRO: Deque vazio!");
    return -1;
  }
  return l->vet[l->fim - 1];
}

int Tamanho(lista *l) { return (l->fim - l->inicio); }

int Pesquisar(lista *l, int e) {
  int i;
  for (i = l->inicio; i < l->fim; i++) {
    if (l->vet[i] == e) {
      return i;
    }
  }
  return -1;
}

void AtualizarElemento(lista *l, int e, int pos) {
  if (pos >= l->inicio && pos < l->fim)
    l->vet[pos] = e;
  else {
    printf("\n ERRO: posição inválida!");
    printf("\n Posições válidas: [%d, %d].", l->inicio, l->fim - 1);
  }
}

void LiberarMemoria(lista *l) { free(l->vet); }

int main() {
  lista minhaLista;
  minhaLista.vet = (int *)malloc(TAM * sizeof(int));
  CriarDeque(&minhaLista);

  InserirFim(&minhaLista, 10);
  InserirInicio(&minhaLista, 5);
  InserirFim(&minhaLista, 20);

  printf("Tamanho da lista: %d\n", Tamanho(&minhaLista));

  printf("Elemento no início: %d\n", AcessarInicio(&minhaLista));
  printf("Elemento no fim: %d\n", AcessarFim(&minhaLista));

  printf("Posição do elemento 5: %d\n", Pesquisar(&minhaLista, 5));

  AtualizarElemento(&minhaLista, 15, 1);

  while (!DequeVazio(&minhaLista)) {
    printf("Removido: %d\n", RemoverInicio(&minhaLista));
  }

  LiberarMemoria(&minhaLista);

  return 0;
}
