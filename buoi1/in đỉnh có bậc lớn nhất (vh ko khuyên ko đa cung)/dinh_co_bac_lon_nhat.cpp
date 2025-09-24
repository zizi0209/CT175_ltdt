#include <stdio.h>

#define MAX_N 100

typedef struct {
    int A[MAX_N][MAX_N];
    int n;
} Graph;

// Kh?i t?o d? th? n d?nh, 0 cung
void init_graph(Graph* G, int n) {
    G->n = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

// Thêm cung (u, v) vào d? th? vô hu?ng
void add_edge(Graph* G, int u, int v) {
    if (u < 1 || v < 1 || u > G->n || v > G->n) return;
    if (u == v) return; // không có khuyên
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}

// Tính b?c c?a d?nh x
int deg(Graph* G, int x) {
    int d = 0;
    for (int v = 1; v <= G->n; v++)
        if (G->A[x][v] == 1)
            d++;
    return d;
}

int main() {
    //freopen("dt.txt", "r", stdin); // Khi test file, m? dòng này. Khi n?p bài nh? b? di.

    Graph G;
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    int max_deg = -1;
    int vertex = -1;

    for (int i = 1; i <= G.n; i++) {
        int d = deg(&G, i);
        if (d > max_deg || (d == max_deg && i < vertex)) {
            max_deg = d;
            vertex = i;
        }
    }

    printf("%d %d\n", vertex, max_deg);
    return 0;
}

