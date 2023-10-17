#include <stdio.h>
#include <stdlib.h>

//Altere o programa para que os trechos de código para alocação 
//de memória, preenchimento do vetor e impressão do vetor 
//seja realizado por funções.

int* alocacao(int *array, int n){

    // Alocação dinâmica de memória usando malloc
    array = (int *) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
    }
    return array;
}

int* preencher(int *array, int n){
    // Preencher o array
    for (int i = 0; i < n; i++) {
        array[i] = i * 10;
    }
    return array;
}

int* imprimir(int *array, int n){
    // Imprimir o array
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return array;
}

int main() {
    int *array, n;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    
    array = alocacao(array, n);
    
    array = preencher(array, n);
    
    imprimir(array,n);

    // Liberar a memória alocada com malloc
    free(array);
    
    return 0;
}