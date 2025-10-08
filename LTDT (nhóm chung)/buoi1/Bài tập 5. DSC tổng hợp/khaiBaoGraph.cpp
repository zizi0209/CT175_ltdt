#include <stdio.h>
#define MAX 100
/* B? sung khai báo CTDL Graph và cài d?t các hàm c?n thi?t */
typedef struct{
	int u,v;
}Edge;
typedef struct{
	int m,n;
	Edge edges[MAX];
}Graph;
/* H?t ph?n mã l?nh c?a b?n */
void init_graph(Graph *G,int n){
	G->n=n;
	G->m=0;
}
void add_edge(Graph *G,int x,int y){
	G->edges[G->m].u=x;
	G->edges[G->m].v=y;
	G->m++;
}
int degree(Graph *G,int x){
	int i,deg=0;
	for(i=0;i<G->m;i++){
		if(G->edges[i].u==x){
			deg++;
		}
		if(G->edges[i].v==x){
			deg++;
		}
	}
	return deg;
}
//Hàm main()
int main() {
    Graph G;
    int n = 4, u;

    //Kh?i t?o d? th?
    init_graph(&G, n);
    //Thêm cung vào d? th?
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 1, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 1, 4);

    //In b?c c?a các d?nh
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;
}
