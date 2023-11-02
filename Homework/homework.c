#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0
#define INF 1000
#define MAX_VERTICES 100
int parent[MAX_VERTICES]; //정점에 대한 부모 노드 저장 배열

void set_init(int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}
//curr이 속하는 집합을 반환
int set_find(int curr)
{
    if (parent[curr] == -1)
        return curr;
    while (parent[curr] != -1) curr = parent[curr];
    return curr;
}
//두개의 원속 속한 집합을 합침
void set_union(int a, int b)
{
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2)
        parent[root1] = root2;
}
struct Edge{
    int s, e, w;
};

typedef struct GraphType {
    int n;              //간선개수
    int nvertex;        //정점의 개수
    struct Edge edges[2 * MAX_VERTICES];
}GraphType;

//그래프 초기화
void graph_init(GraphType* g)
{
    g->n = g->nvertex = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++)
    {
        g->edges[i].s = 0;
        g->edges[i].e = 0;
        g->edges[i].w = INF;

    }
}

//간선 삽입 연산
void insert_edge(GraphType* g, int s, int e, int w)
{
    g->edges[g->n].s = s;
    g->edges[g->n].e = e;
    g->edges[g->n].w = w;
    g->n++;
}


//두 원소를 비교하여 정렬 순서 결정 함수
int compare(const void* a, const void* b) {
    struct Edge* ea = (struct Edge*)a;
    struct Edge* eb = (struct Edge*)b;
    return ea->w - eb->w;
}


//kruskal 알고리즘
void kruskal(GraphType* g) {
    int edge_a = 0; //현재까지 선택된 간선의 수
    int u, v;       //정점 u와 정점 v의 집합 번호
    struct Edge e;
    set_init(g->nvertex);       //집합 초기화
    qsort(g->edges, g->n, sizeof(struct Edge), compare);
    printf("Kruskal MST Algorithm(퀵 정렬 사용)\n");
    int i = 0;
    while(edge_a<(g->nvertex-1)){       //간선의 수 < n-1
        e = g->edges[i];
        u = set_find(e.s);              //정점 u의 집합 번호
        v = set_find(e.e);              //정점 v의 집합 번호
        if (u != v) {                   //서로 속한 집합이 다르면
            printf("Edge (%d, %d) select %d\n", e.s, e.e, e.w);
            edge_a++;
            set_union(u, v);            //두개의 집합을 합침
        }
        i++;
    }

}
int main() {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    g->nvertex = 10;
    insert_edge(g, 1, 2, 3);
    insert_edge(g, 1, 6, 11);
    insert_edge(g, 1, 7, 12);
    insert_edge(g, 2, 3, 5);
    insert_edge(g, 2, 4, 4);
    insert_edge(g, 2, 5, 1);
    insert_edge(g, 2, 6, 7);
    insert_edge(g, 2, 7, 8);
    insert_edge(g, 3, 4, 2);
    insert_edge(g, 3, 7, 6);
    insert_edge(g, 3, 8, 5);
    insert_edge(g, 4, 5, 13);
    insert_edge(g, 4, 8, 14);
    insert_edge(g, 4, 10, 16);
    insert_edge(g, 5, 6, 9);
    insert_edge(g, 5, 9, 18);
    insert_edge(g, 5, 10, 17);
    insert_edge(g, 7, 8, 13);
    insert_edge(g, 8, 10, 15);
    insert_edge(g, 9, 10, 10);

    kruskal(g);
    free(g);
    return 0;
}