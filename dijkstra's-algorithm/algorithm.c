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
int encontrarMenorDistancia(int distancia[], int vistados[], int vertices);
void imprimirCaminho(int verticesPais[], int destino);
void dijkstra(Grafo *grafo, char origem, char destino);

int main()
{
    char origem, destino;
    int vertices, distancia;
    Grafo grafo;

    FILE *arquivo = fopen("../graph.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro: Arquivo vazio!");
        return 1;
    }

    fscanf(arquivo, "%d", &vertices);

    inicializarGrafo(&grafo, vertices);
    while (fscanf(arquivo, " %c %c %d", &origem, &destino, &distancia) != EOF)
    {
        adicionarAresta(&grafo, origem, destino, distancia);
    }

    fclose(arquivo);

    printf("Insira o ponto de origem : ");
    scanf("%c", &origem);
    printf("Insira o ponto de destino: ");
    scanf(" %c", destino);

    dijkstra(&grafo, origem, destino);

    return 0;
}

void inicializarGrafo(Grafo *grafo, int vertices)
{
    grafo->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            grafo->caminho[i][j] = 0;
        }
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
        int u = encontrarMenorDistancia(distancias, visitados, grafo->caminho);
        visitados[u] = 1;
        for (int j = 0; j < grafo->numVertices; j++)
        {
            if (!visitados[j] && grafo->caminho[u][j] && distancias[u] != INT_MAX && distancias[u] + grafo->caminho[u][j] < distancias[j])
            {
                distancias[j] = distancias[u] + grafo->caminho[u][j];
                verticesPais[j] = u;
            }
        }

        printf("A caminho entre %c e %c: ", origem, destino);
        imprimirCaminho(verticesPais, indexDestino);
        printf("\nDistancia total: %d\n", distancias[indexDestino]);
    }
