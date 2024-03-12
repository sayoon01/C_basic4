#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10

int visited[MAX_VERTICES];

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void visited_init() {
	int i;

	for (i = 0; i < MAX_VERTICES; i++)
		visited[i] = 0;
}

void graph_init(GraphType* g) {
	int v;

	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
	if (g->n + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;

	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	// u 에 v 를 매단다
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	// v 에 u 를 매단다
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
}

void dfs_list(GraphType* g, int v) {
	GraphNode* u;

	visited[v] = 1;
	printf("%d ", v);

	for (u = g->adj_list[v]; u != NULL; u = u->link) {
		if (!visited[u->vertex])
			dfs_list(g, u->vertex);
	}
}

void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;

	init(&q); // 큐 초기 화 

	visited[v] = TRUE; // 정점 v 방문 표시 
	printf("%d ", v);

	enqueue(&q, v); // 시작정점을 큐에 저장 

	while (!is_empty(&q)) {
		v = dequeue(&q); // 큐에 저장된 정점 선택 
		for (w = g->adj_list[v]; w; w = w->link) //인접 정점 탐색 
			if (!visited[w->vertex]) { // 미방문 정점 탐색 
				visited[w->vertex] = TRUE; // 방문 표시 
				printf("%d ", w->vertex);
				enqueue(&q, w->vertex); //정점을 큐에 
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
	dfs_list(&g, 0);
	printf("\n");

	visited_init();
	dfs_list(&g, 1);
	printf("\n");

	printf("넓이 우선 탐색\n");
	visited_init();
	bfs_list(&g, 0);
	printf("\n");

	visited_init();
	bfs_list(&g, 1);
	printf("\n");
}