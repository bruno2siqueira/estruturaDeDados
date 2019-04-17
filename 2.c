/*
PILHAS

Exercicio 2) Construa um programa utilizando uma pilha que resolva o seguinte problema:
             Armazene as placas dos carros (apenas os números) que estão estacionados numa rua sem saída estreita.
             Dado uma placa verifique se o carro está estacionado na rua. Caso esteja, informe a sequência de carros que deverá ser retirada para que o carro em questão consiga sair.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Pilha {

	int topo; /* posicao elemento topo */
	int capa;
	int *pElem;
};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (int*) malloc (c * sizeof(int));

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

void empilhar ( struct Pilha *p, int v){

	p->topo++;
	p->pElem [p->topo] = v;
}

int desempilhar ( struct Pilha *p ){

   int aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}

int retornatopo ( struct Pilha *p ){
   return p->pElem [p->topo];
}
verificaCarro(struct Pilha *p){
	int pla,i, j;
	printf("\nDigite a placa do carro: ");
	scanf("%d", &pla);
	for(i = 0; i<=p->topo; i++){
		if(pla == p->pElem[i]){
			printf("Carro encontrado na posicao: %d\n", i);
			printf("Para tira-lo, precisara tirar os seguintes carros: \n");
			printf("POSICAO\tPLACA\n");
			for(j=p->topo; j>i; j--){
				printf("[%d]\t%d\n", j,p->pElem[j]);
			}
			break;
		} 
	}
	printf("Nenhum carro com essa placa encontrado!\n");
}
int main(){

	struct Pilha minhapilha;
	int capacidade, op;
	int valor;

	printf( "\nCapacidade da pilha de carros? " );
	scanf( "%d", &capacidade );

	criarpilha (&minhapilha, capacidade);

	while( 1 ){ /* loop infinito */

		printf("\n1- colocar um carro (PUSH)\n");
		printf("2- tirar o ultimo carro (POP)\n");
		printf("3- mostrar o carro no topo \n");
		printf("4- verificar posicao do carro\n");
		printf("0- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);

		switch (op){

			case 1: //push

				if( estacheia( &minhapilha ) == 1 )

					printf("\nPILHA CHEIA! \n");

				else {

					printf("\nVALOR? ");
					scanf("%d", &valor);
					empilhar (&minhapilha, valor);

				}
				break;

			case 2: //pop
				if ( estavazia(&minhapilha) == 1 )

					printf( "\nPILHA VAZIA! \n" );

				else{

					valor = desempilhar (&minhapilha);
					printf ( "\n%d DESEMPILHADO!\n", valor );

				}
				break;

			case 3: // mostrar o topo
				if ( estavazia (&minhapilha) == 1 )

					printf( "\nPILHA VAZIA!\n" );

				else {

					valor = retornatopo (&minhapilha);
					printf ( "\nTOPO: %d\n", valor );

				}
				break;
			case 4:
				verificaCarro(&minhapilha);
				break;
			case 0:
				exit(0);

			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}

}
