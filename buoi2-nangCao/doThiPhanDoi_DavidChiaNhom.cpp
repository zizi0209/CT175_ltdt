#include <stdio.h>
#define MAX 100
typedef struct{
	int u,v;
}Edge;
typedef struct{
	int m,n;
	Edge edges[MAX];
}Graph;
void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
}
void add_edge(Graph *G, int u,int v){
	if((u>=1 && u<=G->n && v>=1 && v<=G->n)){ //khuyen || u==v
		G->edges[G->m].u=u;
		G->edges[G->m].v=v;
		G->m++;
	}
}
int adjacent(Graph *G, int u,int v){
	int i;
	for(i=0;i<G->m;i++){
		if((G->edges[i].u==u && G->edges[i].v==v) || (G->edges[i].u==v && G->edges[i].v==u)){ //
			return 1;
		}
	}
	return 0;
}
//
#define NO_COLOR -1
#define BLUE 1
#define RED 2
int color[MAX];
int conflict;
void colorize(Graph *G,int u,int c){
	color[u]=c;
	int v;
	for(v=1;v<=G->n;v++){
		if(adjacent(G,u,v)){
			if(color[v]==NO_COLOR){
				colorize(G,v,3-c);
			}else if(color[v]==color[u]){
				conflict=1;
			}
		}
	}
}

int main(){
	freopen("dt.txt","r",stdin);
	int m,n,u,v,i;
	scanf("%d%d",&n,&m);
	Graph G; init_graph(&G,n);
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(i=1;i<=G.n;i++){
		color[i]=NO_COLOR;
	}
	for(i=1;i<=G.n;i++){
		if(color[i]==NO_COLOR){
			colorize(&G,i,BLUE);
		}
	}
	if(conflict){
		printf("IMPOSSIBLE");
	}else{
		for(i=1;i<=G.n;i++){
			if(color[i]==BLUE){
				printf("%d ",i);
			}
		}
		printf("\n");
		for(i=1;i<=G.n;i++){
			if(color[i]==RED){
				printf("%d ",i);
			}
		}
	}
	return 0;
}
