/*===BAT DAU==*/
#include <stdio.h>
#define MAX 100
//Ma tran ke (ma tran dinh dinh)
typedef struct{
	int m,n;
	int A[MAX][MAX];
}Graph;
void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
	int u,v;
	for(u=1;u<=G->n;u++){
		for(v=1;v<=G->n;v++){
			G->A[u][v]=0;
		}
	}
}
void add_edge(Graph *G, int u,int v){
	if((u>=1 && u<=G->n && v>=1 && v<=G->n)){ //khuyen || u==v
		G->A[u][v]=1;
		G->A[v][u]=1;
		G->m++;
	}
}
int adjacent(Graph *G, int u,int v){
	return G->A[u][v]>0;
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
//DFS
int mark[MAX];
void DFS(Graph *G,int s){
	Stack S; makeNullStack(&S);
	push(&S,s);
	while(!empty(&S)){
		int v,u=top(&S);
		pop(&S);
		if(mark[u]!=0) continue;
		mark[u]=1;
		for(v=1;v<=G->n;v++){
			if(adjacent(G,u,v) && mark[v]==0){
				push(&S,v);
			}
		}
	}
}
int connected_components(Graph *G){
	int i;
	for(i=0;i<G->m;i++){
		mark[i]=0;
	}
	DFS(G,1);
	int cnt=1;
	for(i=1;i<=G->n;i++){
		if(mark[i]==0){
			DFS(G,i);
			cnt++;
		}
	}
	return cnt;
}
/*===KET THUC==*/
int main() {
	freopen("dt.txt","r",stdin);
    Graph G;
    int m, n, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 1; e <= m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G.A[u][v] = G.A[v][u] = 1;
    }
    
    printf("%d\n", connected_components(&G));
    return 0;
}
//int main(){
//	freopen("dt.txt","r",stdin);
//	int m,n,u,v,i;
//	scanf("%d%d",&n,&m);
//	Graph G; init_graph(&G,n);
//	for(i=0;i<m;i++){
//		scanf("%d%d",&u,&v);
//		add_edge(&G,u,v);
//	}
//	//
//	printf("%d\n", connected_components(&G));
//	return 0;
//}
