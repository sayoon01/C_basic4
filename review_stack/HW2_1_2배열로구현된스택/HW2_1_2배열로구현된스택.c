//20200990 컴퓨터학과 윤상아
//#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_STACK_SIZE 3 // 배열을 이용한 스택은 사이즈의 제한이 있다
#define MAX_STRING 100

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>

typedef struct {
	int num;
	char numString[MAX_STRING];
}element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s)
{
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[s->top];
	}
}

void stack_print(StackType* s) {

	int i;

	if (s->top == -1) {
		printf("<empty>\n");
	}
	else {

		printf("[%d , %s] <- top\n", s->data[s->top].num, s->data[s->top].numString);
		for (i = s->top - 1; i >= 0; i--)
			printf("[%d , %s]\n", s->data[i].num, s->data[i].numString);
		
	}
	printf("--\n");
}

// 주함수
void main()
{
	StackType s;
	element e;

	init(&s);
	stack_print(&s);

	e.num = 10;
	strcpy(e.numString, "ten");
	push(&s, e);
	stack_print(&s);

	e.num = 20;
	strcpy(e.numString, "twenty");
	push(&s, e);
	stack_print(&s);

	e.num = 30;
	strcpy(e.numString, "thirty");
	push(&s, e);
	stack_print(&s);

	e.num = 40;
	strcpy(e.numString, "forty");
	push(&s, e);
	stack_print(&s);

	e.num = 50;
	strcpy(e.numString, "fifty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}