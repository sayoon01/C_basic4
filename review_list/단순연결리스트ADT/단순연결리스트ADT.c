#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link; // 자기 참조 구조체
} ListNode; // 리스트 노드 정의

// 오류
void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	//exit(1);
}

// 삽입: pre노드 뒤에
ListNode* insert_next(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}

// 삽입: 맨 처음에
ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;
	head = p;

	return head;
}

// 삽입: 맨 뒤
ListNode* insert_last(ListNode* head, int value) {
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = NULL;

	if (head == NULL) // 노드가 0개일 때
		head = p;
	else {
		while (temp->link != NULL) // 노드가 1개이상일 때
			temp = temp->link;
		temp->link = p;
	}

	return head;
}

// 삭제: pre노드 다음
ListNode* delete_next(ListNode* head, ListNode* pre) {
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link;
	free(removed);

	return head;
}

// 삭제: 맨 처음
ListNode* delete_first(ListNode* head) {
	ListNode* removed;

	if (head == NULL)
		error("삭제할 항목이 없음");
	else {
		removed = head;
		head = removed->link;
		free(removed);
	}

	return head;
}

// 삭제: 맨 뒤
ListNode* delete_last(ListNode* head) {
	ListNode* temp = head;
	ListNode* pretemp = (ListNode*)malloc(sizeof(ListNode));
	ListNode* removed;

	if (head == NULL) // 노드 0개
		error("삭제할 항목이 없음");

	if (temp->link == NULL) { // 노드 1개
		head = NULL;
		free(temp);
	}
	else { // 노드 2개 이상
		while (temp->link != NULL) {
			pretemp = temp;
			temp = temp->link;
		}
		pretemp->link = NULL;
		free(temp);
	}

	return head;
}

// 출력
void print_list(ListNode* head) {
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("\n");
}

// 검색, 반환값이 ListNode
ListNode* search(ListNode* head, int x) {
	ListNode* p;

	for (p = head; p != NULL; p = p->link) {
		if (p->data == x) {
			return p;
		}
	}

	return NULL;
}

// 결합
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;

	if (head1 == head2)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;

		return head1;
	}
}

// 역순
ListNode* reverse(ListNode* head) {
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

int main(void) {
	ListNode* head1 = NULL, * head2, * head3, * head4;
	int i;

	for (i = 0; i < 5; i++) {
		head1 = insert_last(head1, i * 10);
		print_list(head1);
	}

	head2 = reverse(head1);
	print_list(head2);

	head1 = NULL;
	head1 = insert_first(head1, 100);
	head1 = insert_first(head1, 200);
	print_list(head1);

	head1 = concat(head1, head2);
	print_list(head1);

	return 0;
}