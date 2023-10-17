/*
* Arquivo: pilha.h
* Biblicoteca de operações para pilha
* implementada com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct tipo_pilha {
char *vet[TAM];
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
void Empilhar(pilha *p, char *e) {
(*p).vet[(*p).topo] = e;
(*p).topo++;
}
//Retira um elemento na pilha.
char *Desempilhar(pilha *p) {
(*p).topo--;
return (*p).vet[(*p).topo];
}

void DesempilharArquivo(pilha *p, FILE *pont_arq) {
printf("\nValores informados: ");
while(PilhaVazia(p) == FALSO) {
fwrite(Desempilhar(p),4,TAM,pont_arq);
}
}

void EmpilharArquivo(pilha *p, FILE *pont_arq) {
	char *read_char;
	char *c[TAM];
	int contador = TAM-1;
	while (!feof (pont_arq))
	{  
		fscanf (pont_arq, "\n%s", &read_char);   
		c[contador] = &read_char;
		//printf ("\n%s ", &read_char);
		contador = contador -1;
	}
	fclose(pont_arq);
	contador = 0;
	while (contador < TAM){
		//printf ("\n%s ", c[contador]);
		Empilhar(p,c[contador]);
		contador = contador +1;
	}
}

void ImprimePilha(pilha *p)
{
//char *num;
//printf("\nValores informados: ");
//while(PilhaVazia(p) == FALSO) {
//num = Desempilhar(p);
printf("\nasd");
//}
}
