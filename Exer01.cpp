#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>

#define V 1
#define F 0

/* a)	Mostrar os elementos pares e �mpares separados */
int parImpar(int *vetorRand){ 
	int i, contador;
	
	printf("\n \n==== Quest�o 2: ==== \n\n");
	printf("a)\n-> Valores pares: ");
	
	contador = 0;
	
	printf("(");
	for (i = 0; i < 10; i++){
		if (vetorRand[i] % 2 == 0){
			printf(" %d, ", vetorRand[i]);
			contador++;
		}
	}
	printf(")");
	
	printf("\n-> Valores �mpares: ");
	printf("(");
	for (i = 0;i < 10;i++){
		if (vetorRand[i] % 2 == 1)
			printf("%d, ", vetorRand[i]);
	}
	printf(")");
	
	/* c)	Contabilizar quantos elementos s�o pares no vetOriginal */
	printf("\n\nc)\n-> Quantidade de valores pares: %d \n", contador);
} 

/* b)	Mostrar o elemento de maior valor do vetOriginal*/
void maiorValor(int *vetorRand){
	int i, maior;
	
	maior = vetorRand[0];
	for (i = 0;i < 10;i++){
		if (vetorRand[i] > maior)
			maior = vetorRand[i];
	}
	
	printf("\nb)\n-> O maior valor � o n�mero %d", maior);
}

/*  e)	Coloque os elementos na ordem inversa do vetOriginal*/
int inverso(int *vetorRand){
	int i, vetorInverso[10];
	
	printf("\ne)\n-> Em ordem inversa: \n");
	printf("inverso = [");
	for (i = 0; i < 10; i++){
		vetorInverso[i] = vetorRand[10-i-1];
		printf("%d, ", vetorInverso[i]);
	}
	printf("] \n");
}

void crescente(int *vetorRand){
	int i, j, b, temp;
	
	for (j = 0;j < 10; j++){
		for (i = 0; i < 10; i++){
			if (vetorRand[i] > vetorRand[i+1]){
				temp = vetorRand[i];
				vetorRand[i] = vetorRand[i+1];
				vetorRand[i+1] = temp;
			}
		}
	}
	
	/* 3) Ordene crescentemente o vetOriginal (1 ponto) */
	printf("\n==== Quest�o 3 ====\n");
	printf("\n-> N�meros em ordem crescente: \n");
	printf("vetor = [");
	for (b = 0; b < 10; b++){
		printf("%d, ", vetorRand[b]);
	}
	
	printf("]");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int i, j, status, vetorRand[10];
	int somatorio;
	
	srand(time(NULL));
	somatorio = 0;
	
	printf(" ============= Gerador e manipulador de n�meros aleat�rios ========== \n \n");
	printf("==== Quest�o 1: ==== \n\n");
	
	/* 1) 	Fa�a um programa que "popule" um vetor (VetOriginal) com 10 n�meros inteiros entre 0 e 9 
	de forma aleat�ria com valores distintos, ou seja, sem valores repetidos (1 ponto) */
	
	printf("vetor = [");
	
	for (i = 0; i < 10; i++){
		
		do{
		
			vetorRand[i] = rand() % 100;
			status = V;
			
			for(j = 0; j < i; j++){
				if (vetorRand[j] == vetorRand[i]){
					status = F;
				}
			}
		} while(status == F);
		
		printf("%d, ", vetorRand[i]);
		
		/*  d) Qual o valor do somat�rio dos elementos do vetOriginal*/
		somatorio += vetorRand[i];
		
	}
	
	printf("]");
	
	
	/* 2) Ap�s o vetor populado, voc� deve: (3 pontos) */
	parImpar(vetorRand);
	maiorValor(vetorRand);
	
	printf("\n\nd)\n-> Somat�rio dos valores: %d \n", somatorio);
	
	inverso(vetorRand);
	crescente(vetorRand);
	
	return 0;
}
