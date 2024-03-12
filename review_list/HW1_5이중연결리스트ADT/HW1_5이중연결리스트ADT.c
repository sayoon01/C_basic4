#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 헤드노드가 맨 앞에, 헤드노드는 값을 가지지 않고 시작과 끝만 구별
typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// 출력
void print_dlist(DListNode* phead) {
	DListNode* p;

	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("%d->", p->data);
	}
	printf("\n");
}

// 삽입: before노드 오른쪽에
void dinsert(DListNode* before, element data) {
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	newNode->data = data;

	newNode->llink = before; //1
	newNode->rlink = before->rlink; //2
	before->rlink->llink = newNode; //3 // 2,3 순서 바껴도 노상관
	before->rlink = newNode; //4
}

// 삭제: removed
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) // head노드가 removed일 경우 삭제않고 그냥 끝
		return;
	else {
		//순서 바껴도 ok
		removed->llink->rlink = removed->rlink;
		removed->rlink->llink = removed->llink;
		free(removed);
	}
}

// HW1_5 새로 추가한 함수들

// 역순 출력
void print_reverse_dlist(DListNode* phead) {
	DListNode* p;

	for (p = phead->llink; p != phead; p = p->llink) {
		printf("%d->", p->data);
	}
	printf("\n");
}

// data를 갖는 노드를 찾아서 반환
DListNode* search(DListNode* head, element data) {
	DListNode* p;

	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->data == data)
			return p;
	}

	return NULL;

	//DListNode* p;

	//if (head == head->rlink) // List가 비어있을 때
	//{
	//	printf("리스트가 비어 삭제를 못함\n");
	//	return NULL;
	//}
	//p = head->rlink;
	//do {
	//	if (p->data == data)
	//		return p;
	//	p = p->rlink;
	//} while (p != head);

	//printf("데이터를 찾지 못함\n");
	//return NULL;
}

int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));

	init(head);

	printf("추가 단계\n");

	// 맨 앞에 노드 삽입
	dinsert(head, 10);print_dlist(head);
	dinsert(head, 20);print_dlist(head);
	dinsert(head, 30);print_dlist(head);

	// 맨 뒤에 노드 삽입
	dinsert(head->llink, 5);print_dlist(head);
	dinsert(head->llink, 50);print_dlist(head);

	printf("\n삭제 단계\n");

	// 맨 앞 노드 삭제
	ddelete(head, head->rlink);print_dlist(head);

	// 맨 뒤 노드 삭제
	ddelete(head, head->llink);print_dlist(head);

	printf("\nHW1_5\n");

	// 역순 출력
	print_reverse_dlist(head);

	// 찾는 노드 반환
	printf("%d\n", search(head, 20)->data);

	return 0;
}