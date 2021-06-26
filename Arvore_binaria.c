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
void EmOrdem_Personalizado(No* aux);
int main(){
	No* arv=Construir_No(91);
	Inserir(arv,40);
	Inserir(arv,7);
	Inserir(arv,24);
	Inserir(arv,52);
	Inserir(arv,48);
	Inserir(arv,88);
	Inserir(arv,68);
	Inserir(arv,61);
	Inserir(arv,97);	
	printf("Em ordem:");
	EmOrdem(arv);
	printf("\nPre ordem:");
	PreOrdem(arv);
	printf("\nPos ordem:");
	PosOrdem(arv);
	printf("\nPersonalizado:");
	EmOrdem_Personalizado(arv);
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
void EmOrdem_Personalizado(No* aux){
	int achou;
	if(aux!=NULL){//nao ser nó folha
		achou=0;
		EmOrdem_Personalizado(aux->esquerda);//percorre esquerda
		if(!(aux->esquerda==NULL&&aux->direita==NULL)){//não ser nó folha
			if(aux->esquerda!=NULL)//existe nó filho a esquerda
				if(aux->esquerda->esquerda==NULL && aux->esquerda->direita==NULL){//o nó filho ser folha
					printf("%d ",aux->info);
					achou=1;	
				}
			if(aux->direita!=NULL)//existe nó filho a direita
				if(aux->direita->esquerda==NULL && aux->direita->direita==NULL)//o nó filho ser folha
					if(!achou)
						printf("%d ",aux->info);
		}
		EmOrdem_Personalizado(aux->direita);//percorre direita
	}
			
}
