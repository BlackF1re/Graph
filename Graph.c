#include <stdio.h>
#include <stdlib.h>

void error()
{
    printf("Вы все сломали. В следующий раз вводите корректные значения.");
    exit(1);
}

int main()
{
    SetConsoleOutputCP(1251);
    int vertexCount, edgesCount, isDigit;

    printf("Введите количество вершин графа: ");
    isDigit = scanf_s("%d", &vertexCount);
    if (isDigit != 1 || vertexCount <= 0)
    {
        error();
    }

    printf("Введите количество ребер графа: ");
    isDigit = scanf_s("%d", &edgesCount);
    if (isDigit != 1 || edgesCount < 0 || edgesCount > vertexCount * (vertexCount-1) / 2)
    {
        error();
    }

    int** adjacencyMatrix = (int**)malloc(vertexCount * sizeof(int*));
    for (int i = 0; i < vertexCount; i++)
        adjacencyMatrix[i] = (int*)malloc(vertexCount * sizeof(int*));

    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    int source, destiny;
    printf("\nВведите ребра графа: \n");
    for (int i = 0; i < edgesCount; i++)
    {
        printf("Введите начало и конец ребра %d\n", i);
        scanf("%d", &source-1);
        if (source > edgesCount)
            error();

        scanf("%d", &destiny);
        if (destiny > edgesCount-1)
            error();
        adjacencyMatrix[source][destiny] = 1;
        adjacencyMatrix[destiny][source] = 1;
    }

    printf("\nСтепени всех вершин:\n");
    for (int i = 0; i < vertexCount; i++)
    {
        int degree = 0;
        for (int j = 0; j < vertexCount; j++)
        {
            degree += adjacencyMatrix[i][j];
        }
        printf("Вершина %d:\t%d\n", i, degree);
    }

    free(adjacencyMatrix);
    return 0;
}