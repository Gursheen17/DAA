#include <stdio.h>

#define INF 9999

int main()
{
    int n, i, j;
    int cost[20][20];
    int visited[20] = {0};
    int edges = 0, min, u = -1, v = -1;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1)
        {
            printf("Graph is not connected.\n");
            return 0;
        }

        printf("Edge: %d - %d  Weight: %d\n", u, v, min);

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum Cost of MST = %d\n", totalCost);

    return 0;
}