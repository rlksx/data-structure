# Explicações sobre o algoritmo de Dijkstra
O algoritmo de Dijkstra é uma solução para encontrar o menor caminho entre dois vértices de uma grafo ponderado(grafo que possui valor associado a cada aresta). Esse algoritmo funciona de maneira iterativa, onde ele atualiza as distancias do
vertice à medida que ele explora o grafo.  
Ele mantém um conjunto de vértices visitados e um conjunto de distâncias mínimas estimadas para cada vértice. Inicialmente, todas as distâncias são definidas como infinito, exceto a distância do vértice de origem, que é definida como zero.

## Sobre o Código
### Declaração do grafo
```
typedef struct
{
    int numVertices;
    int caminho[MAX_VERTICES][MAX_VERTICES];
} Grafo;

```

Aqui temos a declaração do grafo do qual possui um `int numVertices` que representa os numeros de vertices do grafo e `int caminho[MAX_VERTICES][MAX_VERTICES]` que corresponde as vertices, caminhos e distância, sendo o primeiro vetor `[MAX_VERTICES]` sendo a origem, o segundo o destino e o valor a distancia. Exemplo: `caminho[0][3] = 2;`
### Na Main
```
int main()
{   
    // declaração de variaveis
    char origem, destino;
    int vertices, distancia;
    Grafo grafo;

    // função que "abre" o arquivo para leitura ("r" => read)
    FILE *arquivo = fopen("../graph.txt", "r");

    // verifica se o arquivo foi lido com sucesso
    if (arquivo == NULL)
    {
        printf("Erro: Arquivo vazio!");
        return 1;
    }

    // recebe o numero de vertices contidos na primeira linha do grafo
    fscanf(arquivo, "%d", &vertices);

    // executa a função para iniciar o grafo, primeiramente não definindo caminho e distancia nenhuma
    inicializarGrafo(&grafo, vertices);
    while (fscanf(arquivo, " %c %c %d", &origem, &destino, &distancia) != EOF)
        adicionarAresta(&grafo, origem, destino, distancia);
    
    // "fecha" o arquivo
    fclose(arquivo);

    printf("Insira o ponto de origem: ");
    scanf(" %c", &origem);
    printf("Insira o ponto de destino: ");
    scanf(" %c", &destino);

    // executa função dijkstra
    dijkstra(&grafo, origem, destino);

    return 0;
}
```
