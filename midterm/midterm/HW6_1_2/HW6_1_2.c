#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VERTICES 10

typedef int element;

typedef struct GraphNode {
	element vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) {
	int v;

	g->n = 0; // 정점 개수
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

void remove_node(GraphNode** phead, element item) {
	GraphNode* p, * pre;

	if (*phead == NULL)
		printf("그래프가 비었습니다\n");
	else if ((*phead)->vertex == item) {
		p = *phead;
		*phead = (*phead)->link;
		free(p);
	}
	else {
		p = *phead;

		do {
			pre = p;
			p = p->link;
		} while (p != NULL && p->vertex != item);

		if (p != NULL) {
			pre->link = p->link;
			free(p);
		}
		else {
			printf("삭제하려는 %d값이 없습니다\n", item);
		}
	}
}

void delete_edge(GraphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}
	remove_node(&g->adj_list[u], v);
	remove_node(&g->adj_list[v], u);
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
	FILE* fp;
	int i;
	GraphNode* temp;

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

	for (i = 0; i < g->n; i++) {
		temp = g->adj_list[i];
		while (temp != NULL) {
			if (i < temp->vertex) 
				fprintf(fp, "%d %d\n", i, temp->vertex);
			temp = temp->link;
		}
	}

	if (filename != NULL)
		fclose(fp);
}

int main(void) {
	GraphType g;

	graph_init(&g);

	read_graph(&g, "input.txt");
	//insert_edge(&g, 1, 4);
	delete_edge(&g, 0, 1);

	write_graph(&g, "output.txt");
}