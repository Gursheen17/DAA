#include <stdio.h>

#define INF 99999

int n, cost[10][10], visited[10];
int minCost = INF;

void tsp(int city, int count, int total) {
    if (count == n) {
        if (cost[city][0] != 0 && total + cost[city][0] < minCost)
            minCost = total + cost[city][0];
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            if (total + cost[city][i] < minCost) {
                visited[i] = 1;
                tsp(i, count + 1, total + cost[city][i]);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    if (minCost == INF)
        printf("No possible tour\n");
    else
        printf("Minimum Cost = %d\n", minCost);

    return 0;
}