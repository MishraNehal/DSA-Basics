#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void union_set(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

int main() {
    int n = 5; // nodes
    int m = 6; // edges

    struct Edge edges[] = {
        {0, 1, 1},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 5},
        {3, 4, 6}
    };

    for (int i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, m, sizeof(edges[0]), compare);

    int total_weight = 0;
    printf("MST Edges:\n");

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            union_set(u, v);
            total_weight += w;
            printf("%d - %d (weight: %d)\n", u, v, w);
        }
    }

    printf("Total weight: %d\n", total_weight);
    return 0;
}
