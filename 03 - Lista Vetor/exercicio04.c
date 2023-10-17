#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados do produto
struct Produto {
    char nome[100];
    float valor;
    int quantidade;
};

int main() {
    int opcao;
    struct Produto lista[100]; // Array para armazenar produtos
    int numProdutos = 0;

    while (1) {
        printf("1 - Cadastrar Produto\n");
        printf("2 - Pesquisar Produto\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Cadastro de produto
            if (numProdutos < 100) {
                printf("Nome do produto: ");
                scanf(" %99[^\n]", lista[numProdutos].nome);
                printf("Valor unitário: ");
                scanf("%f", &lista[numProdutos].valor);
                printf("Quantidade em estoque: ");
                scanf("%d", &lista[numProdutos].quantidade);
                numProdutos++;
                printf("Produto cadastrado com sucesso!\n");
            } else {
                printf("A lista de produtos está cheia.\n");
            }
        } else if (opcao == 2) {
            // Pesquisa de produto
            char nomePesquisa[100];
            printf("Digite o nome do produto a ser pesquisado: ");
            scanf(" %99[^\n]", nomePesquisa);
            int encontrado = 0;

            for (int i = 0; i < numProdutos; i++) {
                if (strcmp(lista[i].nome, nomePesquisa) == 0) {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s\n", lista[i].nome);
                    printf("Valor unitário: %.2f\n", lista[i].valor);
                    printf("Quantidade em estoque: %d\n", lista[i].quantidade);

                    // Excluir o produto
                    char resposta[2];
                    printf("Deseja excluir o produto (S/N)? ");
                    scanf(" %1[^\n]", resposta);
                    if (resposta[0] == 'S' || resposta[0] == 's') {
                        // Exclui o produto movendo os elementos subsequentes para cima na lista
                        for (int j = i; j < numProdutos - 1; j++) {
                            strcpy(lista[j].nome, lista[j + 1].nome);
                            lista[j].valor = lista[j + 1].valor;
                            lista[j].quantidade = lista[j + 1].quantidade;
                        }
                        numProdutos--;
                        printf("Produto excluído com sucesso!\n");
                    }

                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Produto não cadastrado!\n");
            }
        } else if (opcao == 3) {
            // Sair do programa
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
