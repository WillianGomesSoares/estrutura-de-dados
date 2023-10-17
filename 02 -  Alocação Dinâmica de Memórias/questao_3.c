#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Altere o exemplo para que seja um vetor de estrutura Veículo. A estrutura Veículo deve possuir
//os campos: número do chassi, marca, modelo e preço. Os trechos de código para alocação de
//memória, preenchimento do vetor, impressão do vetor e realocação de memória devem ser
//realizados por funções.

char* alocacao(char *array, int n){

    // Alocação dinâmica de memória usando malloc
    array = (char *) calloc(n, sizeof(char*));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
    }
    return array;
}

char* preencher(char *array, char *input){
    // Preencher o array
    for (int i = 0; i < strlen(input); i++) {
        array[i] = input[i];
    }
    return array;
}

char* imprimir(char *array, int n){
    // Imprimir o array
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", array[i]);
    }
    return array;
}

char* relocacao(char *array, int n){
    // Alocação dinâmica de memória usando malloc
    array = (char *) realloc(array, n);
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
    }
    return array;
}

typedef struct 
{
    char *marca;
    char *modelo;
    double preco;
    int chassi;
}Carro;


int main() {
    int n;
    Carro carro;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    char input[n];

    carro.marca = alocacao(carro.marca, n);

    printf("Digite a marca: ");
    scanf("%s", &input);

    carro.marca = preencher(carro.marca, input);
    
    imprimir(carro.marca,n);
    free(carro.marca);

    char input2[n];

    carro.modelo = alocacao(carro.modelo, n);

    printf("\nDigite o modelo: ");
    scanf("%s", &input2);
    printf("Digite o novo tamanho: ");
    scanf("%d", &n);

    carro.modelo = relocacao(carro.modelo,n);
    carro.modelo = preencher(carro.modelo, input2);

    imprimir(carro.modelo,n);
    free(carro.modelo);

    printf("\nDigite o preço: ");
    scanf("%lf", &carro.preco);
    printf("%lf",carro.preco);

     printf("\nDigite o numero do chassi: ");
    scanf("%d", &carro.chassi);
    printf("%d",carro.chassi);    
    
    return 0;
}