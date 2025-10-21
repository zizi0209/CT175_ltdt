#include <stdio.h>
#define MAX 100

// --- C?u trúc d? li?u d? th? (Không thay d?i) ---
typedef struct {
    int u, v;
} Edge;

typedef struct {
    int m, n;
    Edge edges[MAX];
} Graph;

void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v) {
    if ((u >= 1 && u <= G->n && v >= 1 && v <= G->n)) {
        G->edges[G->m].u = u;
        G->edges[G->m].v = v;
        G->m++;
    }
}

int adjacent(Graph *G, int u, int v) {
    int i;
    for (i = 0; i < G->m; i++) {
        if (G->edges[i].u == u && G->edges[i].v == v) {
            return 1;
        }
    }
    return 0;
}

// --- C?u trúc d? li?u Stack (Không thay d?i) ---
typedef int ElementType;
typedef struct {
    ElementType data[MAX];
    int top_idx;
} Stack;

void makeNullStack(Stack *S) {
    S->top_idx = -1;
}

int top(Stack *S) {
    return S->data[S->top_idx];
}

void push(Stack *S, int x) {
    S->top_idx++;
    S->data[S->top_idx] = x;
}

void pop(Stack *S) {
    S->top_idx--;
}

int empty(Stack *S) {
    return S->top_idx == -1;
}

// --- Các hàm ph? tr? và bi?n toàn c?c cho Tarjan ---
int min(int a, int b) {
    return a < b ? a : b;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

// --- Thêm m?t bi?n c? toàn c?c ---
int is_strongly_connected_flag; // = 1 n?u liên thông m?nh, = 0 n?u không

// --- Hàm SCC dã s?a l?i logic ---
void SCC(Graph *G, int u) {
    num[u] = min_num[u] = k;
    k++;
    push(&S, u);
    on_stack[u] = 1;

    int v;
    for (v = 1; v <= G->n; v++) {
        if (adjacent(G, u, v)) {
            if (num[v] < 0) {
                SCC(G, v);
                min_num[u] = min(min_num[v], min_num[u]);
            } else if (on_stack[v]) {
                min_num[u] = min(num[v], min_num[u]);
            }
        }
    }

    // Khi tìm th?y m?t SCC
    if (num[u] == min_num[u]) {
        int w, cnt = 0;
        // L?y các d?nh trong SCC ra kh?i stack và d?m s? lu?ng
        do {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
            cnt++;
        } while (w != u);

        // --- S?A L?I LOGIC ---
        // N?u s? lu?ng d?nh trong SCC này nh? hon t?ng s? d?nh
        // nghia là d? th? có ít nh?t 2 SCC -> không liên thông m?nh
        if (cnt < G->n) {
            is_strongly_connected_flag = 0;
        }
    }
}

int main() {
    freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
    int m, n, u, v, i;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for (i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    // --- S?A L?I CÚ PHÁP VÀ LOGIC TRONG MAIN ---
    // 1. Kh?i t?o c? là 1 (gi? d?nh là liên thông m?nh)
    is_strongly_connected_flag = 1;

    // 2. Kh?i t?o m?ng num v?i toán t? gán '='
    for (i = 1; i <= G.n; i++) {
        num[i] = -1;
    }

    k = 1;
    makeNullStack(&S);

    // 3. Ch?y thu?t toán Tarjan cho t?t c? các d?nh chua du?c tham
    for (i = 1; i <= G.n; i++) {
        if (num[i] == -1) {
            SCC(&G, i);
        }
    }

    // 4. Ki?m tra c? và in k?t qu?
    if (is_strongly_connected_flag) {
        printf("strong connected");
    } else {
        printf("unconnected");
    }

    return 0;
}
