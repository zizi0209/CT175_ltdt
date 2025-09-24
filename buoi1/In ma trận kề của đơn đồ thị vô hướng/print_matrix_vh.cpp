#include <stdio.h>
#define MAX_N 100

typedef struct{
    int n, m;
    int A[MAX_N][MAX_N];   // 0..n-1
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G->A[i][j] = 0;
}

// add_edge 0-based
void add_edge(Graph *G, int u, int v){
    if (u < 0 || v < 0 || u >= G->n || v >= G->n) return;
    if (u == v) return;               // không t? khép
    if (G->A[u][v] == 0) {            // tránh da cung
        G->A[u][v] = G->A[v][u] = 1;  // vô hu?ng
        G->m++;
    }
}

// doc truc tiep tu "dt1.txt"
Graph read_graph(){
    Graph G;
    int n, m, u, v;
    FILE *f = fopen("dt1.txt", "r");
    if (!f){
        perror("Khong mo duoc tep dt1.txt");
        G.n = 0; G.m = 0;
        return G;
    }
    fscanf(f, "%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++){
        fscanf(f, "%d%d", &u, &v);
        add_edge(&G, u - 1, v - 1);   // file 1..n -> 0..n-1
    }
    fclose(f);
    return G;
}
// in
void print_graph(const Graph *G){
    for (int i = 0; i < G->n; i++){
        for (int j = 0; j < G->n; j++){
            printf("%d", G->A[i][j]);
            if (j < G->n - 1) printf(" ");
        }
        printf("\n");
    }
}

int main(void){
    Graph G = read_graph();
    if (G.n > 0) print_graph(&G);
    return 0;
}

