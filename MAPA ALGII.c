#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LIMITE_AGENDA 5

void menu();
void inserir();
void listar();
void sair();

struct agenda{
	int id;
	char nome[50];
	char telefone[20];
	char email[50];
} agenda[LIMITE_AGENDA];

int cont = 0;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	menu();
	return(0);
}

void menu() {
	system("cls");
	int op = 9;
	printf("====================================\n");
	printf("===     AGENDA - VERSÃO BETA     ===\n");
	printf("====================================\n\n");
	printf("1 - Inserir um novo cadastro.\n");
	printf("2 - Mostrar clientes cadastrados.\n");
	printf("0 - Encerrar.\n\n");
	printf("Digite a opção: ");
	scanf("%d",&op);
	fflush(stdin);
	
	switch(op){
		case 1:
			inserir();
			break;
		case 2:
			listar();
			break;
		case 0:
			sair();
			break;
		default:
			system("cls");
			printf("Opção Inválida!\n\n");
			system("pause");
			menu();
			break;
	}
}
void inserir() {
	if(cont >= 5) {
		system("cls");
		printf(">>>>>>>>>>   Agenda Lotada!   <<<<<<<<<<\n\n");
		system("pause");
		menu();
	} else {
	
		system("cls");
		printf("INSERIR CLIENTE\n\n");
		agenda[cont].id = cont + 1;
		printf("Insira o nome do cliente:\n");
		gets(agenda[cont].nome);
		fflush(stdin);
		printf("\nInsira o telefone do cliente:\n");
		gets(agenda[cont].telefone);
		fflush(stdin);
		printf("\nInsira o e-mail do cliente:\n");
		gets(agenda[cont].email);
		fflush(stdin);
		printf("\nCliente cadastrado com sucesso!\n\n");
		cont++;
		system("pause");
		menu();
	}
}

void listar() {
	system("cls");
	
	if(cont == 0) {
		system("cls");
		printf(">>>>>>>>>>   Agenda Vazia!   <<<<<<<<<<\n\n");
		system("pause");
		menu();
	} else {
		int i;
		printf(">>>>>>>>>>   LISTA DE CLIENTES   <<<<<<<<<<\n\n");
		for (i = 0 ; i < cont; i++) {
		printf(">>>>>> Código do cliente: %d <<<<<<", agenda[i].id);
		printf("\nNome: %s", agenda[i].nome);
		printf("\nTelefone: %s", agenda[i].telefone);
		printf("\nE-mail: %s\n", agenda[i].email);
		printf("\n_____________________________________________\n\n");
		}
		
		system("pause");
		menu();
	}
}

void sair(){
	system("cls");
	printf("Saindo do programa....\n\n");
	system("pause");
}


