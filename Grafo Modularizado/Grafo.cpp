/*
	FAP-Betim
	Disciplica:	Algoritimo e estutura de dados avançados.
	Exercicio:	Grafo Modularizado com algoritmo de djkstra.
	Autor:      Dhiullian Brando de Oliveira Santos.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "MeuGrafo.h"
#include <ctype.h>
using namespace std;

// Estrutura de armazenamento das cidade que irão compor o grafo.
struct Cidade
{
	char nome[15];
	int visitado;
};


int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	/* "eh_ponderado" serve para alterar o grafo para um grafo sem o peso das distancias.
	"eh_digrafo serve para se ter a possibilidade de criar um grafo onde ele nao seja digrafo.*/
	int eh_digrafo = 1,escolha = 0,num_vertice, grau_max, eh_ponderado = 1;

	
	// Loop de inicialização do grafo com quantidade de vertice e número maximo de arestas.
	while(escolha == 0)
	{
		system("cls");
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"             Informe a quantidade de vertices do grafo:"<<endl<<"->";
		cout<<"                                  ";
		cin>>num_vertice;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"                   Informe o Grau maximo do grafo:"<<endl<<"->";
		cout<<"                                  ";
		cin>>grau_max;
		cout<<"========================================================================="<<endl<<endl;
		cout<<"       Seu Grafo será composto por "<<num_vertice<<" vertices com grau máximo de "<<grau_max<<"."<<endl<<endl;
		cout<<"========================================================================="<<endl<<endl;
		cout<<"Precione [1] para confirmar as informações ou [0] para alterar os dados:"<<endl<<"->";
		cin>>escolha;
		
		// Condição para invalidar opções diferentes das pré estabelecidas.
		while(escolha >1 || escolha < 0)
		{
			system("cls");
			cout<<endl<<"[ERRO] A opção escolhida é invalida !"<<endl<<endl;
			system("pause");
			system("cls");
			cout<<"========================================================================="<<endl<<endl;
			cout<<"       Seu Grafo será composto por "<<num_vertice<<" vertices com grau máximo de "<<grau_max<<"."<<endl<<endl;
			cout<<"========================================================================="<<endl<<endl;
			cout<<"Precione [1] para confirmar as informações ou [0] para alterar os dados:"<<endl<<"->";	
			cin>>escolha;		
		}
	}
	
	// Vetor para armazenar os nomes das cidades utilizadas no grafo.
	Cidade city[num_vertice];
	
	// Inicialização do grafo.
	Grafo *gr = Cria_Grafo (num_vertice, grau_max, eh_ponderado);
	
	// Laço para inserção das  cidades no grafo.
	for (int i = 0; i < num_vertice; i++)
	{
		cout<<"Informe a nome da "<<i+1<<"º cidade:";
		fflush(stdin);
		gets(city[i].nome);
	}
	
	// Inserção para facilitar o teste do programa.
	/*Inserir_Aresta(gr, 0, 1, eh_digrafo, 1);
	Inserir_Aresta(gr, 1, 3, eh_digrafo, 1);
	Inserir_Aresta(gr, 1, 2, eh_digrafo, 1);
	Inserir_Aresta(gr, 2, 4, eh_digrafo, 1);
	Inserir_Aresta(gr, 3, 0, eh_digrafo, 1);
	Inserir_Aresta(gr, 3, 4, eh_digrafo, 1);
	Inserir_Aresta(gr, 4, 1, eh_digrafo, 1);*/
	
	// Inicialização do menú do programa.
	escolha = menu();
	while (escolha != 0)
	{
		switch (escolha)
		{
			// Inserção de uma nova aresta no grafo.
			case 1:
			{
				// vet_cidade[grau_max*2]  recebe os valores da função imprime grafo e armazena para a exibição dos nomes das cidades.
				int City_origem,City_destino,vet_cidade[grau_max*2];
				char N_maiusculo[15];
				float City_distancia;
				
				//Inicializando o vetor das cidades com -1.
				for (int i = 0; i < grau_max*2;i++)
					vet_cidade[i] =-1;			
				
				system("cls");
				cout<<"====================================="<<endl;
				cout<<" RELAÇÃO DE CIDADES"<<endl;
				cout<<"====================================="<<endl;
				cout<<" ID\t\t  CIDADE"<<endl;
				cout<<"-------------------------------------"<<endl;
				
				// Exibição dos ID's das cidades para facilitar manipuação.
				for(int i = 0; i < num_vertice; i++)
				{
					cout<<" "<<i<<"\t\t  "<<city[i].nome<<endl;	
				}
				cout<<"====================================="<<endl;				
	   			
				cout<<"Informe o ID da cidade origem:";
				cin>>City_origem;
				
				// Converte o nome da cidade origem para MAIUSCULO(estetico).
				for(int i = 0; i <= strlen(city[City_origem].nome); i++)
				{
					N_maiusculo[i] = (char)toupper(city[City_origem].nome[i]);
				}
					
				//Função que passa as posições da cidade para o vet_cidade para que possa ser impresso posterior.
				Imprime_Grafo(gr,City_origem,vet_cidade);
				
				// comparação para caso não haja relacionamentos.
				if(vet_cidade[0] != -1)
				{			
					cout<<endl<<"=====================================";
					cout<<endl<<" DIREÇÕES PARTINDO DE "<<N_maiusculo<<endl;				
					cout<<"====================================="<<endl;
					cout<<" ORIGEM\t\t      DESTINO"<<endl;
					cout<<"-------------------------------------";

					// Exibe uma lista de relacionamentos do elemento origem já existentes para não se repetir relacionamentos.
			
					for(int i = 0; i < grau_max * 2;i+=2)
					{
					if(vet_cidade[i] == -1)
						break;
					cout<<endl<<" "<<city[vet_cidade[i]].nome;
					for(int j = strlen(city[vet_cidade[i]].nome); j < 15; j++){cout<<" ";};
            		cout<<"->    "<<city[vet_cidade[i+1]].nome;									
					}
					cout<<endl<<"====================================="<<endl;
				}						
				
				cout<<endl<<"Informe o ID da cidade destino:";
				cin>>City_destino;
				cout<<endl<<"Informe a distancia entre as duas cidades:";
				cin>>City_distancia;
				
				system("cls");
				
				// Exibição dos dados da nova aresta inserida.
				cout<<"Foi inserido uma nova direção partindo de "<<city[City_origem].nome<<" com destino á "<<city[City_destino].nome;
				cout<<" e este caminho possui uma distancia de "<<City_distancia<<"Km."<<endl<<endl;
				
				// Função de inserção de Aresta.
				Inserir_Aresta(gr, City_origem, City_destino, eh_digrafo,City_distancia);
				
				system("Pause");
				break;				
			}
			
			// Exibição de todos os relacionamentos do grafo.
			case 2:			
			{
				/* vet_cidade[(grau_max*2)*num_vertice]  recebe os valores da função imprime_relacoes e armazena 
				dados para a exibição de todos os relacionamentos presentes no grafo.*/
				int City_origem,City_destino,vet_cidade[(grau_max*2)*num_vertice];
				
				//Inicializando o vetor das cidades com -1
				for (int i = 0; i < (grau_max*2)*num_vertice;i++)
					vet_cidade[i] =-1;	
					
				Imprime_Relacionamentos(gr,vet_cidade);			
				
				system("cls");
				
				cout<<"=====================================";
				cout<<endl<<" LISTA DE RELAÇÕES ENTRE CIDADES "<<endl;				
				cout<<"====================================="<<endl;
				cout<<" ORIGEM\t\t      DESTINO"<<endl;
				cout<<"-------------------------------------";				
					
				// Exibe uma lista de todos relacionamentos já existentes no grafo.
				for(int i = 0; i < (grau_max*2)*num_vertice;i+=2)
				{
					if(vet_cidade[i] == -1)
						break;
					cout<<endl<<" "<<city[vet_cidade[i]].nome;
					for(int j = strlen(city[vet_cidade[i]].nome); j < 15; j++){cout<<" ";};
	            	cout<<"->    "<<city[vet_cidade[i+1]].nome;					
				}
				cout<<endl<<"====================================="<<endl<<endl;			
				system("pause");
				break;
			}	
			
			// Remover uma aresta do grafo.				
			case 3:
			{						
				int City_origem,City_destino,vet_cidade[grau_max*2];
				char N_maiusculo[15];
				
				//Inicializando o vetor das cidades com -1
				for (int i = 0; i < grau_max*2;i++)
					vet_cidade[i] =-1;				
				
				system("cls");							
				cout<<"====================================="<<endl;
				cout<<" RELAÇÃO DE CIDADES"<<endl;
				cout<<"====================================="<<endl;
				cout<<" ID\t\t  CIDADE"<<endl;
				cout<<"-------------------------------------"<<endl;
				
				// Exibição dos ID's das cidades para facilitar manipuação.
				for(int i = 0; i < num_vertice; i++)
				{
					cout<<" "<<i<<"\t\t  "<<city[i].nome<<endl;	
				}
				cout<<"====================================="<<endl;				
	   			
				cout<<"Informe o ID da cidade que terá uma aresta removida:";
				cin>>City_origem;
				
				// Converte o nome da cidade origem para MAIUSCULO(estetico).
				for(int i = 0; i <= strlen(city[City_origem].nome); i++)
				{
					N_maiusculo[i] = (char)toupper(city[City_origem].nome[i]);
				}	
				
				//Função que passa as posições da cidade para o vet_cidade para que possa ser impresso posterior.
				Imprime_Grafo(gr,City_origem,vet_cidade);
				
				if(vet_cidade[0] != -1)
				{				
					cout<<endl<<"=====================================";
					cout<<endl<<" DIREÇÕES PARTINDO DE "<<N_maiusculo<<endl;				
					cout<<"====================================="<<endl;
					cout<<" ORIGEM\t\t      DESTINO"<<endl;
					cout<<"-------------------------------------";
					
					// Exibe uma lista de relacionamentos do elemento origem já existentes.
					for(int i = 0; i < grau_max * 2;i+=2)
					{
						if(vet_cidade[i] == -1)
							break;
						cout<<endl<<" "<<city[vet_cidade[i]].nome;
						for(int j = strlen(city[vet_cidade[i]].nome); j < 15; j++){cout<<" ";};
	            		cout<<"->    "<<city[vet_cidade[i+1]].nome;								
					}
					cout<<endl<<"====================================="<<endl;
				}
				else
				{
					system("cls");
					cout<<"Não existe nenhuma relação partindo da cidade "<<N_maiusculo<<endl<<endl;
					system("pause");
					break;	
				}	
				cout<<endl<<"Informe o ID da cidade destino:";
				cin>>City_destino;
				
				Remover_Aresta(gr,City_origem, City_destino, eh_digrafo);
				
				system("cls");
				cout<<"Foi removido o caminho que partia de "<<city[City_origem].nome<<" com destino a "<<city[City_destino].nome<<"."<<endl<<endl;
			
				system("Pause");
				break;
			}
			// Menor caminho possivel Djkistra.	
			case 4:
			{
				//
				int City_origem,City_destino,i,anterior[num_vertice]={};
				char N_maiusculo[15];
				float distancia[num_vertice]={};
				
				// zera todos os elementos da struct city para evitar erros.
				for(int i = 0; i < num_vertice;i++)
					city[i].visitado = 0;		
				
				system("cls");
				cout<<"====================================="<<endl;
				cout<<" RELAÇÃO DE CIDADES"<<endl;
				cout<<"====================================="<<endl;
				cout<<" ID\t\t  CIDADE"<<endl;
				cout<<"-------------------------------------"<<endl;
				
				// Exibição dos ID's das cidades para facilitar manipuação.
				for(int i = 0; i < num_vertice; i++)
				{
					cout<<" "<<i<<"\t\t  "<<city[i].nome<<endl;	
				}
				cout<<"====================================="<<endl;				
	   			
				cout<<"Informe o ID da cidade origem:";
				cin>>City_origem;
				
				// Converte o nome da cidade origem para MAIUSCULO(estetico).
				for(int i = 0; i <= strlen(city[City_origem].nome); i++)
				{
					N_maiusculo[i] = (char)toupper(city[City_origem].nome[i]);
				}
				
				Menor_Caminho_Grafo(gr,City_origem, anterior, distancia);
				
				system("cls");
				
				cout<<"=====================================================";
				cout<<endl<<"   DISTANCIAS PARTINDO DA CIDADE "<<N_maiusculo<<endl;				
				cout<<"====================================================="<<endl;
				cout<<" ORIGEM\t\t      DESTINO\t\t   DISTANCIA"<<endl;
				cout<<"-----------------------------------------------------";
				
				// Imprime os menores caminhos partindo da cidade escolhida como origem.
				for(i = City_origem; i < num_vertice; i++)
				{	
					if(i != City_origem)
					{
						if(city[i].visitado == 1)
							break;
						else
						{
							cout<<endl<<" "<<city[City_origem].nome;
							for(int j = strlen(city[City_origem].nome); j < 15; j++){cout<<" ";};	
							cout<<"->    "<<city[i].nome;	
							for(int j = strlen(city[i].nome); j < 15; j++){cout<<" ";};
							if(distancia[i] == -1)	
								cout<<"  =   UNDEFINED"<<endl;				
							else
								cout<<"  =   "<<distancia[i]<<"Km"<<endl;
						
							city[i].visitado++;
						}	
					}
					if(i == 4 && city[0].visitado == 0)
						i=-1;				
				}	
				
				cout<<"====================================================="<<endl<<endl;			
				
				system("pause");
				break;
			}	
		}
		escolha = menu();	
	}	
	
	// Libera todos os Elementos do grafo alocado na memoria antes de finalizar o programa.
	Libera_Grafo(gr);
	
}

