//20200990 컴퓨터학과 윤상아
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 // 리스트의 최대크기

typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

//오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); // 고쳐야 할 때 있음
}

//리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}

// 리스트가 비어 있으면 1, 그렇지 않으면 0을 반환
//공백 검출 함수 
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

// 리스트가 가득 차 있으면 1, 그렇지 않으면 0 반환
// 포화 검출 함수
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

//peek
element get_entry(ArrayListType* L, int pos) // 이때 pos는 0~size-1
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

//리스트 출력
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

// 마지막 삽입
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

//삽입
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0 && pos <= L->size)) { // pos의 유효성 검사
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

//삭제
element delete(ArrayListType* L, int pos)
{
	element item;

	if (pos<0||pos>=L->size) // if(is_empty(L))
		error("위치 오류");

	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

int main(void)
{
	// ArrayListType를 정적으로 생성하고 ArrayListType를
	// 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;

	init(&list);

	//insert_first와 같다
	insert(&list, 0, 10); print_list(&list); // 0번째 위치에 10 추가
	insert(&list, 0, 20); print_list(&list); // 0번째 위치에 20 추가
	insert(&list, 0, 30); print_list(&list); // 0번째 위치에 30 추가
	insert_last(&list, 40); print_list(&list); // 맨 끝에 40 추가
	delete(&list, 0); print_list(&list); // 0번째 항목 삭제

	return 0;
}