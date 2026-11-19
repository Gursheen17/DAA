#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}

int compare(const void *a, const void *b) {
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->w - e2->w;
}

int main() {
    int n, m, cost = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, m, sizeof(struct Edge), compare);

    printf("Minimum Spanning Tree:\n");

    for (int i = 0; i < m; i++) {
        int x = find(edges[i].u);
        int y = find(edges[i].v);

        if (x != y) {
            printf("%d - %d = %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(x, y);
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}