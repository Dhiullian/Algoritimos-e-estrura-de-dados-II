// Protótipo da struct.
typedef struct grafo Grafo;

// Protótipo da função de inialização do grafo.
Grafo *Cria_Grafo(int num_vertice, int grau_max, int eh_ponderado);

// Protótipo da função que libera a alocação dinamica do grafo.
void Libera_Grafo(Grafo *gr);

// Protótipo da função de inserção de arestas.
int Inserir_Aresta(Grafo *gr, int origem, int destino, int eh_digrafo, float peso);

// Protótipo da função de remoção de arestas.
int Remover_Aresta(Grafo *gr, int origem, int destino, int eh_digrafo);

// Protótipo da função que busca o menor caminho entre os elementos (Djikstra).
void Menor_Caminho_Grafo(Grafo *gr, int inicial, int *anterior, float *distancia);

// Protótipo da função que imprime o grafo.
void Imprime_Grafo(Grafo *gr,int city_origem,int *vet_cidade);

// Protótipo da função que imprime os relacionamentos do grafo.
void Imprime_Relacionamentos(Grafo *gr,int *vet_cidade);

// Protótipo da função que executa o menu do programa.
int menu();
