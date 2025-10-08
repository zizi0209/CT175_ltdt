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
    if(u>=1 && u<=G->n && v>=1 && v<=G->n){
        G->edges[G->m].u=u;
        G->edges[G->m].v=v;
        G->m++;
    }
}
int adjacent(Graph *G,int u,int v){	//do thi vo huong don
	int i;
	for(i=0;i<G->m;i++){
		if((G->edges[i].u==u && G->edges[i].v==v) || (G->edges[i].u==v && G->edges[i].v==u)){
			return 1;
		}
	}
	return 0;
}
//BFS
typedef int ElementType;
typedef struct{
	ElementType data[MAX];
	int front,rear;
}Queue;
void make_null_queue(Queue *Q){
	Q->front=0;
	Q->rear=-1;
}
void enqueue(Queue *Q,int s){
	Q->rear++;
	Q->data[Q->rear]=s;
}
void dequeue(Queue *Q){
	Q->front++;
}
int empty(Queue *Q){
	return Q->front>Q->rear;
}
int front(Queue *Q){
	return Q->data[Q->front];
}
int mark[MAX];
void BFS(Graph *G,int s){
	Queue Q;
	make_null_queue(&Q);
	enqueue(&Q,s);
	while(!empty(&Q)){
		int v,u=front(&Q);
		dequeue(&Q);
		if(mark[u]!=0){
			continue;
		}
		mark[u]=1;
		printf("%d\n",u);
		for(v=1;v<=G->n;v++){
			if(adjacent(G,u,v)){
				if(mark[v]==0){
					enqueue(&Q,v);
				}
			}
		}
	}
}

int main(){
    freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
		
	for (e = 0; e < m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G, u, v);
	}
	
	for(e=1;e<=G.n;e++){
		mark[e]=0;
		BFS(&G,1);
	}
	return 0;
}
