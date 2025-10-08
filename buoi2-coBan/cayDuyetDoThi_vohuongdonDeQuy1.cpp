#include <stdio.h>
#define MAX 100
typedef struct{
	int u,v;
}Edge;
typedef struct{
	int m,n;
	Edge edges[MAX];
}Graph;
void init_graph(Graph *G,int n){
	G->n=n;
	G->m=0;
}
void add_edge(Graph *G,int u,int v){
	if((u>=1 && u<=G->n && v>=1 && v<=G->n) || u==v){ //
		G->edges[G->m].u=u;
		G->edges[G->m].v=v;
		G->m++;
	}
}
int adjacent(Graph *G,int u,int v){ //vo huong
	int i;
	for(i=0;i<G->m;i++){
		if((G->edges[i].u==u && G->edges[i].v==v) || (G->edges[i].u==v && G->edges[i].v==u)){
			return 1;
		}
	}
	return 0;
}
//DFS (De qui)
int mark[MAX];
int parent[MAX];
void DFS(Graph *G,int u,int p){
	if(mark[u]!=0){
		return; 	//khong continue nha
	}
	mark[u]=1;
	parent[u]=p;
	int v;
	for(v=1;v<=G->n;v++){
		if(adjacent(G,u,v) && mark[v]==0){
			DFS(G,v,u);
		}
	}
}

int main(){
	int n,m,u,v,i;
	freopen("dt.txt","r",stdin); //tren he thong bo dong nay
	scanf("%d%d",&n,&m);
	Graph G; init_graph(&G,n);
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	//
	for(i=1;i<=G.n;i++){
		mark[i]=0;
		parent[i]=-1;
	}
	for(i=1;i<=G.n;i++){
		if(mark[i]==0){
			DFS(&G,i,0);
		}
	}
	for(i=1;i<=G.n;i++){
		printf("%d %d\n",i,parent[i]);
	}
	return 0;
}
