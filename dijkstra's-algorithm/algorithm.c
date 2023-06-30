#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 50

typedef struct
{
    int numVertices;
    int caminho[MAX_VERTICES][MAX_VERTICES];
} Grafo;

void inicializarGrafo(Grafo *grafo, int vertices);
void adicionarAresta(Grafo *grafo, char origem, char destino, int distancia);
int encontrarMenorDistancia(int distancia[], int visitados[], int vertices);
void imprimirCaminho(int verticesPais[], int destino);
void dijkstra(Grafo *grafo, char origem, char destino);

int main()
{
    char origem, destino;
    int numVertices, distancia;
    Grafo grafo;

    FILE *arquivo = fopen("../graph.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro: Ocorreu um erro durante a leitura do arquivo!");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);

    inicializarGrafo(&grafo, numVertices);
    while (fscanf(arquivo, " %c %c %d", &origem, &destino, &distancia) != EOF)
        adicionarAresta(&grafo, origem, destino, distancia);
    

    fclose(arquivo);

    printf("Insira o ponto de origem: ");
    scanf(" %c", &origem);
    printf("Insira o ponto de destino: ");
    scanf(" %c", &destino);

    dijkstra(&grafo, origem, destino);

    return 0;
}

void inicializarGrafo(Grafo *grafo, int vertices)
{
    grafo->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            grafo->caminho[i][j] = 0;
        
    }
}

void adicionarAresta(Grafo *grafo, char origem, char destino, int distancia)
{
    int indexOrigem = origem - 'A';
    int indexDestino = destino - 'A';
    grafo->caminho[indexOrigem][indexDestino] = distancia;
}

void dijkstra(Grafo *grafo, char origem, char destino)
{
    int distancias[MAX_VERTICES];
    int visitados[MAX_VERTICES];
    int verticesPais[MAX_VERTICES];

    for (int i = 0; i < grafo->numVertices; i++)
    {
        distancias[i] = INT_MAX;
        visitados[i] = 0;
        verticesPais[i] = -1;
    }

    int indexOrigem = origem - 'A';
    int indexDestino = destino - 'A';

    distancias[indexOrigem] = 0;

    for (int i = 0; i < grafo->numVertices - 1; i++)
    {
        int aux = encontrarMenorDistancia(distancias, visitados, grafo->numVertices);
        visitados[aux] = 1;
        for (int j = 0; j < grafo->numVertices; j++)
        {
            if (!visitados[j] && grafo->caminho[aux][j] && distancias[aux] != INT_MAX && distancias[aux] + grafo->caminho[aux][j] < distancias[j])
            {
                distancias[j] = distancias[aux] + grafo->caminho[aux][j];
                verticesPais[j] = aux;
            }
        }
    }

    printf("Caminho entre %c e %c: ", origem, destino);
    imprimirCaminho(verticesPais, indexDestino);
    printf("\nDistancia total: %d\n", distancias[indexDestino]);
}

int encontrarMenorDistancia(int distancias[], int visitados[], int vertices)
{
    int min = INT_MAX;
    int indiceMin;

    for (int i = 0; i < vertices; i++)
    {
        if (!visitados[i] && distancias[i] <= min)
        {
            min = distancias[i];
            indiceMin = i;
        }
    }

    return indiceMin;
}

void imprimirCaminho(int verticesPais[], int destino)
{
    if (verticesPais[destino] == -1)
    {
        printf("%d ", destino);
        return;
    }

    imprimirCaminho(verticesPais, verticesPais[destino]);
    printf("%d ", destino);
}
