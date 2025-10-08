#include <stdio.h>
typedef struct{
    int u,v;
}Edge;
typedef struct{
    int m,n;
    Edge edges[100];
}Graph;

void init_graph(Graph *G,int n){
    G->n=n;
    G->m=0;
}
void add_edge(Graph *G,int u, int v){
    if((u>=1 && u<=G->n && v>=1 && v<=G->n) || u==v){
        G->edges[G->m].u=u;
        G->edges[G->m].v=v;
        G->m++;
    }
}
int degree(Graph *G,int x){
    int i,deg=0;
    for(i=0;i<G->m;i++){
        if(G->edges[i].u==x){
            deg++;
        }
        if(G->edges[i].v==x){
            deg++;
        }
    }
    return deg;
}

int main(){
    Graph G;
    int n, m, u, v;
    FILE *f = fopen("dt.txt", "r");
    if (!f){
        perror("Khong mo duoc tep dt1.txt");
        G.n = 0; G.m = 0;
    }
    fscanf(f, "%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++){
        fscanf(f, "%d%d", &u, &v);
        add_edge(&G, u - 1, v - 1);   // file 1..n -> 0..n-1
    }
    fclose(f);
    //in
    int i;
    for(i=1;i<=G.n;i++){
        printf("deg(%d) = %d\n",i,degree(&G,i));
    }
    return 0;
}

