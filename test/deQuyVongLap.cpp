//de qui voi vong lap (DFS vong lap)
#include <stdio.h>
#define MAX 100

typedef struct {
    int u, v;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX];
} Graph;

int mark[MAX];

void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v) {
    if (u >= 1 && u <= G->n && v >= 1 && v <= G->n) {
        G->edges[G->m].u = u;
        G->edges[G->m].v = v;
        G->m++;
    }
}

int adjacent(Graph *G, int u, int v) {
    for (int i = 0; i < G->m; i++) {
        if ((G->edges[i].u == u && G->edges[i].v == v) ||
            (G->edges[i].u == v && G->edges[i].v == u))
            return 1;
    }
    return 0;
}

// DFS phiên b?n 2: ch? g?i d? quy khi v chua duy?t
void DFS2(Graph *G, int u) {
    printf("%d ", u);
    mark[u] = 1;

    for (int v = 1; v <= G->n; v++) {
        if (adjacent(G, u, v) && !mark[v]) {
            DFS2(G, v);
        }
    }
}

int main() {
    Graph G;
    int n, m, u, v;
    freopen("dt.txt","r",stdin); //
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    // reset mark
    for (int i = 1; i <= n; i++)
        mark[i] = 0;

    // n?u d? th? không liên thông
    for (int i = 1; i <= n; i++) {
        if (!mark[i])
            DFS2(&G, i);
    }

    return 0;
}

