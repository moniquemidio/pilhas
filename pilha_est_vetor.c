#include<stdio.h>
#include<stdlib.h>

#define N 10

struct pilha{
	int n;
	int vet[N];
};
typedef struct pilha Pilha;

Pilha* cria(){
	Pilha *nova;
	nova = (Pilha*)malloc(sizeof(Pilha));
	nova->n = 0;
	return nova;
}

void push(Pilha *p, int v){
	if(p->n<N){
		p->vet[p->n]=v;
		p->n++;
	}
	else
		printf("Stack overflow!");
}

void imprimir(Pilha* p){
	int i;
	for(i=p->n-1;i>=0;i--)
		printf("[%d]\n",p->vet[i]);
}

int vazia(Pilha *p){
	return p->n==0;
}

int pop(Pilha *p){
	int v;
	if(vazia(p))
		printf("Pilha vazia!");
	else{
		v = p->vet[p->n-1];
		p->n--;
		return v;
	}	
}

Pilha* libera(Pilha *p){
	free(p);
	return NULL;
}

Pilha* inverter(Pilha *p){
	Pilha *inv;
	int i;
	inv = cria();
	for(i=0;i<p->n;i++)
		push(inv,pop(p));
	return inv;
}

int main(){
	Pilha *p1,*pInv;
	int r;
	p1 = cria();
	push(p1, 5);
	push(p1, 4);
	push(p1, 3);
	push(p1, 2);
	//imprimir(p1);
	//r = pop(p1);
	//printf("\n\n");
	imprimir(p1);
	//p1 = libera(p1);
	p1 = inverter(p1);
	printf("\n\n");
	imprimir(p1);
	
	return 0;
}
