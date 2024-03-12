#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 30000
#include <stdio.h>

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
int main(void)
{
	StackType s;

	scanf("%s", s.data);
}