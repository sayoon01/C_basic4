//단순연결리스트 관련 숙제
//컴퓨터학과 20200990 윤상아
#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 자기 참조 구조체
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void print_list(ListNode* head)
{
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* p;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = value; newNode->link = NULL;

	if (head == NULL) {
		head = newNode;
	}
	else {
		for (p = head; p->link != NULL; p = p->link);
		p->link = newNode;
	}
	return head;
}
//pos위치에 value를 갖는 노드를 추가
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* p = head;
	//1차
	/*int i = 0;
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; p->link = NULL;

	while (i < pos) {
		temp = temp->link;
		i++;
	}

	p->link = temp->link;
	temp->link = p;*/

	//2차
	/*if (pos == 0)
		insert_first(head, value);
	else {
		for (int i = 0; i < pos-1; i++) {
			p = p->link;
		}
		insert_next(head, p, value);
	}

	return head;*/

	//3트
	if (pos == 0)
		return insert_first(head, value);
	else {
		for (int i = 0; i < pos - 1; i++)
			p = p->link;
		return insert_next(head, p, value);
	}

}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;

	if (head == NULL) {
		error("삭제할 항목이 없음");
	}

	removed = head;
	head = removed->link;
	free(removed);

	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp;
	ListNode* removed;

	prevTemp = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
		error("삭제할 항목이 없음");
	if (head->link == NULL) {
		free(temp);
		head = NULL;
	}
	else {
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}

		removed = temp;
		prevTemp->link = NULL;
		free(removed);
	}

	return head;
}
ListNode* delete_next(ListNode* head, ListNode* pre) {
	ListNode* p = pre->link;
	pre->link = p->link;
	free(p);

	return head;
}
ListNode* delete_pos(ListNode* head, int pos)
{
	//1차시도
	/*int i = 0;
	ListNode* prevTemp = NULL;
	ListNode* temp = head;
	ListNode* removed;

	if (head->link == NULL) {
		free(temp);
		head = NULL;
	}
	else {
		while (i < pos) {
			prevTemp = temp;
			temp = temp->link;
			i++;
		}
		removed = temp;
		prevTemp->link = temp->link;
		free(removed);
	}

	return head;*/

	ListNode* p = head;
	int i;

	if (pos == 0) {
		return delete_first(head);
	}
	else {
		for (i = 0; i < pos - 1; i++) {
			p = p->link;
		}

		return delete_next(head, p);
	}
}

//pre가 가리키는 노드의 다음 노드를 삭제한다
//ListNode* delete_next(ListNode* head, ListNode* pre)
//{
//	ListNode* removed;
//	removed = pre->link;
//	pre->link = removed->link;
//	free(removed);
//	return head;
//}


ListNode* search(ListNode* head, element x)
{
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	/*for (p = head; p != NULL; p = p->link) {
		if (p->data == x)
			return p;
	}*/
	return NULL;
}

ListNode* concat(ListNode* head1, ListNode* head2)
{
	ListNode* p;

	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}
ListNode* reverse(ListNode* head)
{
	ListNode* p, * q, * r;
	p = head;
	q = NULL; // NULL로 초기화 !

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q; // p가 아니라 q!!
}
// 새로 추가한 함수
//item이 리스트에 있으면1 아니면 0반환
int is_in_list(ListNode* head, element item)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link) 
		if (p->data == item)
			return 1;
	return 0;
}
//단순 연결 리스트에 존재하는 노드의 수를 반환
int get_length(ListNode* head)
{
	ListNode* p = head;
	int len = 0;

	while (p != NULL) {
		len++;
		p = p->link;
	}
	return len;
}
//단순연결리스트의 모든 데이터 값을 더한 합을 반환
int get_total(ListNode* head)
{
	ListNode* p = head;
	int total = 0;

	while (p != NULL) {
		total += p->data;
		p = p->link;
	}
	return total;
}
//pos위치(0이 첫번째 노드)에 있는 노드의 data를 반환
element get_entry(ListNode* head, int pos)
{
	//pos가 나오면 pos 유효성 검사 !!!
	ListNode* p = head;

	if (pos < 0)
		error("노드가 없습니다.\n");
	else {
		for (int i = 0; i < pos-1; i++)
			p = p->link;
	}
	return p->data;
}


//ListNode* delete_by_key(ListNode* head, int key)
//{
//	int i = 0;
//	ListNode* p = head;
//
//	//경우2일때, 1차
//	/*while (p != NULL) {
//		if (p->data == key) 
//			return delete_pos(head, i);
//		p = p->link;
//		i++;
//	}*/
//
//	//delete없이 짜보기, 경우 0,1,2생각하기
//	printf("리스트에 %d값이 없습니다.", key);
//	return head;
//}


ListNode* delete_by_key(ListNode* head, int key) {
	ListNode* p = head;
	int i = 0;

	while (p != NULL) {
		if (p->data == key) {
			return delete_pos(head, i);
		}
		p = p->link;
		i++;
	}

	printf("%d값을 지닌 노드는 존재하지 않는다\n", key);
	return head;
}

int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3;
	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);
	//list1의 맨 뒤 노드를 삭제한다 즉, list1 = 20->30->
	list1 = delete_last(list1);
	// list1을 출력
	print_list(list1);
	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다.
	for (int i = 1; i <= 4; i++) {
		list2 = insert_last(list2, i * 11);
	}
	// list2를 출력
	print_list(list2);
	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
	list2 = delete_last(list2);
	// list2를 출력
	print_list(list2);
	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
	list3 = reverse(list2);
	//list3를 출력한다.
	print_list(list3);
	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.
	list1 = concat(list1, list3);
	//list1을 출력한다.
	print_list(list1);
   //(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자 

	printf("%d\n", is_in_list(list1,41));
	printf("%d\n", get_length(list1));
	printf("%d\n", get_total(list1));
	printf("%d\n", get_entry(list1,2));
	
	print_list(list1);
	print_list(delete_by_key(list1, 20));
	print_list(insert_pos(list1, 1, 99));
	print_list(delete_pos(list1, 1));
	
}