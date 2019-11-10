#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "MeuGrafo.h"
using namespace std;

// Estrutura de armazenamento dos dados.
struct grafo
{
	int eh_ponderado;
	int num_vertice;
	int grau_max;
	int **arestas;
	float **valores;
	int *grau;
};

// Inicialização do grafo.
Grafo *Cria_Grafo(int num_vertice, int grau_max, int eh_ponderado)
{
	// Alocação dinamica para a estrutura do grafo.
	Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
	
	// Verificação se o grafo é NULL (Inexistente).
	if (gr != NULL)
	{
		int i;
		
		gr->num_vertice = num_vertice;
		gr->grau_max = grau_max;
		gr->eh_ponderado = (eh_ponderado != 0) ? 1 :0;
		gr->grau = (int*) calloc(num_vertice,sizeof(int));
		gr->arestas = (int**) malloc(num_vertice*sizeof(int*));
		
		for (i = 0; i < num_vertice; i++)
			gr->arestas[i] = (int*) malloc(grau_max*sizeof(int));
				
		if (gr->eh_ponderado)
		{
			gr->valores = (float**) malloc(num_vertice*sizeof(float*));
			
			for (i = 0; i < num_vertice; i++)
				gr->valores[i] = (float*) malloc(grau_max*sizeof(float));
		}	
	}
	// Retorna a estrutura criada.
	return gr;
}

// Liberação da memória alocada.
void Libera_Grafo(Grafo *gr)
{
	if (gr != NULL)
	{
		int i;
		for ( i = 0; i < gr->num_vertice; i++)
			free(gr->arestas[i]);
		free(gr->arestas);
		
		if (gr->eh_ponderado)
		{
			for ( i = 0; i < gr->num_vertice; i++)
				free(gr->valores[i]);
			free(gr->valores);
		}
		free(gr->grau);
		free(gr);
	}
}

// Inserção de arestas no grafo.
int Inserir_Aresta(Grafo *gr, int origem, int destino, int eh_digrafo, float peso )
{
	//Verificação de existencia do grafo e dos vertices.
	if (gr == NULL)
		return 0;
	if (origem < 0 || origem >= gr->num_vertice)
		return 0;
	if (destino < 0 || destino >= gr->num_vertice)
		return 0;
	
	// Verificação da posição da aresta e alocação.
	gr->arestas[origem][gr->grau[origem]] = destino;
	if (gr->eh_ponderado)
		gr->valores[origem][gr->grau[origem]] = peso;
	gr->grau[origem]++;
	
	// Verificação se o grafo não é digrafo, para realizar a inserção da aresta que retorna.
	if (eh_digrafo == 0)
		Inserir_Aresta(gr,destino,origem,1,peso);
	return 1;
}

// Remoção de arestas do grafo.
int Remover_Aresta(Grafo *gr, int origem, int destino, int eh_digrafo)
{
	// Verificação de existencia do grafo e dos vertices.
	if (gr == NULL)
		return 0;
	if (origem < 0 || origem >= gr->num_vertice)
		return 0;
	if (destino < 0 || destino >= gr->num_vertice)
		return 0;
		
	int i = 0;
	
	while (i < gr->grau[origem] && gr->arestas[origem][i] != destino)
		i++;
		
	// Elemento não encontrado.
	if( i == gr->grau[origem])
		return 0;
		
	gr->grau[origem]--;
	
	// remove uma aresta e realoca a ultima aresta da matriz no seu lugar.
	gr->arestas[origem][i] = gr->arestas[origem][gr->grau[origem]];
	
	if (gr->eh_ponderado)
		gr->valores[origem][i] = gr->valores[origem][gr->grau[origem]];
		
	if (eh_digrafo == 0)
		Remover_Aresta(gr,destino,origem,1);
}

// Funcão para localizar a menor distancia.
int Procura_Menor_Distancia (float *distancia, int *visitado, int n_vertice)
{
	int i, menor = -1, primeiro = 1;
	for( i = 0 ; i < n_vertice; i++)
	{
		if (distancia[i] >= 0 && visitado[i] == 0)
		{
			if (primeiro)
			{
				menor = i;
				primeiro = 0;
			}
			else
			{
				if (distancia[menor] > distancia[i])
					menor = i;
			}
		}
	}
	return menor;
}

// Função djikstra para calcular menor caminho.
void Menor_Caminho_Grafo(Grafo *gr, int inicial, int *anterior, float *distancia)
{
	int i, cont, n_vertice, ind,*visitado, vert;
	cont = n_vertice = gr->num_vertice;
	visitado = (int*) malloc(n_vertice * sizeof(int));
	
	for (i = 0; i < n_vertice; i++)
	{
		anterior[i] = -1;
		distancia[i] = -1;
		visitado[i] = 0;
	}
	
	distancia [inicial] = 0;
	
	while(cont > 0)
	{
		vert = Procura_Menor_Distancia (distancia,visitado, n_vertice);
		if( vert == -1)
			break;
		
		visitado[vert] = 1;
		cont--;
		
		for (i = 0; i < gr->grau[vert]; i++)
		{
			ind = gr->arestas[vert][i];
			if(distancia[ind] < 0)
			{
				distancia[ind] = distancia[vert] + gr->valores[vert][i];
				anterior[ind] = vert;
			}
			else if (distancia[ind] > distancia[vert] + gr->valores[vert][i])
			{
				distancia[ind] = distancia[vert] + gr->valores[vert][i];
				anterior[ind] = vert;
			}		
		}
	}
	free(visitado);
}

// Imprimir grafo.
void Imprime_Grafo(Grafo *gr, int city_origem,int *vet_cidade)
{
   
	int cont_vet = 0;
   
    if(gr == NULL)
        return;

    int i, j;
    
    // Envia para o vet_cidade o id das cidades presente em cada aresta do grafo.
    for(i=0; i < gr->num_vertice; i++)
	{
        for(j=0; j < gr->grau[i]; j++)
		{
			if(i == city_origem)
			{
				vet_cidade[cont_vet] = i;				
				vet_cidade[cont_vet+1] = gr->arestas[i][j];
				
            	cont_vet+=2;
			}
			
        }
    }
}

// Imprime relacionamentos.
void Imprime_Relacionamentos(Grafo *gr,int *vet_cidade)
{
   
	int cont_vet = 0;
   
    if(gr == NULL)
        return;

    int i, j;
    
    // Envia para o vet_cidade as relações presentes no grafo.
    for(i=0; i < gr->num_vertice; i++)
	{
        for(j=0; j < gr->grau[i]; j++)
		{
				vet_cidade[cont_vet] = i;				
				vet_cidade[cont_vet+1] = gr->arestas[i][j];
				
            	cont_vet+=2;			
        }
    }
}

// Imprime o menu.
int menu()
{
	int escolha;
	
	do
	{
		system("cls");
		cout<<"------------------------------------------------------"<<endl;
		cout<<"Escolha uma opção:"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<" [1] Inserir aresta.                                  "<<endl;
		cout<<" [2] Exibir lista de relacionamentos do grafo.        "<<endl;
		cout<<" [3] Remover aresta.                                  "<<endl;
		cout<<" [4] Exibir o menor Caminho (Djikstra).               "<<endl;
		cout<<" [5] Exibir o matriz de adjacencia.                   "<<endl;
		cout<<" [0] Encerrar o programa.                             "<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<"escolha:";
		cin>>escolha;
	}while(escolha<0 || escolha > 5);
	
	return escolha;
}
