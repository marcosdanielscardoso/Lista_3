#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct banda{
	char nome[40];
	char genero[40];
	int integrantes;
	int ranking;
}tbanda;
int qtd=0;
//---------------------------
int addBanda(tbanda b[]){
	if(qtd==MAX)
	   return 0;
	printf("***** Dados para banda %d *****\n",qtd+1);
	fflush(stdin);
	printf("Nome:");
	gets(b[qtd].nome);
	fflush(stdin);
	printf("Genero:");
	gets(b[qtd].genero);
	printf("Integrantes:");
	scanf("%d",&b[qtd].integrantes);
	printf("Ranking:");
	scanf("%d",&b[qtd].ranking);
	qtd++;
	return 1;
} 
//---------------------------
void mostraBandas(tbanda b[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("\n----------- Banda %d ---------\n",i+1);
		printf("Nome:%s\nGenero:%s\nIntegrantes:%d\nRanking:%d\n",
		       b[i].nome, b[i].genero,b[i].integrantes, b[i].ranking);
		printf("-------------------------------\n");
	}// fim for
}
//--------------------------
void buscaBanda(tbanda b[], char nomeBusca[]){
	int i, encontrou=0;
	char nomeBanda[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeBanda, b[i].nome);
		if(strcmp(strupr(nomeBanda) , strupr(nomeBusca) )==0){ // iguais
		printf("\n----------- Banda %d ---------\n",i+1);
		printf("Nome:%s\nGenero:%s\nIntegrantes:%d\nRanking:%d\n",
		       b[i].nome, b[i].genero,b[i].integrantes, b[i].ranking);
		printf("-------------------------------\n");
		encontrou=1;
		break; // para o laço de repetição
	   }
	}// fim for
	if(!encontrou) // se nao encontrou
	   printf("Banda nao encontrada :(");
}
//--------------------------
void salvarDados(tbanda b[]){
	int i;
	FILE *arq;
	arq = fopen("bandas.txt","w"); // w = write
	fprintf(arq,"%d\n",qtd); // qtd é variável global da qtde de bandas cadastradas
	for(i=0;i<qtd;i++){
		fprintf(arq,"%s\n",b[i].nome);
		fprintf(arq,"%s\n",b[i].genero);
		fprintf(arq,"%d\n",b[i].integrantes);
		fprintf(arq,"%d\n",b[i].ranking);
	}
	printf("Dados salvos com sucesso :)\n");
}
//--------------------------
void carregaDados(tbanda b[]){
	FILE *arq;
	int i;
	arq = fopen("bandas.txt","r"); // r = leitura
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}// fim if
	fscanf(arq,"%d",&qtd);
	for(i=0;i<qtd;i++){
		fscanf(arq,"%s",&b[i].nome);
		fscanf(arq,"%s",&b[i].genero);
		fscanf(arq,"%d",&b[i].integrantes);
		fscanf(arq,"%d",&b[i].ranking);
	}// fim for
	fclose(arq);
	printf("Dados carregados com sucesso :)\n");
}
//--------------------------
int menu(){
	int op;
	printf("*** SISTEMA DE CADASTRO DE BANDAS ROCKYOU ****\n");
	printf("1-Inserir nova banda\n");
	printf("2-Mostrar todas bandas\n");
	printf("3-Buscar banda por nome\n");
	printf("4-Buscar banda ranking\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//---------------------------
int main(){
	tbanda bandas[MAX];
	char nomeBusca[40];
	int op, rank;
	carregaDados(bandas);
    do{
      op = menu();	
      switch(op){
      	case 1: addBanda(bandas);
      	break;
      	case 2: mostraBandas(bandas);
      	break;
      	case 3: printf("Nome da banda para buscar:");
      			fflush(stdin); gets(nomeBusca);
      			buscaBanda(bandas, nomeBusca);
      	break;		
      	case 4: printf("Ranking para busca:");
      			scanf("%d",&rank);
      			
      	break;
      	case 0: salvarDados(bandas);
		  		printf("Saindo... \n");
      	break;
	  }
      	getch(); // pausa na tela - espera digitar uma tecla
      	system("cls");
	}while(op!=0);
	return 0;
}
