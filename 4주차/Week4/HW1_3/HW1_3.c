//연결 리스트로 구현된 ADT 활용 연습
//20200990 컴퓨터학과 윤상아 
#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 여기서는 구조체명 생략 불가능
	element data;
	struct ListNode* link;

}ListNode; // 이 시점 이후 구조체타입

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
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
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; p->link = NULL;

	if (head == NULL) {
		head = p;
	}
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}
//pre가 가리키는 노드의 다음 노드를 삭제한다
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;

	if (head == NULL)
		error("삭제할 항목이 없음");

	removed = head;
	head = removed->link;
	free(removed);

	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;

	if (head == NULL)
		error("삭제할 항목이 없음");
	else if (head->link == NULL) {
		free(temp);
		head = NULL;
	}
	else { // O(n)
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
//pos 위치의 노드 삭제
ListNode* delete_pos(ListNode* head, int pos) {
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
void print_list(ListNode* head)
{
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

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
//다시 check 이중 포인터
void add_item(ListNode** phead, int new_item)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = new_item; newNode->link = NULL;

	//1차시도
	/*if (*phead == NULL) // 연결 리스트가 비어있는 경우 새로운 노드를 헤드로 설정
		*phead = newNode;
	else {
		ListNode* current = *phead;
		while (current->link!= NULL)
			current = current->link;
		current->link = newNode;
	}*/
	//2차시도
	if (*phead == NULL)
		*phead=insert_first(*phead, new_item);
	else {
		if (get_weight(*phead) + newNode->data > 100) {
			printf("최대 무게(100kg)초과로 아이템 %d를 추가할 수 없음\n", newNode->data);
			return;
		}
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		*phead=insert_next(*phead, p, new_item);
	}
}
int get_weight(ListNode* head)
{
	ListNode* p = head;
	int weightTotal = 0;

	while (p != NULL) {
		weightTotal += p->data;
		p = p->link;
	}
	return weightTotal;
}
void delete_item(ListNode** phead, int item)
{
	ListNode* p = search(*phead, item);
	if (p == NULL)
		printf("item %d는 보유하고있지않습니다.\n", item);
	else {
		delete_by_key(*phead, item);
	}
}
void display(ListNode* head)
{
	ListNode* p = head;
	if (head == NULL)
		return NULL;

	printf("( ");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(")\n");
}
int main(void)
{
	int new_item;
	char choice;
	ListNode* list = NULL;

	/*add_item(&list, 20); display(list);
	add_item(&list, 30); display(list);
	add_item(&list, 40); display(list);
	add_item(&list, 50); display(list);*/

	printf("enter a(add) d(delete) or q(quit) : ");
	scanf("%c", &choice);
	while (choice != 'q') {
		switch (choice) {
		case 'a':
			while (getchar() != '\n');
			printf("enter the weight of the item: ");
			scanf("%d", &new_item);
			add_item(&list, new_item);
			break;
		case 'd':
			while (getchar() != '\n');
			printf("enter the weight of the item: ");
			scanf("%d", &new_item);
			delete_item(&list, new_item);
			break;
		case 'q':
			break;
		}
		while (getchar() != '\n');
	}
}