//컴퓨터학과 20200990 윤상아
#define _CRT_SECURE_NO_WARNINGS
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
int main(void)
{
	ListNode* head1 = NULL, * head2;
	int i;

	for (i = 0; i < 5; i++) {
		head1 = insert_last(head1, i * 10);
		print_list(head1);
	}

	head2 = reverse(head1);
	print_list(head2);
	head2 = insert_next(head2, 1, 99);
	print_list(head2);
	//int i;
	//for (i = 0; i < 5; i++) {
	//	head1 = insert_last(head1, i * 10);
	//	print_list(head1);
	//}
	//head2 = reverse(head1);
	//print_list(head2);
	////head2 = insert_pos(head2, 1, 99);
	//print_list(head2);
	//head2 = delete_last(head2);
	//print_list(head2);
	//head1 = NULL;
	//head1 = insert_first(head1, 100);
	//head1 = insert_first(head1, 200);
	//print_list(head1);
	//head1 = concat(head1, head2);
	//print_list(head1);
}