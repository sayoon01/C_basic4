#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 헤드포인터가 맨 뒤에
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// 출력
void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL)return;

	//sol1
	/*p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->\n", p->data);*/
	//sol2
	p = head->link;
	do
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

// 삽입: 맨 뒤
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node; // 둘이 순서 바껴도 노상관
		node->link = node;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}

	return head;
}

// 삽입: 맨 앞
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node; // 둘이 순서 바껴도 노 상관
		node->link = node;
	}
	else {
		node->link = head->link;
		head->link = node;
	}

	return head;
}

// 삭제: 맨 앞
ListNode* delete_first(ListNode* head) {
	ListNode* temp;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);

		return head;
	}

}

// 삭제: 맨 뒤
ListNode* delete_last(ListNode* head) {
	ListNode* temp = head->link;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}

	if (head->link == NULL) {
		free(head);
		head = NULL;
	}
	else {
		while (temp->link != head)
			temp = temp->link;

		temp->link = head->link;
		head = temp;
	}

	return head;
}

ListNode* search(ListNode* head, element data) {
	ListNode* p;

	if (head == NULL)
		return NULL;

	for (p = head; p != NULL; p = p->link) {
		if (p->data == data)
			return p;
	}

	return NULL;
}

int get_size(ListNode* head) {
	ListNode* p;
	int size;

	if (head == NULL)
		return 0;
	else {
		size = 1;
		for (p = head; p->link != head; p = p->link)
			size++;
	}

	return size;
}

int main(void) {
	ListNode* head = NULL, * p;
	int data;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);

	// list = 20->30->40
	head = delete_first(head);
	print_list(head);

	// list = 20->30
	head = delete_last(head);
	print_list(head);

	printf("찾고 싶은 노드의 데이터는: ");
	scanf("%d", &data);
	p = search(head, data);
	printf("%d\n", p->data);

	printf("리스트의 길이는 %d입니다.\n", get_size(head));

	return 0;
}