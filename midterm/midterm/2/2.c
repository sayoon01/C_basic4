

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

void init(DlistNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void display(DlistNode* phead)
{
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}
// 노드 new_node를 노드 before의 오른쪽에 삽입한다.
void dinsert_node(DlistNode* before, element data)
{
	DlistNode* new_node;
	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	new_node->data = data;

	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

void ddelete(DlistNode* phead, DlistNode* removed)
{
	if (removed == phead) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void dinsert_sorted(DlistNode* phead, element key) // 이 함수를 작성한다
{
	DlistNode* p;
	DlistNode* newNode = (DlistNode*)malloc(sizeof(DlistNode));
	newNode->data = key;


	for (p = phead->rlink; p->rlink != phead; p = p->rlink) {
		if (p->data <= key && key <= p->rlink->data) {
			newNode->llink = p;
			p->rlink->llink = newNode;
			newNode->rlink = p->rlink;
			p->rlink = newNode;
		}
			//return phead;
	}

	//newNode->llink = p;
	//phead->
	//newNode->rlink = phead;

}
int main(void) // 변경하지 말라
{
	DlistNode head_node;
	int n, key;
	init(&head_node);
	scanf("%d", &n);
	while (n != -1) {
		dinsert_node(head_node.llink, n);
		scanf("%d", &n);
	}
	scanf("%d", &key);
	//display(&head_node);
	dinsert_sorted(&head_node, key);
	display(&head_node);
}
