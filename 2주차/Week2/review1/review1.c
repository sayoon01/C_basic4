// 괄호검사
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char element;
typedef struct {
	char data[MAX_STACK_SIZE];
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

int check_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);

	init(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '{': case '[':
			push(&s, ch);
			break;
		case ')': case '}': case ']':
			if (is_empty(&s))
				return 0; //조건 A
			else {
				open_ch = pop(&s);

				if ((ch == '(' != open_ch == ')') && (ch == '{' != open_ch == '}') && (ch == '[' != open_ch == ']'))
					return 0;//조건 B

				break;
			}
		}
	
	}

	if (!is_empty(&s)) // 조건 C
		return 0;

	return 1;
}
int main(void)
{
	char* p = "{A[(i+1)]=0;}";

	if (check_matching(p) == 1)
		printf("%s 괄호검사성공\n",p);
	else
		printf("%s 괄호검사실패\n",p);
	return 0;
}