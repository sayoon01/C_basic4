//20200990 컴퓨터학과 윤상아
//배열을 이용한 리스트
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 5 

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
	printf("리스트끝\n");
}

// 마지막 삽입
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		printf("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

//삽입
void insert(ArrayListType* L, int pos, element item)
{// 삽입시 pos<=L->size를 허용하는 이유는 리스트의 끝에 요소를 추가하기 위한 방법!
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

	if (pos < 0 || pos >= L->size) // if(is_empty(L))
		error("위치 오류");

	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) 
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

// 리스트를 비운다
void clear(ArrayListType* L)
{
	L->size = 0;
}

// item을 리스트의 첫번째 항목에 추가한다.
void insert_first(ArrayListType* L, element item)
{
	int i;

	if (is_full(L))
		printf("리스트 오버플로우\n");
	else {
		for (int i = L->size; i > 0; i--)
			L->array[i] = L->array[i - 1];
		L->array[0] = item;
		L->size++;
	}
}

// 리스트의 항목수를 반환한다.
int get_length(ArrayListType* L)
{
	return L->size;
}

//pos번째 항목을 item으로 바꾼다
void replace(ArrayListType* L, int pos, element item)
{

	//최초 답안
	/*
	* if(!is_empty(L)&&pos>=0&&pos<=L->size) {
	*	L->array[pos]=item;
	* }
	*/
	if (L->array[pos] != NULL)
		L->array[pos] = item;
}

//item이 리스트에 있으면 1 아니면 0을 반환
int is_in_list(ArrayListType* L, element item)
{
	for (int i = 0; i < L->size; i++)
		if (L->array[i] == item)
			return 1;
	return 0;
}

// 리스트에서 key값을 검색하여 그를 삭제한다.
// 여러 개의 key 값이 있을 때는 첫번째 key값을 삭제하는것으로 한다.
//key값이 없는 경우 "없다"고 출력한다.
void delete_by_key(ArrayListType* L, element key)
{
	int i;
	for (i = 0; i < L->size; i++) {
		if (L->array[i] == key) {
			delete(L, i);
			return;
		}
	}

	//delete없이 짜보기
	/*for (i = 0; i < L->size; i++) {
		if (L->array[i] == key) {
			if (!is_empty(L))
				for (int idx = i; idx < (L->size - 1); idx++)
					L->array[idx] = L->array[idx + 1];
			return;
		}
	}*/

	if(i==L->size)
	printf("삭제하하려는 key값 %d는 리스트에 없습니다.\n", key);
}

int main(void) {
	ArrayListType list1;

	init(&list1);

	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);
	clear(&list1); print_list(&list1);

	insert_last(&list1, 90); print_list(&list1);

	insert(&list1, 0, 30);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);

	delete(&list1, 2); print_list(&list1);

	printf("\n-이 이후는 HW1_1에서 추가한 함수들 테스트-\n");

	insert_first(&list1, 9); print_list(&list1);
	insert_last(&list1, 99); print_list(&list1);

	//현재 리스트가 꽉 찬(크기 5개) 상태이므로 한 항목을 더 추가하면 "리스트 오버플로우"을 출력한다.
	insert_first(&list1, 1); print_list(&list1);

	printf("길이는 %d\n", get_length(&list1));
	printf("3번째 데이타는 %d\n", get_entry(&list1, 2));

	replace(&list1, 3, 40); print_list(&list1);

	printf("20은 리스트에 %s\n", is_in_list(&list1, 20) ? "있습니다" : "없습니다");
	printf("22은 리스트에 %s\n", is_in_list(&list1, 22) ? "있습니다" : "없습니다");

	delete_by_key(&list1, 20); print_list(&list1);
	delete_by_key(&list1, 22); print_list(&list1);
}