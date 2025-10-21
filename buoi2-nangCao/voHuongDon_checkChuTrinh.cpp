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
	if((u>=1 && u<=G->n && v>=1 && v<=G->n)){
		G->edges[G->m].u=u;
		G->edges[G->m].v=v;
		G->m++;
	}
}
int adjacent(Graph *G, int u,int v){
	int i;
	for(i=0;i<G->m;i++){
		if((G->edges[i].u==u && G->edges[i].v==v) || (G->edges[i].u==v && G->edges[i].v==u)){
			return 1;
		}
	}
	return 0;
}
//DFS
//typedef int ElementType;
//typedef struct{
//	ElementType data[MAX];
//	int top_idx;
//}Stack;
//void makeNullList(Stack *S){
//	S->top_idx=-1;
//}
//int top(Stack *S){
//	return S->data[S->top_idx];
//}
//void push(Stack *S){
//	S->top_idx++;
//	S->data[S->top_idx];
//}
//void pop(Stack *S){
//	S->top_idx--;
//}
#define WHITE 0
#define GRAY 1
#define DARK 2
int color[MAX];
int has_circle;
void DFS(Graph *G,int u,int p){
	color[u]=GRAY;
	int v;
	for(v=1;v<=G->n;v++){
		if(adjacent(G,u,v)){
			if(v==p){
				continue;
			}else if(color[v]==WHITE){
				DFS(G,v,u);
			}else if(color[v]==GRAY){
				has_circle=1;
			}
		}
	}
	color[u]=DARK;
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
		color[i]=WHITE;
	}
	has_circle=0;
	for(i=1;i<=G.n;i++){
		if(color[i]==WHITE){
			DFS(&G,i,-1);
		}
	}
	if(has_circle){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}
