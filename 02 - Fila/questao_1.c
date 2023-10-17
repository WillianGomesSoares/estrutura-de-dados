/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma fila.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef int elemento;
#include "filanegativa.h"
int main() {
int num;
fila f;
CriarFila(&f);
while(FilaCheia(&f) == FALSO) {
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
Enfileirar(&f, num);
}

ImprimirFila(&f);

printf("\n");
system("pause");
return 0;
}