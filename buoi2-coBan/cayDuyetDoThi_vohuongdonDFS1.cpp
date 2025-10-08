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
//DFS
typedef struct{
	int u,p;
}ElementType;
typedef struct{
	ElementType data[MAX];
	int top_idx;
}Stack;
void makeNullStack(Stack *S){
	S->top_idx=-1;
}
void push(Stack *S, ElementType x){
	S->top_idx++;
	S->data[S->top_idx]=x;
}
void pop(Stack *S){
	S->top_idx--;
}
ElementType top(Stack *S){
	return S->data[S->top_idx];
}
int empty(Stack *S){
	return S->top_idx==-1;
}
int mark[MAX];
int parent[MAX];

void DFS(Graph *G, int s){
	Stack S; makeNullStack(&S);
	ElementType pair;
	pair.u=s; pair.p=0;
	push(&S,pair);
	int v;
	while(!empty(&S)){
		pair=top(&S);
		int u=pair.u, p=pair.p;
		pop(&S);
		if(mark[u]!=0){
			continue;
		}
		mark[u]=1;
		parent[u]=p;
		for(v=1;v<=G->n;v++){
			if(adjacent(G,u,v) && mark[v]==0){
				pair.u=v; pair.p=u;
				push(&S,pair);
			}
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
			DFS(&G,i);
		}
	}
	for(i=1;i<=G.n;i++){
		printf("%d %d\n",i,parent[i]);
	}
	return 0;
}
