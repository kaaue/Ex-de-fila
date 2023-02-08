#include <stdlib.h>
#include <conio2.h>
#include <stdio.h>

struct TpFila
{
	int info;
	struct TpFila *prox;
};
typedef TpFila fila;


void inserir(fila **f, int num)
{
	fila *f1,*aux;
	f1 = (fila*)malloc(sizeof(fila));
	if(f1 != NULL)
	{
		f1->info = num;
		f1->prox = NULL;
		if(*f == NULL) // perguntando se está vazio, se estiver ele adiciona
			*f = f1;
		else
		{
			aux = *f; // recebe o primeiro da fila
			while(aux->prox != NULL) // percorrendo a fila para chegar no ultimo
			{
				aux = aux->prox;
			}
			aux->prox = f1;// saiu do while pq chegou no ultimo entao insere
		}
	}
	else
		printf("erro");
}
fila* remover(fila **f)
{
	fila *f1;
	if(f != NULL)// se nao for vazio contem valor na fila
	{
		f1 = *f; // f1 recebe o que o ponteiro de f indica para pode retornar o primeiro
		*f = f1->prox; // aponta para o proximo sendo ele o novo primerio da lista
	}
	else
		printf("\n FILA VAZIA");
	return f1;
		
	
}
void exibir(fila *f)
{
	printf("\t ----------- Fila ------------- \n \n");
	while(f != NULL)
	{
		
		printf("\t %d",f->info);
		
		f = f->prox;
	}
	printf("\n");
	getch();
	system("cls");
}

int main()
{
	fila *r,*f = NULL;
	int op,numero;
	do
	{
		printf("\n [1] - Inserir na fila ");
		printf("\n [2] - Remover");
		printf("\n [3] - Exibir \n \n\t");
		scanf("%d",&op);
		system("cls");
		switch (op)
		{
			case 1:
				printf("\n Digite o valor para inserir:  ");
				scanf("%d",&numero);
				system("cls");
				inserir(&f,numero);	
				break;
			case 2:
				r = remover(&f);
				printf("\n O valor removido foi:  %d", r->info);
				getch();
				system("cls");
				free(r);
				break;
			case 3:
				exibir(f);
				break;
		}
	}while(op != 27);
	
}
