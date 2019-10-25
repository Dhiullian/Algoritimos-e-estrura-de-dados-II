/*
	FAP-Betim
	Disciplica:	Algoritimo e estutura de dados avançados.
	Exercicio:	Calcular fatorial Utilizando pilha dinamica encadeada
	Autor:      Dhiullian Brando de Oliveira Santos.
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
//Estrutura de armazenamento
struct Store{
	int num;
};typedef struct elemento *Pilha;

struct elemento{
	Store dado;
	elemento *prox;
};typedef struct elemento Elem;

//Inicializar Pilha
Pilha *Criar_plh()
{
	Pilha *plh = (Pilha*) malloc (sizeof(Pilha));
	if (plh != NULL)
		*plh =NULL;
	return plh;
}

//Inserir elemento
int Inserir_elemento(Pilha *plh,struct Store dado)
{

	if (plh == NULL) return 0;
	for(int i = 1;i <= dado.num;i++)
	{
		Elem *no = (Elem*) malloc (sizeof(Elem));
		if (no == NULL) return 0;
		no->dado.num = i;
		no->prox = (*plh);
		*plh = no;
	}
	return 1;
}

//Limpar Pilha e Liberar memória
void Limpa_plh(Pilha *plh)
{
	if (plh != NULL)
	{
		Elem *no;
		while ((*plh) != NULL)
		{
			no = *plh;
			*plh = (*plh)->prox;
			free(no);
		}
		free(plh);
	}
}

//Exibir Pilha(sem excluir) e multiplicar elementos
void Imprimir_mult(Pilha *plh)
{
	if (*plh != NULL)
	{
		int Mult=1;
		Elem *no = *plh;
		cout<<"A pilha é composta pelos números:"<<endl<<endl;
		while (no != NULL)
		{
			cout<<"["<<no->dado.num<<"]\t";
			Mult *=  no->dado.num;	
			no = no->prox;

		}
		cout<<endl<<endl<<"O fatorial do número informado é : "<<Mult<<endl<<endl;
	}
	else
		cout<<"A pilha está vazia!"<<endl<<endl;
}

//Programa Principal
int menu()
{
	int escolha;
	
	do
	{
		system("cls");
		cout<<"----------------------------------------------"<<endl;
		cout<<"Escolha uma opção:"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<" [1] Inserir elemento.                        "<<endl;
		cout<<" [2] Limpar a Pilha.                          "<<endl;
		cout<<" [3] Exibir os Elementos e calcular fatorial. "<<endl;
		cout<<" [0] Encerrar o programa.                     "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"escolha:";
		cin>>escolha;
	}while(escolha<0 || escolha > 3);
	
	return escolha;
}	
int main ()
{
	setlocale(LC_ALL,"Portuguese");
	
//Declaração de Variavel
	Pilha *plh;
	Store dado;
	int escolha;
	
//Inicializar Pilha
	plh = Criar_plh();
	
//Inicializar menu
	escolha = menu();
	while(escolha != 0)
	{
		
		switch (escolha)
		{
			// [1] Inserir elemento.
			case 1:	
			system("cls");
			cout<<"Informe o número para se calcular o fatorial: ";
			cin>>dado.num;
			Inserir_elemento(plh,dado);
			cout<<endl<<"Será calculado o fatorial do número "<<dado.num<<"."<<endl<<endl;
			system("pause");
			break;
			
			// [2] Limpar a pilha.      
			case 2:
				system("cls");
				Limpa_plh(plh);
				cout<<endl<<"A pilha Foi limpa com sucesso!"<<endl<<endl;
				plh = Criar_plh();
				system("pause");
				break;
				
			// [3] Exibir e Multiplicar os elementos. 
			case 3:
				system("cls");
				Imprimir_mult(plh);
				system("pause");
		}
		escolha = menu();
	}

//Limpar a pilha antes de encerrar o programa
	Limpa_plh(plh);
}

