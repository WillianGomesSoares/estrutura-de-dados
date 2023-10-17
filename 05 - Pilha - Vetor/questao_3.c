/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma pilha.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10 //mudar pra 100 se quiser 10 funcionarios
typedef int elemento;
#include "pilha.h"
//funcionário” cujos campos são: CPF, nome, endereço, telefone, celular, data de
//nascimento e de admissão, departamento, cargo e salário. As datas devem estar no formato
//“dd/mm/aaaa”. O algoritmo deve possuir:
typedef struct 
{
    char *CPF;
    char *nome;
    char *endereco;
    char *telefone;
    char *celular;
    char *data_nascimento;
    char *data_admissao;
    char *departamento;
    char *cargo;
    double *salario;
}Funcionario;


int main() {
int num;
pilha p;
Funcionario funcionario;
CriarPilha(&p);

FILE *pont_arq;
pont_arq = fopen("pilha.dab", "wb");


while(PilhaCheia(&p) == FALSO) {
printf("Digite o CPF: ");
scanf("%s", &funcionario.CPF);
Empilhar(&p, &funcionario.CPF);
printf("Digite o nome: ");
scanf("%s", &funcionario.nome);
Empilhar(&p, &funcionario.nome);
//ImprimePilha(&p);
printf("Digite o endereco: ");
scanf("%s", &funcionario.endereco);
Empilhar(&p, &funcionario.endereco);
printf("Digite o telefone: ");
scanf("%s", &funcionario.telefone);
Empilhar(&p, &funcionario.telefone);
printf("Digite o celular: ");
scanf("%s", &funcionario.celular);
Empilhar(&p, &funcionario.celular);
printf("Digite o data_nascimento (“dd/mm/aaaa”): ");
scanf("%s", &funcionario.data_nascimento);
Empilhar(&p, &funcionario.data_nascimento);
printf("Digite o data_admissao (“dd/mm/aaaa”): ");
scanf("%s", &funcionario.data_admissao);
Empilhar(&p, &funcionario.data_admissao);
printf("Digite o departamento: ");
scanf("%s", &funcionario.departamento);
Empilhar(&p, &funcionario.departamento);
printf("Digite o cargo: ");
scanf("%s", &funcionario.cargo);
Empilhar(&p, &funcionario.cargo);
printf("Digite o salario: ");
scanf("%lf", &funcionario.salario);
Empilhar(&p, &funcionario.salario);
}


DesempilharArquivo(&p,pont_arq);

fclose(pont_arq);

pont_arq = fopen("pilha.dab", "rb");

EmpilharArquivo(&p,pont_arq);

ImprimePilha(&p);

fclose(pont_arq);

printf("\n");
system("pause");
return 0;
}

//Modifique o algoritmo apresentado, para que ele cadastre uma sequência de 10 registros do
//tipo “funcionário” cujos campos são: CPF, nome, endereço, telefone, celular, data de
//nascimento e de admissão, departamento, cargo e salário. As datas devem estar no formato
//“dd/mm/aaaa”. O algoritmo deve possuir:
//a. Um procedimento que leia os registros a partir do teclado e os empilhe.
//b. Um procedimento que desempilhe os elementos e os grave em um arquivo no modo
//binário.
//c. Um procedimento que leia os registros a partir do arquivo no modo binário e os
//empilhe.
//d. Uma função que permita pesquisar os funcionários por CPF. O algoritmo deve ler o
//CPF a ser pesquisado a partir do teclado.