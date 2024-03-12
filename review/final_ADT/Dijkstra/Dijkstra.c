// 위상정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 7
#define INF 1000

typedef struct GraphType {
	int n; // 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

/* 네트워크의 인접행렬 */
int weight[MAX_VERTICES][MAX_VERTICES] = {
	{ 0, 7, INF, INF, 3, 10, INF },
	{ 7, 0, 4, 10, 2, 6, INF },
	{ INF, 4, 0, 2, INF, INF, INF },
	{ INF, 10, 2, 0, 11, 9, 4 },
	{ 3, 2, INF, 11, 0, INF, 5 },
	{ 10, 6, INF, 9, INF, 0, INF },
	{ INF, INF, INF, 4, 5, INF, 0 }
};

int found[MAX_VERTICES]; // 방문한 정점 표시
int distance[MAX_VERTICES]; // 시작정점으로부터의 최단경로 거리

// 방문되지 않은 것 중에서 가장 distance[u]가 작은 u를 찾아서 이를 반환
int choose(int distance[], int n, int found[]) {
	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;

	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}

	return minpos;
}

void shortest_path(int start, int n) {
	int i, u, v;

	// 초기화
	for (i = 0; i < n; i++) {
		distance[i] = weight[start][i];
		found[i] = 0;
	}

	found[start] = 1; // 시작 정점 방문 표시
	distance[start] = 0; // 본인 정점과의 거리는 0
	printf("<%d>\n", start);

	for (i = 0; i < n - 1; i++) {
		// 선택되지 않은 정점 중에서 distance[u]가 가장 적은 정점 u를 찾음
		u = choose(distance, n, found);
		found[u] = 1;

		printf("<%d>\n", u);

		// 새로인 방문된 u 때문에 변화가 생기는 distance[…] 재조정
		for (v = 0; v < n; v++) {
			if (!found[v]) {
				if (distance[u] + weight[u][v] < distance[v])
					distance[v] = distance[u] + weight[u][v];
			}
		}
	}
}

int main(void) {
	shortest_path(0, MAX_VERTICES);
}