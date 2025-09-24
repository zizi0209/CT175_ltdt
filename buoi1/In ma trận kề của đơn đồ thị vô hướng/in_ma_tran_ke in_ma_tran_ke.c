// Khai b�o h?ng v� thu vi?n
#include <stdio.h>

#define MAX_N 100

// C?u tr�c d? th? d�ng ma tr?n k?
typedef struct {
    int n, m;                    // n: s? d?nh, m: s? cung (th?c t? sau khi d?c)
    int A[MAX_N + 1][MAX_N + 1]; // 1..n; d�ng +1 cho ti?n 1-index
} Graph;

// Kh?i t?o d? th? n d?nh, 0 cung
void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;
    int i,j;
    for ( i = 1; i <= n; i++)
        for ( j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

// Th�m cung (u, v) cho d? th? v� hu?ng don
void add_edge(Graph *G, int u, int v) {
    // B? qua n?u u, v ngo�i ph?m vi
    if (u < 1 || v < 1 || u > G->n || v > G->n) return;

    // �? th? don: kh�ng t? kh�p, kh�ng nh�n da cung
    if (u == v) return;
    if (G->A[u][v] == 0) {
        G->A[u][v] = G->A[v][u] = 1;
        G->m++;
    }
}

int main(void) {
    Graph G;
    int n, m, u, v;

    // M? t?p tin d?u v�o
    FILE *f = fopen("dt1.txt", "r");
    if (!f) {
        perror("Khong mo duoc tep dt1.txt");
        return 1;
    }

    // �?c n, m v� kh?i t?o d? th?
    if (fscanf(f, "%d%d", &n, &m) != 2) {
        fprintf(stderr, "Dinh dang tep khong hop le.\n");
        fclose(f);
        return 1;
    }
    if (n > MAX_N) {
        fprintf(stderr, "So dinh vuot MAX_N=%d.\n", MAX_N);
        fclose(f);
        return 1;
    }
    init_graph(&G, n);
    int e;
    // �?c m d�ng cung v� th�m v�o d? th?
    for ( e = 0; e < m; e++) {
        if (fscanf(f, "%d%d", &u, &v) != 2) {
            fprintf(stderr, "Thieu du lieu cung o dong %d.\n", e + 2);
            fclose(f);
            return 1;
        }
        add_edge(&G, u, v);
    }
    fclose(f);
    int i,j;
    // In ma tr?n k? (0/1)
    for ( i = 1; i <= G.n; i++) {
        for ( j = 1; j <= G.n; j++) {
            printf("%d", G.A[i][j]);
            if (j < G.n) printf(" "); // c�ch ph?n t? b?ng 1 kho?ng tr?ng
        }
        printf("\n");
    }

    return 0;
}

