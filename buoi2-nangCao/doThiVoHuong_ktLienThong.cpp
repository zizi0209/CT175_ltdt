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
	if((u>=1 && u<=G->n && v>=1 && v<=G->n) || u==v){ //khuyen
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
typedef int ElementType;
typedef struct{
	ElementType data[MAX];
	int top_idx;
}Stack;
void makeNullStack(Stack *S){
	S->top_idx=-1;
}
int top(Stack *S){
	return S->data[S->top_idx];
}
void push(Stack *S,int x){
	S->top_idx++;
	S->data[S->top_idx]=x;
}
void pop(Stack *S){
	S->top_idx--;
}
int empty(Stack *S){
	return S->top_idx==-1;
}
int mark[MAX];
void DFS(Graph *G,int s){
	Stack S; makeNullStack(&S);
	push(&S,s);
	while(!empty(&S)){
		int v,u=top(&S);
		pop(&S);
		if(mark[u]!=0){
			continue;
		}
		mark[u]=1;
		for(v=1;v<=G->n;v++){
			if(adjacent(G,u,v) && mark[v]==0){
				push(&S,v);
			}
		}
	}
}
int connected(Graph *G){
	int u;
	for(u=1;u<=G->n;u++){
		mark[u]=0;
	}
	DFS(G,1);
	for(u=1;u<=G->n;u++){
		if(mark[u]==0){
			return 0;
		}
	}
	return 1;
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
	//
	if(connected(&G)){
		printf("connected");
	}else{
		printf("unconnected");
	}
	return 0;
}
