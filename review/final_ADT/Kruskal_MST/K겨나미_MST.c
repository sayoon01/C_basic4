//heap
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VERTICES 10

// -------------------------------------------

int parent[MAX_VERTICES];
int num[MAX_VERTICES];

void set_init(int n) {
	int i;

	for (i = 0; i < n; i++)
		parent[i] = -1;
}

int set_find(int vertex) {
	if (parent[vertex] == -1)
		return vertex;

	while (parent[vertex] != -1)
		vertex = parent[vertex];

	return vertex;
}

void set_union(int s1, int s2) {
	int root1 = set_find(s1);
	int root2 = set_find(s2);

	if (root1 != root2)
		parent[root1] = root2;
}

// -------------------------------------------

#define MAX_ELEMENT 100

typedef struct {
	int key; // 간선의 가중치
	int u; // 정점1
	int v; // 정점2
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void heap_init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item) {
	int i = ++(h->heap_size);

	while (i != 1 && item.key < h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key)
			child++;

		if (temp.key <= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}


void insert_heap_edge(HeapType* h, int u, int v, int weight) {
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;

	// u, v, weight를 element로 히프에 삽입
	insert_min_heap(h, e);
}

void insert_all_edges(HeapType* h) {
	insert_heap_edge(h, 0, 1, 29);
	insert_heap_edge(h, 1, 2, 16);
	insert_heap_edge(h, 2, 3, 12);
	insert_heap_edge(h, 3, 4, 22);
	insert_heap_edge(h, 4, 5, 27);
	insert_heap_edge(h, 5, 0, 10);
	insert_heap_edge(h, 6, 1, 15);
	insert_heap_edge(h, 6, 3, 18);
	insert_heap_edge(h, 6, 4, 25);
}

void kruskal(int n) {
	int edge_accepted = 0; // 현재까지 선택된 간선의 수
	int uset, vset;
	element e;
	HeapType h;

	heap_init(&h);
	insert_all_edges(&h);
	set_init(n);

	while (edge_accepted < n - 1) { // 간선의 수는 정점의 수 보다 하나 작아야 함
		e = delete_min_heap(&h); // 1. 최소 비용 간선 선택
		uset = set_find(e.u);
		vset = set_find(e.v);

		if (uset != vset) { // 2. cycle 여부 확인
			printf("(%d,%d) %d \n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset);
		}
	}
}

int main(void) {
	kruskal(7);
}
