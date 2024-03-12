#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>　 
#include <malloc.h>　 

typedef int element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType* s) // 변경하지 말라
{
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType* s)// 변경하지 말라
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s)// 변경하지 말라
{
	return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item)// 변경하지 말라
{
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
// 삭제 함수
element pop(LinkedStackType* s)// 변경하지 말라
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}
// 피크 함수
element peek(LinkedStackType* s)// 변경하지 말라
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void stack_print(LinkedStackType* s)// 변경하지 말라
{
	StackNode* p = s->top;
	if (p) {
		while (p) {
			printf("%d ", p->item);
			p = p->link;
		}
	}
	else
		printf("(empty)\n");
}

// 주 함수
int main(void)
{
	LinkedStackType s;
	init(&s);
	element data, item;
	int sum = 0;
	int threshold;

	init(&s);

	scanf("%d", &data);
	while (data != -1) {
		push(&s, data);
		scanf("%d", &data);
	}

	scanf("%d", &threshold);

	// 이하에 코드 추가



	printf("%d\n", sum);
	stack_print(&s);

	return 0;
}