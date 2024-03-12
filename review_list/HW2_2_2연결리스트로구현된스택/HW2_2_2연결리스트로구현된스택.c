//#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_STRING 100

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <malloc.h>

typedef struct {
	int num;
	char numString[MAX_STRING];
}element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
}StackNode;
typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s)
{
	s->top = NULL;
}
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

int is_full(LinkedStackType* s) { // 연결프로그램은 크기 제한이 없음. 그러므로 is_full은 항상 거짓 반환
	return 0;
}

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

element pop(LinkedStackType* s) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	element item;

	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		temp = s->top;
		item = temp->item;
		s->top = s->top->link;
		free(temp);
	}
	return item;
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void stack_print(LinkedStackType* s) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp = s->top;
	if (is_empty(s)) {
		printf("<empty>\n");
	}
	else {
		while (temp != NULL)
		{
			if (temp == s->top)
				printf("[%d , %s] <-top\n", temp->item.num, temp->item.numString);
			else
				printf("[%d , %s]\n", temp->item.num, temp->item.numString);
			temp = temp->link;
		}
	}
	printf("--\n");
}

// 주함수
void main()
{
	LinkedStackType s;
	element e;

	init(&s);
	stack_print(&s);

	e.num = 10;strcpy(e.numString, "ten");
	push(&s, e);stack_print(&s);

	e.num = 20;strcpy(e.numString, "twenty");
	push(&s, e);stack_print(&s);

	e.num = 30;strcpy(e.numString, "thirty");
	push(&s, e);stack_print(&s);

	e.num = 40;strcpy(e.numString, "forty");
	push(&s, e);stack_print(&s);

	e.num = 50;strcpy(e.numString, "fifty");
	push(&s, e);stack_print(&s);

	pop(&s);stack_print(&s);

	pop(&s);stack_print(&s);

	pop(&s);stack_print(&s);
}