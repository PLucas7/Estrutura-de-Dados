#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define SIM 1
#define NAO 0

int main(void){
	int i = 0, s = 0, acertos = 0;
	char c;
	bool jogarNovamente;
	int numeros[5];
	int respostas[5];
	
	setlocale(LC_ALL, "Portuguese");
	SetConsoleTitle("Jogo da Memoria");
	
	srand(time(NULL));
	
	printf("Este programa irá gerar números aleatórios entre 1 e 100.\n\n");
	printf("Você deve decorar os números exibidos em 5 segundos e depois escrevê-los na \nordem em que foram exibidos.\n\n");
	printf("Presssione ENTER para iniciar");
	
	do{
		c = getch();
	} while(c != 13);
	
	for(i = 0; i < 5; i++){
		numeros[i] = (rand() % 100) + 1;
	}
	
	s = 5;
	
	do{
		system("cls");
		printf("Decore os seguintes a seguir em %d:\n\n\n", s);
		s--;
		for(i = 0; i < 5;i++){
			printf("%d\t", numeros[i]);
		}
		Sleep(1000);
	} while(s > 0);
	
	system("cls");
	printf("Informa os números que foram exibidos\n\n");
	
	for(i = 0;i < 5;i++){
		printf("\t%d números: ", i+1);
		scanf("%d", &respostas[i]);
		if(respostas[i] == numeros[i]){
			acertos++;
		}
	}
	
	if (acertos == 5){
		printf("\n\nParabéns! Sua memória é muito boa. Veja os números exibidos:\n\n\t");
		for (i = 0; i < 5;i++){
			printf("%d\t", numeros[i]);
		}
	} else{
		printf("\n\nQue pena! Sua memória não é muito boa. Veja os números exibidos:\n\n\t");
		for (i = 0; i < 5;i++){
			printf("%d\t", numeros[i]);
		}
	}
	
	printf("\n\nJogar Novamente?\n1- SIM\n0- NAO\n%d");
	scanf("%d", jogarNovamente);
	
	if (jogarNovamente == SIM){
		system("cls");
		main();
	} else{
		system("pause");
	}
	
	return 0;
}
