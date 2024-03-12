#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
	//printf("%d ", v);

	for (u = 0; u < g->n; u++) {
		if (g->adj_mat[v][u] == 1 && visited[u] == 0) {
			// HW6_2_1a
			printf("<%d %d>\n", v, u);
			dfs_mat(g, u);
		}
	}
}

void read_graph(GraphType* g, char* filename) {
	FILE* fp = fopen(filename, "r");
	int n, u, v;

	if (fp == NULL) {
		fprintf(stderr, "파일 % s을 열 수 없음!\n", filename);
		return;
	}

	// 정점 읽기
	if (fscanf(fp, "%d\n", &n) != EOF)
		g->n = n;

	// 간선 읽기
	while (fscanf(fp, "%d %d\n", &u, &v) != EOF) {
		insert_edge(g, u, v);
	}

	fclose(fp);
}

void write_graph(GraphType* g, char* filename) {
	int r, c;
	FILE* fp;

	if (filename == NULL)
		fp = stdout;
	else {
		fp = fopen(filename, "w");

		if (fp == NULL) {
			fprintf(stderr, "파일 % s을 열 수 없음!\n", filename);
			return;
		}
	}

	fprintf(fp, "%d\n", g->n);
	for (r = 0; r < g->n; r++) {
		for (c = r; c < g->n; c++) {
			if (g->adj_mat[r][c] == 1)
				fprintf(fp, "%d %d\n", r, c);
		}
	}

	fclose(fp);
}

int main(void) {
	GraphType g;
	int v;

	graph_init(&g);

	printf("Enter 정점: ");
	scanf("%d", &v);

	read_graph(&g, "input.txt");
	dfs_mat(&g, v);

}