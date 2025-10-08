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
//BFS
typedef struct{
	int u,p;
}ElementType;
typedef struct{
	ElementType data[MAX];
	int front,rear;
}Queue;
void makeNullQueue(Queue *Q){
	Q->front=0;
	Q->rear=-1;
}
void enqueue(Queue *Q,ElementType x){
	Q->rear++;
	Q->data[Q->rear]=x;
}
void dequeue(Queue *Q){
	Q->front++;
}
int empty(Queue *Q){
	return Q->front>Q->rear;
}
ElementType front(Queue *Q){
	return Q->data[Q->front];
}
int mark[MAX];
int parent[MAX];
void BFS(Graph *G,int s){	
	Queue Q; makeNullQueue(&Q);
	ElementType pair;
	pair.u=s; pair.p=0; 	//gan pair.p= -1|0
	enqueue(&Q,pair);
	int v;
	while(!empty(&Q)){
		pair=front(&Q);
		int u=pair.u, p=pair.p;
		dequeue(&Q);
		if(mark[u]!=0){
			continue;
		}
		mark[u]=1; //bo print & gan lai tri cho parent
		parent[u]=p;
		for(v=1;v<=G->n;v++){
			if(adjacent(G,u,v) && mark[v]==0){
				pair.u=v;
				pair.p=u;
				enqueue(&Q,pair);
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
			BFS(&G,i);
		}
	}
	for(i=1;i<=G.n;i++){
		printf("%d %d\n",i,parent[i]);
	}
	return 0;
}
