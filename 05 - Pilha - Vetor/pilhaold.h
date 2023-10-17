/*
* Arquivo: pilha.h
* Biblicoteca de operações para pilha
* implementada com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct tipo_pilha {
elemento vet[TAM];
int topo;
};
typedef struct tipo_pilha pilha;
//Cria pilha.
void CriarPilha(pilha *p) {
(*p).topo = 0;
}
//Verifica se a pilha está vazia.
int PilhaVazia(pilha *p) {
return((*p).topo == 0);
}
//Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
return((*p).topo == TAM);
}
//Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
(*p).vet[(*p).topo] = e;
(*p).topo++;
}
//Retira um elemento na pilha.
elemento Desempilhar(pilha *p) {
(*p).topo--;
return (*p).vet[(*p).topo];
}

void DesempilharArquivo(pilha *p, FILE *pont_arq) {
int num = 0;
printf("\nNumeros informados: ");
while (PilhaVazia(p) == FALSO) {
	num = Desempilhar(p);
	fprintf(pont_arq,"\n%d", num);
}
}

void EmpilharArquivo(pilha *p, FILE *pont_arq) {
	int read_int = 0;
	int c[TAM];
	int contador = TAM-1;
	while (!feof (pont_arq))
	{  
		fscanf (pont_arq, "\n%d", &read_int);   
		c[contador] = read_int;
		//printf ("\n%d ", c[contador]);
		contador = contador -1;
	}
	fclose(pont_arq);
	contador = 0;
	while (contador < TAM){
		//printf ("\n%d ", c[contador]);
		Empilhar(p,c[contador]);
		contador = contador +1;
	}
}

void ImprimePilha(pilha *p)
{
int num = 0;
printf("\nValores informados: ");
while(PilhaVazia(p) == FALSO) {
num = Desempilhar(p);
printf("\n%d", num);
}
}
