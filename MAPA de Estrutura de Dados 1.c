#include <stdio.h>
#include <stdlib.h>




#define tamanho 5

void menu_exibir(){
	printf("              \n----------------------  MENU: -------------------------\n\n");
	printf("    1 ---> INSERIR UM ELEMENTO NA FILA.\n");
	printf("    2 ---> REMOVER UM ELEMENTO DA FILA.\n");
	printf("    3 ---> DEIXAR LIMPA TODA A FILA.\n");
	printf("    0 ---> ENCERRAR O PROGRAMA.\n\n");
	printf("\n--------------------------------------------------------\n");
}



typedef struct t_estudande{
	char ra[18];
	char nome_arquivo[45];
	char ext_arquivo[25];
	char matricula_pro[18];
}t_estudante;



typedef struct t_fila{
    t_estudante dados[tamanho];
	int inicio;
	int fim;
}t_fila;



struct t_fila fila;
int op;



void fila_adicionar();
void fila_sair();
void fila_exibir();
void menu_exibir();
void fila_finalizar();
void fila_zerar();



int main(){

	op = 1;
	fila.inicio=0;
	fila.fim=0;
	while(op!=0){
		system("cls");
		fila_exibir();
		menu_exibir();
		scanf("%d", &op);
		switch(op){
			case 0:
				fila_finalizar();
			break;
			case 1:
				fila_adicionar();
			break;
			case 2:
				fila_sair();
			break;
			case 3:
				fila_zerar();
			break;
			default:
				printf("\n OPCAO INEXISTENTE, POR FAVOR, ESCOLHA UMA DAS OPCOES DO MENU: [ 0, 1, 2, 3 ]!  \n\n");
				system("pause");
			break;
		}
	}
	return(0);
}



void fila_adicionar(){
	int i;
	if(fila.fim == tamanho){
		printf("\n\n Fila cheia! \n\n");
		system("pause");
	}	else{
		printf("\nInsira o RA do aluno: ");
		scanf(" %s", fila.dados[fila.fim].ra);
		fflush(stdin);
		printf("\nInsira o nome do arquivo: ");
		fgets(fila.dados[fila.fim].nome_arquivo,45, stdin);
		fflush(stdin);
		printf("\nInsira a extensao do arquivo: ");
		fgets(fila.dados[fila.fim].ext_arquivo, 18, stdin);
		fflush(stdin);
		printf("\nInsira a matricula do professor: ");
		fgets(fila.dados[fila.fim].matricula_pro, 18, stdin);
		fflush(stdin);
		fila.fim++;
	}

}



void fila_sair(){
	int i;
	if( fila.inicio == fila.fim){
		printf("\n\n   FILA VAZIA! \n\n");
		system("pause");
	}	else{
		int i;
		printf("\n         RA: %s\n         NOME DO ARQUIVO: %s\n         EXTENSAO DO ARQUIVO: %s\n         MATRICULA DO PROFESSOR: %s\n\n", fila.dados[fila.inicio].ra, fila.dados[fila.inicio].nome_arquivo, fila.dados[fila.inicio].ext_arquivo, fila.dados[fila.inicio].matricula_pro);
 		system("pause");
		for (i = 0; i < tamanho; i++){
			fila.dados[i] = fila.dados[i+1];
		}
		fila.dados[fila.fim];
		fila.fim--;
	}
}



void fila_zerar(){
	if( fila.inicio == fila.fim){
		printf("\n\n   FILA VAZIA! \n\n");
		system("pause");
	} 	else{
		 	while(fila.inicio != fila.fim){
		 		int i;
		 		for( i = 0; i< tamanho; i++){
		 			fila.dados[i] = fila.dados[i+1];
				}
		 		fila.dados[fila.fim];
				fila.fim--;
			}
		}
}



void fila_exibir(){
	int i;
	do{

		for(i = 0; i < fila.fim; i++)

		{
			printf("------------------------------------------------------------------------------------------\n\n");
			printf("         RA: %s \n         NOME DO ARQUIVO: %s \n         EXTENSAO DO ARQUIVO: %s \n         MATRICULA DO PROFESSOR: %s \n\n", fila.dados[i].ra, fila.dados[i].nome_arquivo, fila.dados[i].ext_arquivo, fila.dados[i].matricula_pro);
		}
		printf("------------------------------------------------------------------------------------------\n\n");
	} while(fila.inicio == tamanho);
}




void fila_finalizar(){
	printf("\n\n  Encerrando o programa! \n\n");
	system("pause");


}

