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
    int n,m;
    scanf("%d%d",&n,&m);
    Graph G; init_graph(&G,n);
    int i,u,v;
    for(i=0;i<G.m;i++){
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }
    //in
    for(i=1;i<=G.n;i++){
        printf("deg(%d) = %d\n",i,degree(&G,i));
    }
}
