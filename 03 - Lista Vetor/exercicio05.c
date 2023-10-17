#include <stdio.h>

int main() {
    int lista[10]; // Lista de inteiros
    int tamanho = 0; // Tamanho atual da lista
    int posicao, elemento, opcao;

    // Leitura dos 10 inteiros iniciais
    printf("Digite 10 inteiros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &lista[i]);
        tamanho++;
    }

    while (1) {
        // Mostrar a lista atual
        printf("Lista atual: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", lista[i]);
        }
        printf("\n");

        printf("Digite a posição a ser retirada (-1 para encerrar): ");
        scanf("%d", &posicao);

        if (posicao == -1) {
            // Encerrar a execução
            break;
        } else if (posicao < 0 || posicao >= tamanho) {
            // Posição inválida
            printf("Posição inválida. Tente novamente.\n");
        } else {
            // Retirar o elemento da posição escolhida
            elemento = lista[posicao];
            for (int i = posicao; i < tamanho - 1; i++) {
                lista[i] = lista[i + 1];
            }
            tamanho--;

            printf("Elemento retirado: %d\n", elemento);
        }
    }

    return 0;
}
