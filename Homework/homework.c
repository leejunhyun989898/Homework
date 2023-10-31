#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0
#define MAX 10

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX];
}QueueType;

void error(char* message)
{
    fprintf(stderr, "%s\n", message);

}

void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}



int is_full(QueueType* q)
{
    return((q->rear + 1) % MAX == q->front);
}
int is_empty(QueueType* q)
{
    return(q->front == q->rear);

}
void enqueue(QueueType* q, int item)
{
    if (is_full(q)) {
        error("큐가 포화상태");
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[(q->rear)] = item;
}
element dequeue(QueueType* q)
{
    if (is_empty(q))
    {
        error("큐 공백상태");
    }
    q->front = (q->front + 1) % MAX;
    return q->data[q->front];

}
#define MAX_VERTICES 50

typedef struct GrapNode {
    int vertex;
    struct GraphNode* link;
}GraphNode;
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];
void init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}
void insert_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = TRUE;
    printf("%d ", v);
    for (w = 0; w < g->n; w++)
        if (g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, w);
}

void bfs_mat(GraphType* g, int v)
{
    int w;
    QueueType q;
    init_queue(&q);
    visited[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w =0; w<g->n; w++)
            if (g->adj_mat[v][w]&&!visited[w])
            {
                visited[w] = TRUE;
                printf("%d ", w);
                enqueue(&q, w);
            }
    }
}

void main()
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 10; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 4);
    
    insert_edge(g, 1, 5);
    insert_edge(g, 1, 4);
    insert_edge(g, 1, 7);
    insert_edge(g, 1, 10);
    insert_edge(g, 2, 3);
    insert_edge(g, 4, 0);
    insert_edge(g, 4, 2);
    insert_edge(g, 4, 3);
    insert_edge(g, 4, 5);
    insert_edge(g, 4, 6);
    insert_edge(g, 4, 7);
    insert_edge(g, 4, 6);
    insert_edge(g, 4, 6); 
    insert_edge(g, 5, 0);
    insert_edge(g, 5, 3);
    insert_edge(g, 6, 0);
    insert_edge(g, 6, 8);
    insert_edge(g, 7, 6);
    insert_edge(g, 7, 10);
    insert_edge(g, 10, 8);
    insert_edge(g, 8, 9);
    insert_edge(g, 0, 9);
    printf("-----------------------\n");
    printf("1    : 깊이 우선 탐색  |\n");
    printf("2    : 너비 우선 탐색  |\n");
    printf("3    : 종료            |\n");
    printf("-----------------------\n");
    int n,start,search;
    
    while (1) {
        printf("메뉴 입력: ");
        scanf_s("%d", &n);
        printf("\n");
        if (n == 1)
        {
            printf("시작 할 번호와 탐색할 값 입력: ");
            scanf_s("%d %d", &start, &search);
            dfs_mat(g, start);
            printf("\n");
        }
    }
    
    free(g);
    return 0;
}
