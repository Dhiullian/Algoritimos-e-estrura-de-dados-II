//Montar uma matriz de um grafo
#include <iostream>
#include <locale.h>
#include <ctype.h>//Biblioteca para convers�o de caracteres minusculos/maiusculo
using namespace std;

int menu()
{
	int escolha;
	
	do
	{
		system("cls");
		cout<<"------------------------------------------------------"<<endl;
		cout<<"Escolha uma op��o:"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<" [1] Informar a posi��o da aresta.                    "<<endl;
		cout<<" [2] Exibir a matriz de adjacencia e relacionamentos. "<<endl;
		cout<<" [3] Remover rela��o do grafo.                        "<<endl;
		cout<<" [0] Encerrar o programa.                             "<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<"escolha:";
		cin>>escolha;
	}while(escolha<0 || escolha > 3);
	
	return escolha;
}	

int main ()
{
	setlocale(LC_ALL,"Portuguese");
//Declara��o de variaveis
	int indice_coluna = 65,indice_linha = 65;//Letra inicial A
	int vertice,escolha,linha,coluna;
	
//Receber quantidade vertices
	cout<<"Informe a quantidade de vertices:";
	cin>>vertice;
//Declara��o da matriz
	int grafo[vertice][vertice]={};
//Inicializando a matriz preenchida com 0
	cout<<endl<<"Sua Matriz adjacente ter� a seguinte forma:"<<endl<<endl;
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
//Inicializa��o do menu	
	escolha=menu();
	while (escolha != 0)
	{
		switch (escolha)
		{
		
			// [1] Informar a posi��o da aresta.
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
					cout<<endl<<"Foi alterada a posi��o "<<linha+1<<" X "<<coluna+1<<endl<<endl;
				}
				else
				{
					system("cls");
					cout<<endl<<"A posi��o informada � invalida!!!"<<endl<<endl;
				}
				system("pause");
				break;
			//	[2] Exibir a matriz de adjacencia e relacionamentos.  
			case 2:
				system("cls");
				indice_linha=65;
				indice_coluna=65;
				for(int i=-1 ; i < vertice ; i++)
				{
					if(i >= 0)
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
				cout<<endl<<"Rela��o de orienta��o do grafo:"<<endl<<endl;
				for (int i=0; i < vertice; i++)
				{
					indice_linha = 65;
					indice_linha += i;
					for (int j=0; j<vertice; j++)
					{
						indice_coluna =65;
						indice_coluna += j;
						if( (grafo[i][j]) == 1)
						{
							cout<<"["<<(char)indice_linha<<"]-->"<<"["<<(char)indice_coluna<<"]"<<endl<<endl;
						}
					}
				}
				system("pause");
				break;
				
			case 3:
				system("cls");
				char l_linha,l_coluna;
				indice_linha=65;
				indice_coluna=65;
				for(int i=-1 ; i < vertice ; i++)
				{
					if(i >= 0)
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
				cout<<endl<<endl<<"Informe de qual linha voc� deseja remover um relacionamento:";
				cin>>l_linha;
				system("cls");
				cout<<"Rela��es do vertice "<<(char)toupper(l_linha)<<":"<<endl<<endl;
				for (int i=0; i < vertice; i++)
				{
					indice_linha = 65;
					indice_linha += i;
					for (int j=0; j<vertice; j++)
					{
						indice_coluna =65;
						indice_coluna += j;
						if( (grafo[i][j]) == 1 && toupper(l_linha) == indice_linha)
						{
							cout<<"["<<(char)indice_linha<<"]-->"<<"["<<(char)indice_coluna<<"]"<<endl;
						}
					}
				}
				
				//Encontrar o erro para exibir caso a letra informada n�o tenha um relacionamento
				cout<<endl<<"Com qual vertice ser� o relacionamento removido:";
				cin>>l_coluna;
				int validacao=0;;
				for( int i=0 ;i < vertice; i++)
				{
					indice_linha = 65;
					indice_linha+=i;					
					for (int j=0; j< vertice;j++)
					{
						indice_coluna=65;
						indice_coluna+=j;
						if(toupper(l_linha) == indice_linha && toupper(l_coluna) == indice_coluna && grafo[i][j] == 1)
						{
							grafo[i][j] =0;
							validacao=1;
							break;
						}						
					}
					if(validacao == 1)
						break;
				}
				system("cls");
				if(validacao == 1)
				{
					cout<<endl<<"O relacionamento ["<<(char)toupper(l_linha)<<"]-->["<<(char)toupper(l_coluna)<<"] foi removido com sucesso!"<<endl<<endl;
				}			
				else
					cout<<endl<<"N�o existe um relacionamento entre os vertices informados!"<<endl<<endl;
				system("pause");
				break;				
		}
		escolha = menu();
	}
	
}
