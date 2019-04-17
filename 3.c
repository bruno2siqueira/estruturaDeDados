/*
PILHAS

Exercicio 3) Implemente uma função chamada TPilha, que receba um vetor de inteiros com 15 elementos.
             Para cada um deles, como segue:
             - se o número for par, insira-o na pilha;
             - se o número lido for ímpar, retire um número da pilha;
             - Ao final, esvazie a pilha imprimindo os elementos.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Pilha {

	int topo; /* posicao elemento topo */
	int capacidade;
	int *pElem;
};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capacidade = c;
   p->pElem = (int*) malloc (c * sizeof(int));

}
int estavazia ( struct Pilha *p ){

   if( p-> topo == -1 )
      return 1;   // true
   else
      return 0;   // false
}

int estacheia ( struct Pilha *p ){

	if (p->topo == p->capacidade - 1)
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

int main(){

	struct Pilha minhapilha;
	int i;
	char opcao;
	int valor[15];

	criarpilha (&minhapilha, 15);

			

				if( estacheia( &minhapilha ) == 1 )

					printf("\nPILHA CHEIA! \n");

				else {
					
					for (i = 0; i<15; i++){
					
						
					printf("\nInforme um valor: ");
					scanf("%d", &valor[i]);
				
					if(valor[i] % 2 == 0){
						empilhar (&minhapilha, valor[i]);
					}
					
					else if (valor[i] % 2 == 1){
						i--;
						printf("O numero informado e impar e nao pode ser inserido na pilha");
					}

				
		}
		}

		
		 
				if ( estavazia(&minhapilha) == 1 )

					printf( "\nPILHA VAZIA! \n" );

				else{
					
						for (i = 15; i>0; i--){
						
					printf( "\n%d DESEMPILHADO!\n", desempilhar (&minhapilha));

				}
		}
	
	
}
