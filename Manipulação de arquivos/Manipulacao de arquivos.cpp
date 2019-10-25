/*
	FAP-Betim
	Disciplica:	Algoritimo e estutura de dados avançados.
	Exercicio:	Manipulação de arquivos.
	Autor:      Dhiullian Brando de Oliveira Santos.
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

// Estrutura de armazenamento de dados.
struct aluno
{
	int matricula;
	char nome[50],sexo;
};

// Função do menu.
int menu()
{
	int escolha;
	
	do
	{
		system("cls");
		cout<<"------------------------------------------------------"<<endl;
		cout<<"Escolha uma opção:"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<" [1] Criar um arquivo.                                "<<endl;
		cout<<" [2] Realizar a leitura de um arquivo.                "<<endl;
		cout<<" [3] Inserir dados no arquivo AlunosFap2019.txt.      "<<endl;
		cout<<" [4] Exibir informações do arquivo.                   "<<endl;
		cout<<" [5] Remover um cadastro pela matricula.              "<<endl;
		cout<<" [0] Encerrar o programa.                             "<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<"escolha:";
		cin>>escolha;
	}while(escolha<0 || escolha > 5);
	
	return escolha;
}
	
// Verificação de criação
void verifica(FILE *f)
{
	if ( f == NULL)
	{
		cout<<"Erro na criação do arquivo"<<endl;
		system("pause");
		exit(1);
	}
}

// Verificação de abertura do arquivo
void abrir(FILE *f)
{
	if ( f == NULL)
	{
		cout<<"Erro na abertura do arquivo!"<<endl;
		system("pause");
	}
}

int main ()
{
	setlocale(LC_ALL,"Portuguese");
	
	int escolha;
	FILE *f;
	aluno dado;
	
	// Inicialização do menú.
	escolha = menu();
	while (escolha != 0)
	{
		switch (escolha)
		{
			// [1] Criar arquivo
			case 1:
			{
				system("cls");					
				f = fopen("AlunosFap2019.txt","wb");	
				
				int adicionar;
				verifica(f);
				
				cout<<"Arquivo criado com Sucesso!"<<endl<<endl;					

				cout<<"Deseja inserir dados no arquivo [1]Sim [0]Não:";
				cin>>adicionar;
				system("cls");
			
				// Estrutura para inserção de dados	
				while(adicionar == 1)
				{
					system("cls");
					
					cout<<"Informe o nome do aluno:";
					fflush(stdin);
					gets(dado.nome);
					fflush(stdin);
					
					cout<<"Informe a matricula do aluno:";
					cin>>dado.matricula;
					
					cout<<"Informe o sexo do aluno:";
					cin>> dado.sexo;					
					dado.sexo = (char)toupper(dado.sexo);
					
					fwrite(&dado,sizeof(aluno),1,f);							
					
					system("cls");
					
					adicionar =2;
					while(adicionar < 0 || adicionar > 1)
					{
						cout<<"Continuar inserindo dados no arquivo [1]Sim [0]Não:";
						cin>>adicionar;
						system("cls");
					}								
				}
			
				fclose(f);
				break;	
			}
				
			// [2] Leitura de arquivo			
			case 2:
			{
				system("cls");				
				char c = 'a',nomeArquivo[20],comparativo[20] = {"ALUNOSFAP2019.TXT"};
				aluno aux;
				int anterior= -1;
				
				cout<<"Informe o nome do arquivo que será aberto:";
				fflush(stdin);
				gets(nomeArquivo);
				fflush(stdin);
				
				strupr(nomeArquivo);
				
				
				f = fopen (nomeArquivo,"rb");
				system("cls");
				abrir(f);
				
				if(f == NULL)
					break;
										
				cout<<"O conteudo do arquivo é :"<<endl;
				cout<<"---------------------------------------------"<<endl;			
				
				// Estrutura para impressão do arquivo AlunosFap2019 codificado pelo fwrite.
				if(strcmp(nomeArquivo,comparativo) == 0)
				{
					while (!feof(f))
					{
						fread(&aux,sizeof(aluno),1,f);
						
						if(anterior != aux.matricula)
						{
							cout<<"Nome:"<<aux.nome<<endl;
							cout<<"Matricula:"<<aux.matricula<<endl;
							cout<<"Sexo:"<<aux.sexo<<endl<<endl;
						}						
						anterior = aux.matricula;
					}
				}
				else
				{
					//Estrutura para impressão de outros arquivos
					while (c != EOF)
					{
						c = fgetc(f);
						if( c != EOF)
						cout<<c;
					}	
				}				
			 	
				fclose(f);
				cout<<endl;																	
				system("pause");
				break;
			}
			
			// [3] Inserção de dados no arquivo
			case 3:
			{
				system("cls");
				f = fopen("AlunosFap2019.txt","ab");
				int adicionar = 1;
				verifica(f);
				
				// Estrutura de inserção de registros.
				while(adicionar == 1)
				{
					system("cls");
					
					cout<<"Informe o nome do aluno:";
					fflush(stdin);
					gets(dado.nome);
					fflush(stdin);
					
					cout<<"Informe a matricula do aluno:";
					cin>>dado.matricula;
					
					cout<<"Informe o sexo do aluno:";
					cin>>dado.sexo;	
					dado.sexo = (char)toupper(dado.sexo);
					
					fwrite(&dado,sizeof(aluno),1,f);
							
					system("cls");
					
					adicionar =2;
					while(adicionar < 0 || adicionar > 1)
					{
						cout<<"Continuar inserindo dados no arquivo [1]Sim [0]Não:";
						cin>>adicionar;
						system("cls");
					}			
				}
			
				fclose(f);
				break;	
					
			}
			
			//[4] Exibir informações do arquivo.
			case 4:
			{
				system("cls");
				
				char linha[100];
				char *resultado,c = 'a',nomeArquivo[20],compara[20] = {"ALUNOSFAP2019.TXT"};
				int cmp = 0,cont_a = 0,cont_e = 0,cont_i = 0,cont_o = 0,cont_u = 0,cont_caractere = 0,anterior = -1;
				aluno aux;						
				
				cout<<"Informe o nome do arquivo que será aberto:";
				fflush(stdin);
				gets(nomeArquivo);
				fflush(stdin);
				
				system("cls");
				strupr(nomeArquivo);
				
				f = fopen(nomeArquivo,"rb");
				abrir(f);
								
				if(f == NULL)
					break;
				
				
				// Estrutura para analise do arquivo e contagem de vogais/outros caracteres.
				if(strcmp(nomeArquivo,compara) == 0)
				{				
					while(!feof(f))
					{
						fread(&aux,sizeof(aluno),1,f);
						for(int i = 0; i < strlen(aux.nome);i++)
						{
							if(anterior != aux.matricula)
							{
								cmp =toupper(aux.nome[i]);
																
								switch (cmp)
								{
									case 65:
										cont_a++;
										break;									
									case 69:
									{
										cont_e++;
										break;	
									}							
									case 73:
									{
										cont_i++;
										break;	
									}							
									case 79:
									{
										cont_o++;
										break;	
									}							
									case 85:
									{
										cont_u++;
										break;
									}							
									default:
									{
										cont_caractere++;
										break;	
									}
								}						
							}		
						}
						if(anterior != aux.matricula)
							cont_caractere++;
							
						anterior = aux.matricula;							
					}
				}
				else
				{
					while (c != EOF)
					{
						c = fgetc(f);
						cmp = toupper(c);
						switch (cmp)
						{
							case 65:
							{
								cont_a++;
								break;
							}						
							case 69:
							{
								cont_e++;
								break;	
							}							
							case 73:
							{
								cont_i++;
								break;	
							}							
							case 79:
							{
								cont_o++;
								break;	
							}							
							case 85:
							{
								cont_u++;
								break;
							}							
							default:
							{
								cont_caractere++;
								break;	
							}
						}											
					}	
				}
				
				fclose(f);
				
				f = fopen(nomeArquivo,"rb");
				verifica(f);				
				
				// Estrutura para realizar a contagem de linhas do arquivo
				int i = 1;
				if(strcmp(nomeArquivo,compara) == 0)
				{
					while (!feof(f))
					{
						fread(&aux,sizeof(aluno),1,f);
						
						if(anterior != aux.matricula)
						{
							i+=3;
						}						
						anterior = aux.matricula;
					}
				}
				else
				{																					
					while (!feof(f))
					{
						resultado = fgets(linha,100,f);
						i++;
					}	
				}
				//Saída do resultado.	
				cout<<endl<<"================================"<<endl;				
				cout<<"  Informaçoes do Arquivo    qtd "<<endl;
				cout<<"================================"<<endl;
				cout<<"  Número de linhas          "<<i-1<<endl;	
				cout<<"================================"<<endl;
				cout<<"  Número de vogais A        "<<cont_a<<endl;
				cout<<"================================"<<endl;
				cout<<"  Número de vogais E        "<<cont_e<<endl;
				cout<<"================================"<<endl;
				cout<<"  Número de vogais I        "<<cont_i<<endl;
				cout<<"================================"<<endl;
				cout<<"  Número de vogais O        "<<cont_o<<endl;
				cout<<"================================"<<endl;
				cout<<"  Número de vogais U        "<<cont_u<<endl;	
				cout<<"================================"<<endl;	
				cout<<"  Número de vogais          "<<cont_a + cont_e + cont_i + cont_o + cont_u<<endl;	
				cout<<"================================"<<endl;			
				cout<<"  Outros Caracteres         "<<cont_caractere<<endl;
				cout<<"================================"<<endl<<endl;
				
				fclose(f);
				system("pause");
				break;
			}
			
			// [5] Remover um cadastro pela matricula.
			case 5:
			{
				system("cls");
				FILE *bkp;
				aluno aux,remover;
				int compara;
								
				f = fopen("AlunosFap2019.txt","rb");
				bkp = fopen("Backup.txt","wb");
				
				cout<<"Informe a matricula que deve ser removida do arquivo:";
				cin>>compara;
				
				remover.matricula = -1;
						
				//Comparação de dados do arquivo para realizar a remoção.			
				while (!feof(f))
				{	
					fread(&aux,sizeof(aluno),1,f);
					
					if (aux.matricula != compara)
					{
						fwrite(&aux,sizeof(aluno),1,bkp);
					}
					else 
					{
						strcpy(remover.nome, aux.nome);
						remover.matricula = aux.matricula;
					}		
				}
				
				if (remover.matricula != -1)
					cout<<endl<<"O aluno "<<remover.nome<<" correspondente á matricula "<<remover.matricula<<" foi removido com sucesso."<<endl<<endl;
				else
					cout<<endl<<"A matricula "<<compara<<" não foi localizada no arquivo."<<endl<<endl;
				
				system("pause");
													
				fclose(f);
				fclose(bkp);
				
				int ret;
				remove("AlunosFap2019.txt");
				rename("backup.txt","AlunosFap2019.txt");				
				
				break;
			}

		}
		escolha = menu();
	}							
	
	
				
	fclose(f);
}

/* 
	Funções de manipulação de arquivos

   fputc -> Insere um caractere dentro do arquivo.
   fgetc -> realiza leitura de um caractere do arquivo.
   fputs -> Insere uma string de caracteres dentro do arquivo.
   fgets -> Realiza leitura de uma string dentro do arquivo.
   fwrite -> Escreve um bloco de bytes em um arquivo.
   fread -> Realiza leitura de um bloco de bytes de um arquivo.
   fprint -> Realiza a mesma função do printf porem ao armazena os dados informados no arquivo.
   fscanf -> Realiza a mesma função do scanf porem recebe os dados contidos no arquivo.
   fseek -> Realiza a busca dentro do arquivo para localizar partes desejadas. (SEEK_ ->SET 0 = INICIO ARQUIVO, CUR 1 = PONTO ATUALDO ARQUIVO,END 2 = FIM DO ARQUIVO)
   rewind -> função para retonar ao inicio do arquivo.
*/
