//연결 리스트를 사용하여 특정 키(값)의 출현 횟수를 세는 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

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

int keyCount(ListNode* head, element key)
{
	// 코드 작성
	int count = 0;
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == key)
			count++;
		p = p->link;
	}
	return count;

	//HJ ANSWER
	/*int count = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link) {
		if (p->data == key)
			count++;
	}

	return count;*/
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
	printf("%d\n", keyCount(list, key));
}