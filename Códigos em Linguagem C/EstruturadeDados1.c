#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 5


// primeira estrutura para empilhar os pratos
struct pilha_mapa {
	int pratos[MAX];
	int base;
	int topo;
};

// declarando as variáveis do tipo struct pilha_1
struct pilha_mapa pilha, pilha2;


void mostrar_pilha();
void mostrar_pilha2();
void empilhar_pilha();
void desempilhar_pilha();
void menu();


// FUNÇÃO PRINCIPAL
int main() {
	
	// correção de acentuações
	SetConsoleOutputCP(CP_UTF8);
	
	int op = 1;
	pilha.base = 0;
	pilha.topo = 0;
	pilha2.topo = 0;
	
	while(op != 0) {
			mostrar_pilha();
			mostrar_pilha2();
			menu();
			scanf("%d", &op);
			system("cls");
			fflush(stdin);
			
		switch(op) {
			case 1:
				mostrar_pilha();
				empilhar_pilha();
				system("cls");
			break;
			case 2:
				if(pilha.base == pilha.topo) {
					mostrar_pilha();
					printf("A pilha está vazia. Impossível desempilhar!\n\n");
					system("pause");
					system("cls");
				} else {
					desempilhar_pilha();
					mostrar_pilha2();
					system("pause");
					system("cls");
				}
			break;	
		}
	}
}

// função para mostrar a primeira pilha
void mostrar_pilha() {
	int contador;
	printf("Primeira Pilha:\n");
	printf("[ ");
	// estrutura de repetição para mostrar os dados empilhados
	for(contador = 0; contador < MAX; contador++) {
		printf("%d ", pilha.pratos[contador]);
	}
	printf("]\n\n");
}

// função para mostrar a segunda pilha
void mostrar_pilha2() {
	int i;
	printf("Segunda Pilha:\n");
	printf("[ ");
	for(i = 0; i < MAX; i++) {
		printf("%d ", pilha2.pratos[i]);
	}
	printf("]\n\n");
}

// função empilhar
void empilhar_pilha() {
	if(pilha.topo == MAX) {
		printf("A pilha está cheia. Não e possível empilhar!\n\n");
		system("pause");
	} else {
		printf("(1) Vermelho\n(2) Verde\n(3) Azul\n(4) Branco\n(5) Laranja \nDigite o número da cor que deseja empilhar: ");
		scanf("%d", &pilha.pratos[pilha.topo]);
		pilha.topo++;
	}
}

// função desempilha da primeira pilha e atribui o conteúdo a segunda pilha
void desempilhar_pilha() {
		pilha.topo--;
		pilha2.pratos[pilha2.topo] = pilha.pratos[pilha.topo];
		pilha.pratos[pilha.topo] = 0;
		pilha2.topo++;
}

// função menu de opções
void menu() {
	printf("\n****DIGITE A OPÇÃO**** \n\n# 1 - Empilhar pratos\n# 2 - Desempilhar pratos\n# 0 - Sair\n\n# ");
}

