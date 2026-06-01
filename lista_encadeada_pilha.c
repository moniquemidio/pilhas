#include<stdio.h>
#include<stdlib.h>

struct no{
	int info;
	struct no *prox;
};
typedef struct no No;

struct pilha{
	No *topo;
};
typedef struct pilha Pilha;

Pilha* cria(){
	Pilha *nova;
	nova = (Pilha*)malloc(sizeof(Pilha));
	nova->topo = NULL;
	return nova;
}

void push(Pilha *p, int v){
	No *novo;
	novo = (No*)malloc(sizeof(No));
	if(novo!=NULL){	
		novo->prox = p->topo;
		novo->info = v;
		p->topo = novo;	
	}
	else
		printf("ERRO");
}

void imprimir(Pilha *p){
	No *aux=p->topo;
	while(aux!=NULL){
		printf("[%d]\n", aux->info);
		aux = aux->prox;
	}	
}

int vazia(Pilha *p){
	return p->topo==NULL;
}

int pop(Pilha *p){
	No *aux=p->topo;
	int v;
	
	if(!vazia(p)){
		p->topo = aux->prox;
		v = aux->info;
		free(aux);
		return v;
	}
	else{
		printf("Pilha vazia");
	}
}

int main(){
	Pilha *p1;
	p1 = cria();
	push(p1,4);
	push(p1,3);
	push(p1,2);
	imprimir(p1);
	printf("Elemento retirado: %d\n", pop(p1));
	imprimir(p1);
	
	return 0;
}
