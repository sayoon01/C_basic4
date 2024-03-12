#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "queue.h"

#define MAX_VERTICES 10
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void visited_init() {
	int i;

	for (i = 0; i < MAX_VERTICES; i++)
		visited[i] = 0;
}

void graph_init(GraphType* g) {
	int r, c;

	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
	}
}

void insert_vertex(GraphType* g, int v) {
	if (g->n + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) {
	int u;

	visited[v] = 1;
	printf("%d ", v);

	for (u = 0; u < g->n; u++) {
		if (g->adj_mat[v][u] == 1 && visited[u] == 0)
			dfs_mat(g, u);
	}
}

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;

	init(&q);
	visited[v] = TRUE;
	printf("%d ", v);

	enqueue(&q, v); // 시작 정점을 큐에 저장 
	while (!is_empty(&q)) {
		v = dequeue(&q); // 큐에 정점 추출 
		for (w = 0; w < g->n; w++) // 인접 정점 탐색 
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE; // 방문 표시 
				printf("%d ", w);
				enqueue(&q, w); // 방문한 정점을 큐에 저장 
			}
	}
}

int main(void) {
	GraphType g;

	graph_init(&g);

	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);

	insert_edge(&g, 0, 1);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 3, 0);
	insert_edge(&g, 0, 2);

	printf("깊이 우선 탐색\n");
	dfs_mat(&g, 0);
	printf("\n");

	visited_init();
	dfs_mat(&g, 1);
	printf("\n");

	printf("넓이 우선 탐색\n");
	visited_init();
	bfs_mat(&g, 0);
	printf("\n");

	visited_init();
	bfs_mat(&g, 1);
	printf("\n");
}