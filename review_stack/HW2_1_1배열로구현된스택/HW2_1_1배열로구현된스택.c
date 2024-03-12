//#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_STACK_SIZE 3 // 배열을 이용한 스택은 사이즈의 제한이 있다
#include <stdio.h>
#include <stdlib.h> // for exit()


// 스택을 위한 타입 정의
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화 함수 
void init(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

// 스택 출력 함수 <- 상태함수!
//sp가 가리키는 값 변화줄 필요 없음
void stack_print(StackType* s)
{
	if (is_empty(s)) {
		printf("<empty>\n--\n");
		return;
	}
	else
	{
		for (int i = s->top; i >= 0; i--) {
			if (i == s->top)
				printf("%d <- top\n", s->data[i]);
			else
				printf("%d\n", s->data[i]);
		}
		printf("--\n");
	}

}

// 주함수

/*1-2 구조체 변수 사용*/
void main()
{
	StackType s;

	init(&s); stack_print(&s);

	push(&s, 10); stack_print(&s);

	push(&s, 20); stack_print(&s);

	push(&s, 30); stack_print(&s);

	//스택 포화 에러 구간
	push(&s, 40); stack_print(&s);

	pop(&s); stack_print(&s);

	push(&s, 50); stack_print(&s);

	pop(&s); stack_print(&s);

	pop(&s); stack_print(&s);

	pop(&s); stack_print(&s);
}