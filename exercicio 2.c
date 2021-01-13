#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

//struct
typedef struct{
	char titulo[30], autor[10];
	int ano,prateleira;
}tLivro;
int n=0;

// inserir
void inserir(tLivro l[]){
	if(n==MAX){
		printf("Sistema de Cadastro cheio :(\n");
		return;
	}
	printf("** Cadastro de Livros **\n");
	printf("Digite o titulo: ");
	fflush(stdin);
	gets(l[n].titulo);
	printf("Digite o autor: ");
	fflush(stdin);
	gets(l[n].autor);
	printf("Digite o Ano: ");
	scanf("%d",&l[n].ano);
	printf("Digite a prateleira: ");
	scanf("%d",&l[n].prateleira);
	n++;
}

//listar
void listar(tLivro l[]){
	int i;
	for(i=0; i<n; i++){
		printf("*** Livro %d ***\n",i+1);
		printf("Titulo: %s\n",l[i].titulo);
		printf("Autor: %s\n",l[i].autor);
		printf("Ano: %d\n",l[i].ano);
		printf("Prateleira: %d\n",l[i].prateleira);
	}
}

// procurar por nome
void procurarPorNome(tLivro l[], char nomeBusca[]){
	int i, existe = 0;
	for(i=0; i<n; i++){
		if(strcmp(l[i].titulo,nomeBusca) == 0){
			printf("*** Livro %d ***\n",i+1);
			printf("Titulo: %s\n",l[i].titulo);
			printf("Autor: %s\n",l[i].autor);
			printf("Ano: %d\n",l[i].ano);
			printf("Prateleira: %d\n",l[i].prateleira);	
			existe = 1;
		}
	}
	
	if(existe == 0){
		printf("Nao existe livro com este titulo...\n");
	}
}


//busca por ano
void buscaano(tLivro l[],int ano){
	int i, existe = 0;
	for(i=0; i<n; i++){
		if(ano < l[i].ano){
			printf("*** Livro %d ***\n",i+1);
			printf("Titulo: %s\n",l[i].titulo);
			printf("Autor: %s\n",l[i].autor);
			printf("Ano: %d\n",l[i].ano);
			printf("Prateleira: %d\n",l[i].prateleira);
			existe = 1;
		}
	}
	
	if(existe == 0){
		printf("Nao existe livro mais novo que este!\n");
	}
}

int menu(){
	int op;
	printf("*** Sistema de Cadastro de Livros ***\n");
	printf("1 - Inserir\n");
	printf("2 - Listar\n");
	printf("3 - Procurar por nome\n");
	printf("4 - Livro por ano mais novo\n");
	printf("0 - Sair\n");
	scanf("%d",&op);
	return op;
}

int main(){
	tLivro livros[MAX];
	char nomeBus[30];
	int op,ano;
	do{
		op = menu();
		switch(op){
			case 1: inserir(livros);
			break;
			case 2: listar(livros);
			break;
			case 3: printf("Digite o nome para buscar:\n");
					fflush(stdin);
					gets(nomeBus);
					procurarPorNome(livros,nomeBus);
			break;
			case 4: printf("Digite o ano: ");
					scanf("%d",&ano);
					buscaano(livros, ano);
			break;	
			case 0: printf("Saindo ... ate mais\n");
			default: printf("Opcao invalida");
		}
		printf("Pressione qualquer tecla para sair...\n");
		getch();
		system("cls");
	}while(op != 0);
	return 0;
}
