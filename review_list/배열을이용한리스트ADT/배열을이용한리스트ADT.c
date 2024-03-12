#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 3 // 리스트의 최대 크기, 배열이므로 크기가 정해져 있음

typedef int element; // 리스트의 들어갈 항목의 정의

typedef struct {
	element array[MAX_LIST_SIZE];
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류
void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	// exit(1);
}

// 리스트 초기화
void init(ArrayListType* L) {
	L->size = 0;
}

// 공백
int is_empty(ArrayListType* L) {
	return L->size == 0;
}

// 포화
int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

// 인덱스가 pos인 값 반환
element get_entry(ArrayListType* L, int pos) {
	// index가 0보다 작거나 MAX보다 큰 것은 오류
	if (pos < 0 || pos >= L->size)
		error("위치 오류");

	return L->array[pos];
}

// 출력
void print_list(ArrayListType* L) {
	int i;

	// 0부터 size까지 출력
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

// 삽입: 원하는 위치
void insert(ArrayListType* L, int pos, element item) {
	int i;

	// 포화 상태가 아니거나 삽입 가능한 index 범위일 때
	if (!is_full(L) && (pos >= 0 && pos <= L->size)) {
		for (i = L->size - 1; i >= pos; i--) {
			// pos부터 마지막까지 한 칸씩 뒤로 밈
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
	else {
		error("리스트 오버플로우");
	}
}

// 삽입: last
void insert_last(ArrayListType* L, element item) {
	if (is_full(L)) {
		error("리스트 오버플로우");
	}
	else {
		L->array[(L->size)++] = item;
	}
}

// 삭제: 원하는 위치
element delete(ArrayListType* L, int pos) {
	element item;
	int i;

	if (pos < 0 || pos >= L->size) {
		error("위치 오류");
	}

	item = L->array[pos]; // 삭제하는 항목 담기
	for (i = pos; i < L->size - 1; i++) { // 맨 뒤부터 삭제한 곳까지 한 칸씩 땡기기
		L->array[i] = L->array[i + 1];
	}
	L->size--;

	return item;
}

int main(void) {
	ArrayListType list;
	int pos;

	init(&list);

	insert(&list, 0, 10);print_list(&list);
	insert(&list, 0, 20);print_list(&list);
	insert(&list, 0, 30);print_list(&list);

	// 리스트 오버플로우
	insert_last(&list, 40);print_list(&list);

	delete(&list, 0);print_list(&list);

	scanf("%d", &pos);
	printf("get entry: %d\n", get_entry(&list, pos));

	return 0;
}