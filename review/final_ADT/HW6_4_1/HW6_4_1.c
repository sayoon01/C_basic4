//Dij
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		/* 노드의 수 */
#define INF 	9999		/* 무한 값(연결이 없는 경우) */

int distance[MAX_VERTICES];	/* 시작노드로부터의 최단경로 거리 */
int previous[MAX_VERTICES];	/* 경유 노드  :  이 배열의 값을 어떻게 설정할 것인가?가 이 숙제의 문제*/
int found[MAX_VERTICES];	/* 방문한 노드 표시 */

typedef struct GraphType {
	int n;					// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g) {
	int r, c;

	g->n = 0;

	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;

	for (r = 0; r < MAX_VERTICES; r++) // pak 추가
		g->adj_mat[r][r] = 0;
}

void read_graph(GraphType* g, char* filename) {
	int n, u, v;
	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		fprintf(stderr, "파일 %s을 열 수 없음!\n", filename); return;
	}

	fscanf(fp, "%d\n", &n);
	g->n = n;

	while (fscanf(fp, "%d %d", &u, &v) != EOF) {
		fscanf(fp, "%d\n", &g->adj_mat[u][v]);
		g->adj_mat[v][u] = g->adj_mat[u][v];
	}
	fclose(fp);
}

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

void print_path(int start, int end) {
	if (start == end) {
		printf("%d -> ", start);
		return;
	}
	else {
		print_path(start, previous[end]);
		printf("%d -> ", end);
	}
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;

	/* 초기화 */
	for (i = 0; i < g->n; i++) {
		distance[i] = g->adj_mat[start][i];
		found[i] = FALSE;
		previous[i] = start;
	}

	found[start] = TRUE;    /* 시작노드 방문 표시 */
	distance[start] = 0;	// 요개 불필요하지 않나요?

	for (i = 0; i < (g->n) - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;

		// 이부분에 출력문을 추가
		/* 1-1
		printf("%d -> %d <%d>\n", start, u, distance[u]);
		*/

		/* 1-2
		*/
		print_path(start, u);
		printf("  <%d>\n", distance[u]);

		// distance[] 재조정
		for (w = 0; w < g->n; w++) {
			if (!found[w])
				if (distance[u] + g->adj_mat[u][w] < distance[w]) {
					distance[w] = distance[u] + g->adj_mat[u][w];
					previous[w] = u;
				}
		}
	}
}

int main(void) {
	GraphType g;		// 입력 그래프

	graph_init(&g);

	read_graph(&g, "input3.txt");
	shortest_path(&g, 0);
}