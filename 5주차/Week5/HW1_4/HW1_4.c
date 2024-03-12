//원형 연결 리스트로 구현된 ADT
//20200990 컴퓨터학과 윤상아
#define _CRT_SEUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head)
{	
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("리스트의 끝\n");
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) { // 경우 0
		/*A*/node->link = node;
		/*B*/head = node;  // A,B순서 바꿔도 노상관
	}
	else {// 경우 1
		node->link = head->link;
		head->link = node;
	}
	return head;
}
// 단순연결리스트: O(n) -> 원형연결리스트: O(1)
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {//경우:0
		/*A*/node->link = node;
		/*B*/head = node;  // A,B순서 바꿔도 노상관
	}
	else {//경우:1
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
ListNode* delete_first(ListNode* head)
{
	ListNode* temp; //free하는 부분이 있으므로 등장 !
	if (head == NULL) {// 경우 : 0 
		printf("리스트가 비어 삭제 못함\n");
		return NULL;
	}
	else if (head == head->link) {// 경우 : 1 노드가 하나
		temp = head;
		free(temp);
		head = NULL;
	}
	else { // 경우 : 2
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}
//O(n)
//리스트의 마지막 노드를 삭제하고 헤드노드를 반환한다.
//리스트가 비어있으면 "리스트가 비어있어 삭제를 못함"이라 출력한다
ListNode* delete_last(ListNode* head)
{
	ListNode* p;
	//ListNode* prevTemp = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) {// 경우 : 0 
		printf("리스트가 비어있어 삭제를 못함\n");
		return NULL;
	}else if (head == head->link) {
		//1차시도
		/*free(temp);
		head = NULL;*/
		//2차
		free(head);
		head = NULL;
	}
	else {
		//1차시도
		/*prevTemp = temp;
		while (prevTemp!= temp) {
			prevTemp = prevTemp->link;
		}
		free(temp);
		head = prevTemp;*/
		//2차시도
		p = head->link;
		while (p->link != head) 
			p = p->link;
	
		p->link = head->link;
		head = p;
	}
	return head;
}
//data를 가지고 있는 첫번째 노드를 찾아서 반환한다.
//1차 시도
//Listnode* search(Listnode* head, element data)
//{
//	Listnode* p = head;
//
//	do {
//		if (p->data == data) {
//			return p;
//		}
//		p = p->link;
//	} while (p->link != head);
//
//	return NULL;
//}
//사실 이해 잘 안됌 다시 search 코드 보기
ListNode* search(ListNode* head, element data)
{
	ListNode* p;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}

	p = head;
	do {
		if (p->data == data) 
			return p;
		p = p->link;
	} while (p->link != head);

	return NULL; // 데이터를 찾지 못한 경우 NULL 반환
}


//리스트의 길이를 반환한다.
int get_size(ListNode* head)
{
	ListNode* p = head;
	int size = 0;
	do
	{
		size++;
		p = p->link;
	} while (p->link != head->link);
	return size;
}
int main(void)
{
	ListNode* head = NULL;

	//list = 10->20->30->리스트의 끝
	head = insert_last(head, 20); print_list(head);
	head = insert_last(head, 30); print_list(head);
	head = insert_first(head, 10); print_list(head);

	/*head = delete_last(head); print_list(head);
	head = delete_first(head); print_list(head);
	head = delete_last(head); print_list(head);
	head = delete_last(head); print_list(head);*/
	printf("리스트의 길이는 %d\n", get_size(head));

	//head = search(head, 30); printf("%d\n", head->data);
	head = search(head, 71); printf("%d\n", head->data);
	return 0;
}