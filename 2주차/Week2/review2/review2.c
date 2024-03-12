/*중위식을 후위식으로 변환*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* sp)
{
	sp->top = -1;
}
int is_empty(StackType* sp)
{
	return sp->top == -1;
}
int is_full(StackType* sp)
{
	return sp->top == MAX_STACK_SIZE - 1;
}
void push(StackType* sp, element item)
{
	if (is_full(sp)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		sp->data[++(sp->top)] = item;
}
element pop(StackType* sp)
{
	if (is_empty(sp)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return sp->data[(sp->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];

}
int prec(char op)
{
	switch (op) {
		case '(': case ')':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
	}
}
void infix_to_postfix(char exp[])
{
	StackType s;
	int i, n = strlen(exp);
	char ch;
	char top_op;

	init(&s);
	for (i = 0; i < n; i++) {
		ch = exp[i];

		switch (ch) {
			case '+' : case '-': case '*': case '/': 
				while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
					printf("%c", pop(&s));
				push(&s, ch);
				break;
			case '(':
				push(&s, ch);
				break;
			case ')':
				top_op = pop(&s);
				while (top_op != '(') {
					printf("%c", top_op);
					top_op = pop(&s);
				}
				break;
			default:
				printf("%c", ch);
				break;
		}
	}

	while (!is_empty(&s)) {
		printf("%c", pop(&s));
	}
}
int main(void)
{
	char* s = "(2+3)*4+9";

	printf("중위표시수식 %s\n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}