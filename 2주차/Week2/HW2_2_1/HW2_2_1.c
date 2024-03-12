//스택연결프로그램
//20200990 컴퓨터학과 윤상아
//#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_STACK_SIZE 3 // 배열을 이용한 스택은 사이즈의 제한이 있다
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> // for exit()


typedef int element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
}StackNode;
typedef struct {
	StackNode* top;
}LinkedStackType;

//초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}
//공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return s->top == NULL;
}
//포화 상태 검출 함수
int is_full(LinkedStackType* s) // 항상 거짓을 반환. 즉 꽉 차있을 때는 없음
{
	return 0;
}
//삽입 함수
void push(LinkedStackType* s, element item)
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
//삭제 함수
element pop(LinkedStackType* s)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
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
	}
	return item;
}
//피크 함수
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else
		return s->top->item;
}

// 스택 출력 함수 <- 상태함수!
//즉 stack_print(const StackType *sp)
//sp가 가리키는 값 변화줄 필요 없음
void stack_print(LinkedStackType* s)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp = s->top;

	if (is_empty(s)) {
		printf("<empty>\n--\n");
		return;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp == s->top)
				printf("%d <-top\n", temp->item);
			else
				printf("%d\n", temp->item);
			temp = temp->link;
		}
	}
	printf("--\n");
}

// 주함수

/*1-2 구조체 변수 사용*/
void main()
{
	LinkedStackType s;

	init(&s); stack_print(&s);

	push(&s, 10); stack_print(&s);

	push(&s, 20); stack_print(&s);

	push(&s, 30); stack_print(&s);

	push(&s, 40); stack_print(&s);

	pop(&s); stack_print(&s);

	push(&s, 50); stack_print(&s);

	pop(&s); stack_print(&s);

	pop(&s); stack_print(&s);

	pop(&s); stack_print(&s);
}