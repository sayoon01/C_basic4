#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head) // 리스트의 끝에 end를 출력하게 수정하라
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("end\n");
}
//-----------------------------------------
int is_in_list(ListNode* head, element item) // item 이 리스트에 있으면 1 을 아니면 0 을 반환
{
	for (ListNode* p = head; p != NULL; p = p->link)
		if (p->data == item)
			return 1;
	return 0;
}
int get_length(ListNode* head) // 단순 연결 리스트에 존재하는 노드의 수를 반환
{
	int length = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		length++;
	return length;
}
// pos위치의 노드를 삭제
ListNode* delete_pos(ListNode* head, int pos) {
	ListNode* p = head;
	int i = 1;

	while (i < pos) {
		p = p->link;
		i++;
	}
	head = delete(head, p);

	return head;
}
ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* p = head;
	int i = 0;

	for (p = head; p != NULL; p = p->link) {
		if (p->data == key)
			return delete_pos(head, i);
		i++;
	}

	return NULL;
}
int main(void)
{
	ListNode* list = NULL;
	int n, key;

	scanf("%d", &n);
	while (n != -1) {
		list = insert_first(list, n);
		scanf("%d", &n);
	}
	scanf("%d", &key);
	print_list(list);
	//print_list(list);
	int result = delete_by_key(list, key);
	print_list(list);
}