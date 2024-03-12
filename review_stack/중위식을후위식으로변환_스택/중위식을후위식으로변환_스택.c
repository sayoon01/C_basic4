#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init(StackType* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return s->top == -1;
}

// 포화 상태 검출 함수
int is_full(StackType* s) {
	return s->top == MAX_STACK_SIZE - 1;
}

// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

// 피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[s->top];
	}
}

// 연산자의 우선순위를 반환
int prec(char op) {
	switch (op) {
	case '(': case')': return 0;
	case '+': case'-': return 1;
	case '*': case'/': return 2;
	}
	return -1;
}

// 중위 -> 후위
void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
		case '+': case '-': case '*': case '/':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				// 스택에 있는 연산자의 우선순위가 같거나 크다면 pop하여 출력
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: // 피연산자는 무조건 출력
			printf("%c", ch);
			break;
		}
	}

	while (!is_empty(&s)) {
		printf("%c", pop(&s));
	}
}

int main(void) {
	char* s = "5*(10+2)/2";

	printf("중위표시수식 %s\n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");

	return 0;
}