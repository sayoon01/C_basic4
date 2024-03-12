//연결 리스트를 구성하고,
//이 리스트 내에서 입력된 값을 정렬된 순서로 삽입하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void display(ListNode* head) //변경하지 말라
{
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL\n");
}

ListNode* insert_last(ListNode* head, int value) // 변경하지 말라
{

	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (head == NULL) // 공백 리스트이면
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;

		temp->link = p;
	}
	return head;
}

ListNode* insert_sorted(ListNode* head, int value)
{
	// 코드 작성
	//나의 비루한 답
	ListNode* temp = head, * preTemp = NULL;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = value;

	if (head == NULL) { // head가 NULL일때 무조건 !!!!! 
		newNode->data = value;
		newNode->link = NULL;
		head = newNode;

		return head;
	}

	while (temp != NULL) {
		if (newNode->data <= temp->data) { 
			newNode->link = head;
			head = newNode;
			return head;
		}
		else if (temp != head && temp->data >= newNode->data && preTemp->data <= newNode->data)
		{
			preTemp->link = newNode;
			newNode->link = temp;
			return head;
		}
		preTemp = temp;
		temp = temp->link;
	}
	return insert_last(head, value);

	//HJ ANSWER
	
	ListNode* p;
	ListNode* pre = NULL;
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));

	if (head == NULL) {
		new->data = value;
		new->link = NULL;
		head = new;
		
		return head;
	}

	for (p = head; p != NULL; p = p->link) {
		if (value <= p->data) {
			new->data = value;

			if (pre == NULL) {
				new->link = p;
				head = new;
			}
			else {
				new->link = pre->link;
				pre->link = new;
			}

			return head;
		}
		pre = p;
	}

	new->data = value;
	new->link = NULL;
	pre->link = new;

	return head;
	

}

int main(void) // 변경하지 말라
{
	ListNode* list = NULL;
	int n, key;

	scanf("%d", &n);
	while (n != -1) {
		list = insert_last(list, n);
		scanf("%d", &n);
	}
	scanf("%d", &key);
	list = insert_sorted(list, key);
	display(list);
}