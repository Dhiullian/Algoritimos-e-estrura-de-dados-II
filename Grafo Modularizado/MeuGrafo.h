
typedef struct grafo Grafo;


Grafo *Cria_Grafo(int num_vertice, int grau_max, int eh_ponderado);

void Libera_Grafo(Grafo *gr);

int Inserir_Aresta(Grafo *gr, int origem, int destino, int eh_digrafo, float peso);

int Remover_Aresta(Grafo *gr, int origem, int destino, int eh_digrafo);

void Menor_Caminho_Grafo(Grafo *gr, int inicial, int *anterior, float *distancia);

void Imprime_Grafo(Grafo *gr,int city_origem,int *vet_cidade);

void Imprime_Relacionamentos(Grafo *gr,int *vet_cidade);

int menu();
