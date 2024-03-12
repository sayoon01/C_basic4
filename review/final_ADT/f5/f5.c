#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		// 노드의 수 
#define INF 	999		// 

int distance[MAX_VERTICES];	// 시작노드로부터의 최단경로 거리 
int found[MAX_VERTICES];	//  방문한 노드 표시 

typedef struct GraphType {
	int n;					// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g) // 변경하지 말라
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;

	for (r = 0; r < MAX_VERTICES; r++)
		g->adj_mat[r][r] = 0;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) // 변경하지 말라
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end, int weight) // 변경하지 말라
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = weight;
	g->adj_mat[end][start] = weight;
}

int choose(int distance[], int n, int found[]) // 변경하지 말라
{
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

void shortest_path(GraphType* g, int start, int end) // 코드 작성
{
	int i, u, v;
	int n;

	// 초기화
	for (i = 0; i < g->n; i++) {
		distance[i] = g->adj_mat[start][i];
		found[i] = 0;
	}

	found[start] = 1; // 시작 정점 방문 표시
	distance[start] = 0; // 본인 정점과의 거리는 0
	printf("%d-", start);
	n = distance[start];

	for (i = 0; i < g->n - 1; i++) {
		// 선택되지 않은 정점 중에서 distance[u]가 가장 적은 정점 u를 찾음
		u = choose(distance, g->n, found);
		found[u] = 1;

		printf("<%d>->%d", n, u);
		n = distance[u];


		// 새로인 방문된 u 때문에 변화가 생기는 distance[…] 재조정
		for (v = 0; v < g->n; v++) {
			if (!found[v]) {
				if (distance[u] + g->adj_mat[u][v] < distance[v])
					distance[v] = distance[u] + g->adj_mat[u][v];
			}
		}
	}
}

int main(void) // 변경하지 말라
{
	GraphType g;
	int u, v, w;
	int start, end;

	graph_init(&g); // 그래프 초기화

	scanf("%d", &g.n);
	scanf("%d %d %d", &u, &v, &w);
	while (u != -1) {
		insert_edge(&g, u, v, w);
		scanf("%d %d %d", &u, &v, &w);
	}
	scanf("%d", &start);
	scanf("%d", &end);

	shortest_path(&g, start, end);
}