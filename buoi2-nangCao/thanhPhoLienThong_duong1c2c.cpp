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
		if((G->edges[i].u==u && G->edges[i].v==v)){
			return 1;
		}
	}
	return 0;
}
//Stack
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
//
int min(int a,int b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}
int num[MAX], min_num[MAX];
int k, scc, scc_cnt;
Stack S;
int on_stack[MAX];

void SCC(Graph *G,int u){
	num[u]=min_num[u]=k; k++;
	push(&S,u); on_stack[u]=1;
	int v;
	for(v=1;v<=G->n;v++){
		if(adjacent(G,u,v)){
			if(num[v]<0){
				SCC(G,v);
				min_num[u]=min(min_num[v],min_num[u]);
			}else if(on_stack[v]){
				min_num[u]=min(num[v],min_num[u]);
			}
		}
	}
	if(num[u]==min_num[u]){
		int w,cnt=0;
		do{
			w=top(&S); pop(&S);
			on_stack[w]=0;
			cnt++;
		}while(w!=u);
		scc_cnt++;
		if(cnt<G->n) scc=0;
	}
}

int main(){
	freopen("dt1.txt","r",stdin);
	int m,n,u,v,p,i;
	scanf("%d%d",&n,&m);
	Graph G; init_graph(&G,n);
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
		scanf("%d",&p);
		if(p==2) add_edge(&G,v,u);
	}
	//
	scc=1;
	for(i=1;i<=G.n;i++){
		num[i]=-1;
	}
	k=1; scc_cnt=0;
	makeNullStack(&S);
	for(i=1;i<=G.n;i++){
		if(num[i]==-1){
			SCC(&G,i);
		}
	}
	printf(scc_cnt==1? "OKIE":"NO");
	return 0;
}
