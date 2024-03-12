#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// 초기화
void init(LinkedStackType* s) {
	s->top = NULL;
}

// 공백
int is_empty(LinkedStackType* s) {
	return s->top == NULL;
}

// 포화
// 연결리스트의 특성으로 동적으로 크기를 변경할 수 있기 때문에 항상 거짓을 반환
// 즉 꽉 차 있을 때는 없음.
int is_full(LinkedStackType* s) {
	return 0;
}

// 삽입
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));

	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

// 삭제
element pop(LinkedStackType* s) {
	StackNode* temp;
	element item;

	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		temp = s->top;
		item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

// 피크
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		return NULL;
	}
	else {
		return s->top->item;
	}
}

int main(void) {
	LinkedStackType s;

	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
}