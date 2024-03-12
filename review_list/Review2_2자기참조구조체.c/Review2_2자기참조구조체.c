#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // 이 시점에서는 ListNode가 구조체명
	int number;
	struct ListNode* link; // 자기참조구조체
} ListNode; // 여기서부터는 ListNode가 구조체 타입으로 정의되었음

// 6) 반복을 이용하여 노드리스트를 출력
// 1->10->2->30->44->
// temp를 head부터 시작하여 전진하면서 temp가 가리키는 number를 출력, temp가 NULL이 될 때까지
void displayList1(ListNode* head) {
	ListNode* temp = head;

	while (temp != NULL) {
		printf("%d->", temp->number);
		temp = temp->link;
	}
	//printf("\n");
}

// 7) 순환을 이용하여 노드리스트를 출력
void displayList2(ListNode* head) { // 실제로 head가 변화하지는 않음
	if (head == NULL)
		return;
	else {
		printf("%d->", head->number);
		displayList2(head->link); // head를 하나씩 전진시킨 것을 인자로 함
	}
}

int main(void) {
	ListNode* head, * newNode, * temp;

	// 1) head --> 10, NULL
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	head = newNode;

	// 2) head --> 10, rf --> 20, NULL
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 20;
	newNode->link = NULL;
	head->link = newNode;

	// 3) head -->10, rf --> 20, rf --> 30, NULL
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 30;
	newNode->link = NULL;
	head->link->link = newNode;

	// 4) head --> 10, rf --> 20, rf --> 30, rf --> 44, NULL
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 44;
	newNode->link = NULL;

	temp = head;
	while (temp->link != NULL)
		temp = temp->link; // 한 칸씩 전진
	temp->link = newNode;

	// 5) head --> 1, rf --> 10, rf --> 20, rf --> 30, rf --> 44, NULL
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 1;
	newNode->link = head;
	head = newNode;

	displayList1(head);
	printf("\n");
	displayList2(head);

	return 0;
}