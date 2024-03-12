#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define VERTICES 7
#define INF 1000L

int weight[VERTICES][VERTICES] = {
	{ 0, 29, INF, INF, INF, 10, INF },
	{ 29, 0, 16, INF, INF, INF, 15 },
	{ INF, 16, 0, 12, INF, INF, INF },
	{ INF, INF, 12, 0, 22, INF, 18 },
	{ INF, INF, INF, 22, 0, 27, 25 },
	{ 10, INF, INF, INF, 27, 0, INF },
	{ INF, 15, INF, 18, 25, INF, 0 }
};

int selected[VERTICES]; // 0으로 초기화, 선택된 신장트리집합은 공집합으로 시작
int dist[VERTICES]; // 신장트리집합내의 정점과의 최소거리

int get_min_vertex(int n) {
	int v, i;

	for (i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;
		}
	}

	for (i = 0; i < n; i++) {
		if (!selected[i] && dist[i] < dist[v])
			v = i;
	}

	return v;
}

void prim(int s, int n) {
	int i, u, v;

	for (u = 0; u < n; u++)
		dist[u] = INF;

	// 시작 정점인 s 의 거리를 변경
	dist[s] = 0;

	for (i = 0; i < n; i++) {
		// 선택되지 않은 정점 중에서 dist[u]가 가장 적은 정점 u 를 찾음
		u = get_min_vertex(n);
		selected[u] = 1; // <신장트리집합>에 u 를 포함시킴
		printf("%d ", u);
		// 새로이 <신장트리집합>에 포함시킨 u 때문에 변화가 생기는 dist[..]를 재조정
		for (v = 0; v < n; v++)
			if (!selected[v])
				if (weight[u][v] < dist[v])
					dist[v] = weight[u][v];
	}

	printf("\n");
}

int main(void) {
	prim(0, VERTICES);
}