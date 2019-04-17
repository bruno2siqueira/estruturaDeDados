/*
Operações com Pilha:

Todas as operações em uma pilha podem ser imaginadas como as que ocorre numa pilha de pratos em um restaurante ou como num jogo com as cartas de um baralho:
criação da pilha (informar a capacidade no caso de implementação sequencial - vetor);

- empilhar (push) - o elemento é o parâmetro nesta operação;
- desempilhar (pop);
- mostrar o topo;
- verificar se a pilha está vazia (isEmpty);
- verificar se a pilha está cheia (isFull - implementação sequencial - vetor).

O programa abaixo exibe o codigo fonte de uma pilha dinâmica como as operacoes indicadas acima. Agora, vocês deve realizar as seguintes operacoes.

1 - mostraPilha - funcao que deve mostrar todos os elementos da pilha na tela.
2 - invertePilha - funcao que deve inverter o conteudo da pilha
3 - maiorValor - função que recebe como parâmetro uma pilha. A função deve retornar o maior elemento da pilha
4 - saoIguais - função que receba como parâmetro duas pilhas e verifique de elas são iguais. Duas pilhas são iguais se possuem os mesmos elementos, na mesma ordem.
5-
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct Pilha {
	int topo; /* posicao elemento topo */
	int capa;
	float *pElem;
};

void criarPilha(struct Pilha *p, struct Pilha *p2, int c ){
   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));
   p2->topo = -1;
   p2->capa = c;
   p2->pElem = (float*) malloc (c * sizeof(float));
}
int estavazia ( struct Pilha *p ){
   if( p-> topo == -1 )
      return 1;   // true
   else
      return 0;   // false
}

int estacheia ( struct Pilha *p ){
	if (p->topo == p->capa - 1)
		return 1;
	else
		return 0;
}

void empilhar ( struct Pilha *p, float v){
	p->topo++;
	p->pElem [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){
   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}

float retornatopo ( struct Pilha *p ){
   return p->pElem [p->topo];
}
void mostraPilha(struct Pilha *p){
	int i;
	printf("\nMostrando elementos da pilha...: \n");
	for(i=0; i<=p->topo; i++){
		printf("[%d]: %f\n", i, p->pElem[i]);
	}
}
void invertePilha(struct Pilha *p){
	int i, j = p->capa;
	float aux[p->capa];
	printf("Invertendo pilha...\n");
	for(i=0; i <= p->topo; i++){
		aux[i] = p->pElem[--j];
	}
	for(i=0; i<=p->topo; i++){
		p->pElem[i] = aux[i];
	}
}
void maiorValor(struct Pilha *p){
	int pos, i;
	float mai;
	for(i=0; i<=p->topo; i++){
		if (i==0){ 
			pos = i;
			mai = p->pElem[i];
		} else {
			if(p->pElem[i] > mai){
				mai = p->pElem[i];
				pos = i;
			}
		}
	}
	printf("Na posicao %d encontra-se o maior valor, sendo ele: %f", pos, mai);
}
bool saoIguais(struct Pilha *p, struct Pilha *p2){
	int i;
	bool ret;
	for(i=0; i<=p->capa; i++){
		if(p->pElem[i] == p2->pElem[i]){
			ret = true;
		} else {
			ret = false;
			break;
		}
	}
	return ret;
}
int escolhaPilha(struct Pilha *p, int qual){
	int op = 1;
	float valor;
	while (op != 0){
		printf("\n\tATUALMENTE NA PILHA %d\n", qual);
		printf("\n1- empilhar (PUSH)\n");
		printf("2- desempilhar (POP)\n");
		printf("3- mostrar o topo \n");
		printf("4- mostrar a pilha \n");
		printf("5- inverter a pilha \n");
		printf("0- sair dessa opcao\n");
		printf("\nopcao? ");
		scanf("%d", &op);
		switch (op){
			case 1: //push
				if( estacheia(p) == 1 )
					printf("\nPILHA CHEIA! \n");
				else {
					printf("\nVALOR? ");
					scanf("%f", &valor);
					empilhar (p, valor);
				}
				break;
			case 2: //pop
				if ( estavazia(p) == 1 )
					printf( "\nPILHA VAZIA! \n" );
				else{

					valor = desempilhar (p);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );
				}
				break;
			case 3: // mostrar o topo
				if ( estavazia (p) == 1 )

					printf( "\nPILHA VAZIA!\n" );
				else {

					valor = retornatopo (p);
					printf ( "\nTOPO: %.1f\n", valor );
				}
				break;
			case 4:
				if ( estavazia(p) == 1 )
					printf( "\nPILHA VAZIA! \n" );
				else{
					mostraPilha(p);
				}
				break;
			case 5:
				if ( estavazia(p) == 1 )
					printf( "\nPILHA VAZIA! \n" );
				else{
					invertePilha(p);
				}
				break;
			case 0:
				break;
			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}
}
int main(){
	struct Pilha minhapilha, minhapilhinha;
	bool teste;
	int capacidade, op = 1;
	float valor;
	printf( "\nCapacidade das pilhas? " );
	scanf( "%d", &capacidade);
	criarPilha(&minhapilha, &minhapilhinha, capacidade);
	while( op != 0 ){ /* loop infinito */
		printf("Digite a pilha em questao para modificar(1/2): \n 3 - Comparar se sao iguais\n 0  - sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				escolhaPilha(&minhapilha, op);
				break;
			case 2:
				escolhaPilha(&minhapilhinha, op);
				break;
			case 3:
				teste = saoIguais(&minhapilha, &minhapilhinha);
				if(teste == 1){
					printf("Sao iguais!\n");
				} else {
					printf("Nao sao iguais!\n");
				}
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nOperacao invalida!\n");
		}
	}

}
