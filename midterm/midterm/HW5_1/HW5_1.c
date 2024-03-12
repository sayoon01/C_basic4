#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;

	i = ++(h->heap_size);

	while (i != 1 && h->heap[i / 2].key < item.key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp; // temp는 루트로 올리는 노드

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void preorder(HeapType* h, int root) {
	if (h->heap_size < root)
		return;
	else {
		printf("%d ", h->heap[root]);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}

void print_heap(HeapType* h) {
	int i, j = 1, count = 0;

	for (i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i].key);
		count++;

		if (j == count) {
			count = 0;
			j *= 2;
			printf("\n");
		}
	}

	printf("\n");
}

int find(HeapType* h, int root, int key) {
	if (root > h->heap_size)
		return 0;
	if (key == h->heap[root].key)
		return root;
	else if (key > h->heap[root].key)
		return 0;
	else
		return max(find(h, root * 2, key), find(h, root * 2 + 1, key));
}

void print_sorted_value(HeapType h) {
	int i;

	for (i = h.heap_size; i > 0; i--)
		printf("%d ", delete_max_heap(&h).key);

	printf("\n");
}

void modify_priority(HeapType* h, int oldKey, int newKey) {
	int i, child;

	if (oldKey == newKey)
		return;

	// oldKey 위치 저장
	i = find(h, 1, oldKey);

	// oldKey가 존재하지 않을 때
	if (i == 0)
		return;

	// 히프 구조를 바꿔야할 때
	if (newKey > oldKey) {
		while (i != 1 && newKey > h->heap[i / 2].key) {
			h->heap[i] = h->heap[i / 2];
			i /= 2;
		}
		h->heap[i].key = newKey;
	}
	else {
		child = i * 2;

		while (i <= h->heap_size) {
			if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
				child++;

			if (newKey >= h->heap[child].key)
				break;

			h->heap[i] = h->heap[child];
			i = child;
			child *= 2;
		}
		h->heap[i].key = newKey;
	}
}

int main(void) {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4, e5, e6;
	int index, key, oldKey, newKey;
	HeapType heap; // 히프생성

	init(&heap);

	printf("Step1: 삽입된 10, 5, 30에 추가적으로 9, 19, 39을 <삽입>한다\n");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);

	printf("Step2: preorder, print_heap 함수 테스트\n");
	preorder(&heap, 1);
	printf("\n\n");
	print_heap(&heap);

	e4 = delete_max_heap(&heap);
	printf("삭제:루트가 삭제됨\n\n", e4.key);
	print_heap(&heap);
	printf("\n");

	printf("Step3: find 함수 테스트\n");
	printf("찾을 key 입력(-1 for exit): ");
	scanf("%d", &key);

	while (key != -1) {
		index = find(&heap, 1, key);
		if (index == 0)
			printf("%d는  없음\n", key);
		else
			printf("%d은 [%d]에 있음\n", key, index);

		printf("찾을 key 입력(-1 for exit): ");
		scanf("%d", &key);
	}
	printf("\n");

	printf("Step4: print_sorted_value 함수 테스트\n");
	print_sorted_value(heap);
	printf("\n");

	printf("Step5: modify_priority  함수 테스트\n");
	printf("바꿀 key 입력(-1 for exit): ");
	scanf("%d", &oldKey);

	while (oldKey != -1) {
		printf("새 key 입력: ");
		scanf("%d", &newKey);
		modify_priority(&heap, oldKey, newKey);
		print_heap(&heap);

		printf("바꿀 key 입력(-1 for exit): ");
		scanf("%d", &oldKey);
	}
}