#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define INF 1000000

typedef struct GraphType {
    int n; // 그래프의 노드 수
    int weight[MAX][MAX]; // 간선 가중치를 저장한 인접 행렬
} GraphType;

int found[MAX]; // 방문 여부를 나타내는 배열
int distance[MAX]; // 시작 노드로부터의 최단 거리를 나타내는 배열

// 최소 거리를 선택하는 함수
int choose(int distance[], int n, int found[]) {
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

// 현재 상태를 출력하는 함수
void printf_status(GraphType* g) {
    printf("Distance: ");
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF)
            printf(" * "); // 최단 거리가 무한대인 경우
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf(" found: ");
    for (int i = 0; i < g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

// 다익스트라 알고리즘으로 최단 경로를 찾는 함수
void shortest_path(GraphType* g, int start) {
    int i, u, w, j;
    int array[10]; // 최단 경로를 저장하는 배열
    for (i = 0; i < g->n; i++) {
        distance[i] = g->weight[start][i]; // 시작 노드에서의 거리 초기화
        found[i] = FALSE; // 방문 여부 초기화
    }
    found[start] = TRUE; // 시작 노드 방문 표시
    distance[start] = 0; // 시작 노드의 거리는 0
    array[0] = start + 1; // 시작 노드 추가
    for (i = 1; i < (g->n); i++) {
        printf_status(g); // 현재 상태 출력
        u = choose(distance, g->n, found); // 다음 방문할 노드 선택
        found[u] = TRUE; // 해당 노드 방문 표시
        for (w = 0; w < g->n; w++)
            if (!found[w])
                if (distance[u] + g->weight[u][w] < distance[w])
                    distance[w] = distance[u] + g->weight[u][w]; // 최단 거리 갱신
        array[i] = u + 1; // 최단 경로 배열에 추가
    }
    for (j = 0; j < g->n; j++) {
        printf("%d ", array[j]); // 최단 경로 출력
    }
}

int main(void) {
    // 그래프 초기화
    GraphType g = { 10, {{0,3,INF,INF,INF,11,12,INF,INF,INF},
                          {3,0,5,4,1,7,8,INF,INF,INF},
                          {INF,5,0,2,INF,INF,6,5,INF,INF},
                          {INF,4,2,0,13,INF,INF,14,INF,16},
                          {INF,1,INF,13,0,9,INF,INF,18,17},
                          {11,7,INF,INF,9,0,INF,INF,INF,INF},
                          {12,8,6,INF,INF,INF,0,13,INF,INF},
                          {INF,INF,5,14,INF,INF,13,0,INF,15},
                          {INF,INF,INF,INF,18,INF,INF,INF,0,10},
                          {INF,INF,INF,16,17,INF,INF,15,10,0}} };

    printf("인접 행렬로 구현\n");
    shortest_path(&g, 0); // 다익스트라 알고리즘 호출

    return 0;
}
