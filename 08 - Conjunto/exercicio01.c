/* Arquivo: lista.h
 * Biblicoteca de operações para lista implementada
 * com vetor com implementação das
  principais operações de um TAD Conjunto
 */

#define VERDADEIRO 1
#define FALSO 0
#define TAM 100 // Tamanho máximo do conjunto

typedef int elemento; // Tipo de elementos do conjunto

struct tipo_lista {
  elemento vet[TAM];
  int tamanho;
};
typedef struct tipo_lista lista;

typedef struct {
  lista l;
} conjunto;

// Inicializa um conjunto vazio
void InicializarConjunto(conjunto *c) { c->l.tamanho = 0; }

// Verifica se o conjunto está vazio
int ConjuntoVazio(conjunto *c) { return (c->l.tamanho == 0); }

// Insere um elemento no conjunto (sem duplicatas)
void InserirNoConjunto(conjunto *c, elemento e) {
  if (!ContemNoConjunto(c, e)) {
    c->l.vet[c->l.tamanho] = e;
    c->l.tamanho++;
  }
}

// Remove um elemento do conjunto, se estiver presente
void RemoverDoConjunto(conjunto *c, elemento e) {
  int pos = EncontrarNoConjunto(c, e);
  if (pos != -1) {
    for (int i = pos; i < c->l.tamanho - 1; i++) {
      c->l.vet[i] = c->l.vet[i + 1];
    }
    c->l.tamanho--;
  }
}

// Verifica se um elemento pertence ao conjunto
int ContemNoConjunto(conjunto *c, elemento e) {
  return EncontrarNoConjunto(c, e) != -1;
}

// Encontra a posição de um elemento no conjunto (ou -1 se não encontrado)
int EncontrarNoConjunto(conjunto *c, elemento e) {
  for (int i = 0; i < c->l.tamanho; i++) {
    if (c->l.vet[i] == e) {
      return i;
    }
  }
  return -1;
}

// Calcula a união de dois conjuntos
conjunto UniaoDeConjuntos(conjunto *c1, conjunto *c2) {
  conjunto resultado;
  InicializarConjunto(&resultado);

  for (int i = 0; i < c1->l.tamanho; i++) {
    InserirNoConjunto(&resultado, c1->l.vet[i]);
  }

  for (int i = 0; i < c2->l.tamanho; i++) {
    InserirNoConjunto(&resultado, c2->l.vet[i]);
  }

  return resultado;
}

// Calcula a interseção de dois conjuntos
conjunto IntersecaoDeConjuntos(conjunto *c1, conjunto *c2) {
  conjunto resultado;
  InicializarConjunto(&resultado);

  for (int i = 0; i < c1->l.tamanho; i++) {
    if (ContemNoConjunto(c2, c1->l.vet[i])) {
      InserirNoConjunto(&resultado, c1->l.vet[i]);
    }
  }

  return resultado;
}

// Calcula a diferença entre dois conjuntos (elementos em c1, mas não em c2)
conjunto DiferencaDeConjuntos(conjunto *c1, conjunto *c2) {
  conjunto resultado;
  InicializarConjunto(&resultado);

  for (int i = 0; i < c1->l.tamanho; i++) {
    if (!ContemNoConjunto(c2, c1->l.vet[i])) {
      InserirNoConjunto(&resultado, c1->l.vet[i]);
    }
  }

  return resultado;
}

int main() {
  conjunto conjuntoA, conjuntoB;
  InicializarConjunto(&conjuntoA);
  InicializarConjunto(&conjuntoB);

  InserirNoConjunto(&conjuntoA, 1);
  InserirNoConjunto(&conjuntoA, 2);
  InserirNoConjunto(&conjuntoA, 3);

  InserirNoConjunto(&conjuntoB, 2);
  InserirNoConjunto(&conjuntoB, 3);
  InserirNoConjunto(&conjuntoB, 4);

  conjunto uniao = UniaoDeConjuntos(&conjuntoA, &conjuntoB);
  conjunto intersecao = IntersecaoDeConjuntos(&conjuntoA, &conjuntoB);
  conjunto diferenca = DiferencaDeConjuntos(&conjuntoA, &conjuntoB);

  // Imprimir os resultados
  printf("Conjunto A: ");
  for (int i = 0; i < conjuntoA.l.tamanho; i++) {
    printf("%d ", conjuntoA.l.vet[i]);
  }
  printf("\n");

  printf("Conjunto B: ");
  for (int i = 0; i < conjuntoB.l.tamanho; i++) {
    printf("%d ", conjuntoB.l.vet[i]);
  }
  printf("\n");

  printf("União: ");
  for (int i = 0; i < uniao.l.tamanho; i++) {
    printf("%d ", uniao.l.vet[i]);
  }
  printf("\n");

  printf("Interseção: ");
  for (int i = 0; i < intersecao.l.tamanho; i++) {
    printf("%d ", intersecao.l.vet[i]);
  }
  printf("\n");

  printf("Diferença (A - B): ");
  for (int i = 0; i < diferenca.l.tamanho; i++) {
    printf("%d ", diferenca.l.vet[i]);
  }
  printf("\n");

  return 0;
}
