/* Arquivo: lista.h
* Biblioteca de operações para lista implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
#define TAM 100 // Você deve definir um valor adequado para TAM

struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

// Cria lista.
void CriarLista(lista *l) {
    (*l).inicio = -1; // Inicializa o campo "inicio" com -1
    (*l).fim = -1;    // Inicializa o campo "fim" com -1
}

// Verifica se a lista está vazia.
int ListaVazia(lista *l) {
    return ((*l).inicio == -1);
}

// Verifica se a lista está cheia.
int ListaCheia(lista *l) {
    return ((*l).fim == (TAM - 1)); // Checagem de lista cheia considerando o tamanho máximo TAM
}

// Insere um elemento na lista.
void Alistar(lista *l, elemento e, int pos) {
    int i;
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else if ((pos < (*l).inicio) || (pos > (*l).fim)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [%d, %d].", (*l).inicio, (*l).fim);
    } else {
        for (i = (*l).fim; i > pos; i--)
            (*l).vet[i] = (*l).vet[i - 1];
        (*l).vet[pos] = e;
        (*l).fim++;
    }
}

// Retira um elemento da lista.
elemento Desalistar(lista *l, int pos) {
    int i;
    elemento e;
    if (ListaVazia(l))
        printf("\n ERRO: lista vazia!");
    else if ((pos < (*l).inicio) || (pos > (*l).fim)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [%d, %d].", (*l).inicio, (*l).fim);
    } else {
        e = (*l).vet[pos];
        for (i = pos; i < ((*l).fim - 1); i++)
            (*l).vet[i] = (*l).vet[i + 1];
        (*l).fim--;
    }
    return (e);
}

// Procedimento para imprimir o conteúdo da lista.
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
