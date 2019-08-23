//Montar uma matriz adjacente de um grafo
#include <iostream>
#include <locale.h>
using namespace std;

int menu()
{
	int escolha;
	
	do
	{
		system("cls");
		cout<<"----------------------------------------------"<<endl;
		cout<<"Escolha uma opção:"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<" [1] Informar a posição da aresta.            "<<endl;
		cout<<" [2] Exibir a matriz de adjacencia.           "<<endl;
		cout<<" [0] Encerrar o programa.                     "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"escolha:";
		cin>>escolha;
	}while(escolha<0 || escolha > 2);
	
	return escolha;
}	

int main ()
{
	setlocale(LC_ALL,"Portuguese");
//Declaração de variaveis
	int indice_coluna = 65,indice_linha = 65;//Letra inicial A
	int vertice,escolha,linha,coluna;
	
//Receber quantidade vertices
	cout<<"Informe a quantidade de vertices:";
	cin>>vertice;
//Declaração da matriz
	int grafo[vertice][vertice]={};
//Inicializando a matriz com 0
	cout<<endl<<"Sua Matriz adjacente terá a seguinte forma:"<<endl<<endl;
	for(int i=-1 ; i < vertice ; i++)
	{
		if(i >=0)
		{
		cout<<char(indice_linha);
		indice_linha++;
		}
		
		for(int j= 0 ; j < vertice ; j++)
		{
			if (i == -1)
			{
				cout<<"  "<<(char)indice_coluna;
				indice_coluna++;	
			}
			else
			{
				if(j == 0)
					cout<<" "<<grafo[i][j];					
				else
					cout<<"  "<<grafo[i][j];
			}
			
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	system("pause");
	system("cls");
//Inicialização do menu	
	escolha=menu();
	while (escolha != 0)
	{
		switch (escolha)
		{
		
			// [1] Informar a posição da aresta.
			case 1:
				system("cls");
				cout<<"Informe a Linha do vertice:";
				cin>>linha;
				cout<<"Informe a Coluna do vertice:";			
				cin>>coluna;
				linha--;
				coluna--;
				if (linha < vertice && coluna < vertice)
				{			
					system("cls");
					grafo[linha][coluna] =1;
					cout<<endl<<"Foi alterada a posição "<<linha+1<<" X "<<coluna+1<<endl<<endl;
				}
				else
				{
					system("cls");
					cout<<endl<<"A posição informada é invalida!!!"<<endl<<endl;
				}
				system("pause");
				break;
			//	[2] Exibir a matriz de adjacencia.  
			case 2:
				system("cls");
				indice_linha=65;
				indice_coluna=65;
				for(int i=-1 ; i < vertice ; i++)
				{
					if(i >=0)
					{
					cout<<char(indice_linha);
					indice_linha++;
					}
					
					for(int j= 0 ; j < vertice ; j++)
					{
						if (i == -1)
						{
							cout<<"  "<<(char)indice_coluna;
							indice_coluna++;	
						}
						else
						{
							if(j == 0)
								cout<<" "<<grafo[i][j];					
							else
								cout<<"  "<<grafo[i][j];
						}
						
					}
					cout<<endl;
				}
	cout<<endl<<endl;
				system("pause");
				break;
		}
		escolha = menu();
	}
	
}
