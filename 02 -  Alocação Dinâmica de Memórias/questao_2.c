#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Altere o exemplo para que seja um vetor de estrutura Pessoa. A estrutura Pessoa deve possuir
//os campos: CPF, nome e salário. Os trechos de código para alocação de memória,
//preenchimento do vetor e impressão do vetor devem ser realizados por funções.

char* alocacao(char *array, int n){

    // Alocação dinâmica de memória usando malloc
    array = (char *) calloc(n, sizeof(char*));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
    }
    return array;
}

char* preencher(char *array, int n, char *input){
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

typedef struct 
{
    char *cpf;
    char *nome;
    double salario;
}Pessoa;


int main() {
    int n;
    Pessoa pessoa;

    printf("Digite o tamanho do cpf: ");
    scanf("%d", &n);

    char input[n];

    pessoa.cpf = alocacao(pessoa.cpf, n);

    printf("Digite o cpf: ");
    scanf("%s", &input);

    pessoa.cpf = preencher(pessoa.cpf, n,input);
    
    imprimir(pessoa.cpf,n);
    free(pessoa.cpf);

    //nome
    printf("\nDigite o tamanho do nome: ");
    scanf("%d", &n);

    char input2[n];

    pessoa.nome = alocacao(pessoa.nome, n);

    printf("Digite o nome: ");
    scanf("%s", &input2);

    pessoa.nome = preencher(pessoa.nome, n,input2);
    
    imprimir(pessoa.nome,n);
    free(pessoa.nome);

    //salario
    printf("\nDigite o salario: ");
    scanf("%lf", &pessoa.salario);
    printf("%lf",pessoa.salario);
    
    return 0;
}