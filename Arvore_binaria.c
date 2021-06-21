#include<stdio.h>
#include<stdlib.h>
typedef struct noh{
	int info;
	struct noh * esquerda;
	struct noh * direita; 
}No;
No* Construir_No(int x);
void Inserir(No* aux,int x);
void EmOrdem(No* aux);
void PreOrdem(No* aux);
void PosOrdem(No* aux);
int main(){
	No* arv=Construir_No(20);
	Inserir(arv,18);
	Inserir(arv,25);
	Inserir(arv,14);
	Inserir(arv,13);
	Inserir(arv,5);
	Inserir(arv,2);
	printf("Em ordem:");
	EmOrdem(arv);
	printf("\nPre ordem:");
	PreOrdem(arv);
	printf("\nPos ordem:");
	PosOrdem(arv);
}
No* Construir_No(int x){
	No *novo=malloc(sizeof(No));
	novo->info=x;
	novo->direita=NULL;
	novo->esquerda=NULL;
	return novo;
}
void Inserir(No* aux,int x){/**/
	if(aux->info>x){
		if(aux->esquerda==NULL)
			aux->esquerda=Construir_No(x);
		else
			Inserir(aux->esquerda,x);
	}else if(aux->info<x){
		if(aux->direita==NULL)
			aux->direita=Construir_No(x);
		else
			Inserir(aux->direita,x);
	}
	else
		printf("Numero ja existe");
}
void EmOrdem(No* aux){
	if(aux!=NULL){
		EmOrdem(aux->esquerda);//esquerda
		printf("%d ",aux->info);//visita o nó
		EmOrdem(aux->direita);//direita
	}
}
void PreOrdem(No* aux){
	if(aux!=NULL){
		printf("%d ",aux->info);//visita o nó
		PreOrdem(aux->esquerda);//esquerda
		PreOrdem(aux->direita);//direita
	}
}
void PosOrdem(No* aux){
	if(aux!=NULL){
		PosOrdem(aux->esquerda);//esquerda
		PosOrdem(aux->direita);//direita
		printf("%d ",aux->info);//visita o nós
	}
}

