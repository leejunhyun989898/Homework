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

int A[MAX][MAX];



void floyd(GraphType* g,int a,int b) {
    int i, j, k;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            A[i][j] = g->weight[i][j];
        }
    }

    for (k = 0; k < g->n; k++) {
        for (i = 0; i < g->n; i++) {
            for (j = 0; j < g->n; j++) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    
                }
            }
        }
        
    }
    printf("Shortest distance : %d ", A[a][b]);
}

// Function to print the shortest path from i to j
void printShortestPath(int i, int j) {

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


    int start, end;
    printf("Floyd-Warshall Algorithm\n");
    while (1) {
        printf("Strat Node: ");
        scanf_s("%d", &start);
        printf("End Node: ");
        scanf_s("%d", &end);
 
        floyd(&g, start - 1, end - 1);
        printf("\n");
        printf("\n");
        if (end == 9) {
            break;
        }
    }


    return 0;
}
