/*후위식 계산*/
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
//int prec(char op)
//{
//	switch (op) {
//	case '(': case ')':
//		return 0;
//	case '+': case '-':
//		return 1;
//	case '*': case '/':
//		return 2;
//	}
//}
//void infix_to_postfix(char exp[])
//{
//	StackType s;
//	int i, n = strlen(exp);
//	char ch;
//	char top_op;
//
//	init(&s);
//	for (i = 0; i < n; i++) {
//		ch = exp[i];
//
//		switch (ch) {
//		case '+': case '-': case '*': case '/':
//			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
//				printf("%c", pop(&s));
//			push(&s, ch);
//			break;
//		case '(':
//			push(&s, ch);
//			break;
//		case ')':
//			top_op = pop(&s);
//			while (top_op != '(') {
//				printf("%c", top_op);
//				top_op = pop(&s);
//			}
//			break;
//		default:
//			printf("%c", ch);
//			break;
//		}
//	}
//
//	while (!is_empty(&s)) {
//		printf("%c", pop(&s));
//	}
//}
int eval(char exp[])
{
	StackType s;
	char ch;
	int value;
	int op1, op2;
	int i, n = strlen(exp);

	init(&s);
	for (i = 0; i < n; i++) {
		ch = exp[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s, ch);
			op1 = pop(&s, ch);
			switch (ch) {
			case '+' :
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	}

	return pop(&s);
}
int main(void)
{
	int result;

	printf("후위표기식은 43*2/58*+\n");
	result = eval("43*2/58*+");
	printf("결과값은 %d\n", result);

	return 0;
}