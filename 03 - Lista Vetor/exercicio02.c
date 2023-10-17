#include <stdio.h>

#define TAM 10

typedef int elemento;

struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

void CriarLista(lista *l) {
    (*l).inicio = -1;
    (*l).fim = -1;
}

int ListaVazia(lista *l) {
    return ((*l).inicio == -1);
}

int ListaCheia(lista *l) {
    return ((*l).fim == (TAM - 1));
}

void Alistar(lista *l, elemento e) {
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else {
        if (ListaVazia(l))
            (*l).inicio = 0;
        (*l).fim++;
        (*l).vet[(*l).fim] = e;
    }
}

elemento Desalistar(lista *l) {
    int i;
    elemento e;
    if (ListaVazia(l))
        printf("\n ERRO: lista vazia!");
    else {
        e = (*l).vet[(*l).inicio];
        for (i = (*l).inicio; i < (*l).fim; i++)
            (*l).vet[i] = (*l).vet[i + 1];
        (*l).fim--;
        if ((*l).inicio == (*l).fim) {
            (*l).inicio = -1;
            (*l).fim = -1;
        }
    }
    return e;
}

void ImprimeLista(lista *l) {
    int i;
    if (ListaVazia(l))
        printf("Lista vazia\n");
    else {
        printf("Conteúdo da lista:\n");
        for (i = (*l).inicio; i <= (*l).fim; i++)
            printf("%d ", (*l).vet[i]);
        printf("\n");
    }
}

int main() {
    lista minhaLista;
    CriarLista(&minhaLista);

    printf("Digite 10 números inteiros:\n");
    for (int i = 0; i < 10; i++) {
        int numero;
        scanf("%d", &numero);
        Alistar(&minhaLista, numero);
    }

    ImprimeLista(&minhaLista);

    return 0;
}
