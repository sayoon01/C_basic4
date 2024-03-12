﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g) //변경하지말라
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end) //변경하지말라
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	//g->adj_mat[end][start] = 1;
}
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init(StackType* s) //변경하지말라
{
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s) //변경하지말라
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) //변경하지말라
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item) //변경하지말라
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s) //변경하지말라
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

// 진입차수
int calc_in_degree(GraphType* g, int v) // 코드 작성
{
	int count = 0, i;

	for (i = 0; i < g->n; i++) {
		if (g->adj_mat[i][v] == 1)
			count++;
	}

	return count;
}

// 위상정렬을 수행한다.
void topo_sort(GraphType* g) // 코드 작성
{
	int i, j, n, count = 0;
	int selected[MAX_VERTICES], in_degree[MAX_VERTICES];
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init(s);

	for (i = 0; i < g->n; i++) {
		in_degree[i] = calc_in_degree(g, i);
		selected[i] = 0;
	}

	while (count < g->n) {
		for (i = 0; i < g->n; i++) {
			in_degree[i] = calc_in_degree(g, i);
		}

		for (i = 0; i < g->n; i++) {
			if (in_degree[i] == 0) {
				if (selected[i] == 0) {
					push(s, i);
					selected[i] = 1;
				}
			}
		}

		n = pop(s);
		count++;
		printf("%d->", n);

		for (j = 0; j < g->n; j++) {
			g->adj_mat[n][j] = 0;
		}
	}
}

int main(void) //변경하지말라
{
	GraphType g;
	int u, v;
	graph_init(&g);

	scanf("%d", &g.n);
	scanf("%d %d", &u, &v);
	while (u != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}
	topo_sort(&g);
	printf("정렬끝\n");
}