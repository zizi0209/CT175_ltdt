//dacung cohuong (lien thong manh)!?
//van la lien thong bth (tailieuMTT)
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
	if((u>=1 && u<=G->n && v>=1 && v<=G->n) || u==v){
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
typedef int ElementType;
typedef struct{
	ElementType data[MAX];
	int top_idx;
}Stack;
void makeNullStack(Stack *S){
	S->top_idx=-1;
}
void push(Stack *S,int x){
	S->top_idx++;
	S->data[S->top_idx]=x;
}
void pop(Stack *S){
	S->top_idx--;
}
int top(Stack *S){
	return S->data[S->top_idx];
}
int empty(Stack *S){
	return S->top_idx==-1;
}
int mark[MAX];
void DFS(Graph *G,int s){
	Stack S;
	makeNullStack(&S);
	push(&S,s);
	while(!empty(&S)){
		int v,u=top(&S);
		pop(&S);
		if(mark[u]!=0){
			continue;
		}
		//printf("%d\n",u);
		mark[u]=1;
		for(v=G->n;v>=1;v--){
			if(adjacent(G,u,v)){
				if(mark[v]==0){
					push(&S,v);
				}
			}
		}
	}
}
//kt tinh lien thong
void connect(Graph *G){
	int u;
	for(u=1;u<=G->n;u++){
		mark[u]=0;
	}
	DFS(G,1);
	for(u=1;u<=G->n;u++){
		if(mark[u]==0){
			printf("KHONG");
			return;
		}
	}
	printf("DUOC");
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
	connect(&G);
	return 0;
}
