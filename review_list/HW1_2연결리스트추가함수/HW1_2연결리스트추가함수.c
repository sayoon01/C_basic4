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

// HW1_2, 새로 추가한 함수들

// item이 리스트에 있는지 확인
int is_in_list(ListNode* head, element item) {
	ListNode* p;

	for (p = head; p != NULL; p = p->link) {
		if (p->data == item)
			return 1;
	}

	return 0;
}

// 단순연결리스트에 존재하는 노드의 수 반환
int get_length(ListNode* head) {
	ListNode* p;
	int length = 0;

	for (p = head; p != NULL; p = p->link) {
		length++;
	}

	return length;
}

// 단순연결리스트의 모든 데이터 값을 더한 합 반환
int get_total(ListNode* head) {
	ListNode* p;
	int total = 0;

	for (p = head; p != NULL; p = p->link) {
		total += p->data;
	}

	return total;
}

// pos위치에 있는 노드의 data를 반환
element get_entry(ListNode* head, int pos) {
	ListNode* p = head;
	int i = 0;

	while (i < pos) {
		p = p->link;
		i++;
	}

	return p->data;
}

// pos위치의 노드를 삭제
ListNode* delete_pos(ListNode* head, int pos) {
	ListNode* p = head;
	int i = 1;

	while (i < pos) {
		p = p->link;
		i++;
	}
	head = delete_next(head, p);

	return head;
}

// 해당하는 값을 찾아서 삭제
ListNode* delete_by_key(ListNode* head, int key) {
	ListNode* p = head;
	int i = 0;

	for (p = head; p != NULL; p = p->link) {
		if (p->data == key)
			return delete_pos(head, i);
		i++;
	}

	return NULL;
}

// pos 위치에 value를 갖는 노드 추가
ListNode* insert_pos(ListNode* head, int pos, element value) {
	ListNode* p = head;
	int i;

	if (pos == 0) {
		return insert_first(head, value);
	}
	else {
		for (i = 1; i < pos; i++) {
			p = p->link;
		}

		return insert_next(head, p, value);
	}
}

int main(void) {
	ListNode* list1 = NULL, * list2 = NULL, * list3;
	element item;
	int index;

	// list1 = 30->20->10->, 10 20 30의 순으로 삽입
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	printf("list1 = ");
	print_list(list1);

	// list1의 맨 앞 노드 삭제, list1 = 20->10
	list1 = delete_first(list1);
	printf("list1 = ");
	print_list(list1);

	// list2 = 11->22->33->44->, 11 22 33 44의 순으로 삽입
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);
	printf("list2 = ");
	print_list(list2);

	// list2의 맨 뒤 노드 삭제, list2 = 11->22->33->
	list2 = delete_last(list2);
	printf("list2 = ");
	print_list(list2);

	// list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다, list3 = 33->22->11->
	list3 = reverse(list2);
	printf("list3 = ");
	print_list(list3);

	// list1과 list3를 합쳐서 list1이 가리키게 한다, list1 = 20->10->33->22->11->
	list1 = concat(list1, list3);
	printf("list1 = ");
	print_list(list1);

	// is_in_list()
	printf("리스트에 유무 확인하고 싶은 값: ");
	scanf("%d", &item);
	if (is_in_list(list1, item))
		printf("%d는 리스트에 있습니다.\n", item);
	else
		printf("%d는 리스트에 없습니다.\n", item);

	// get_length()
	printf("리스트의 길이는 %d입니다.\n", get_length(list1));

	// get_total()
	printf("리스트의 데이터들을 더한 값은 %d입니다.\n", get_total(list1));

	// get_entry()
	printf("리스트에 확인하고 싶은 값: ");
	scanf("%d", &item);
	printf("%d에 있는 노드의 값은 %d입니다.\n", item, get_entry(list1, item));

	// delete_by_key()
	printf("삭제하고 key값: ");
	scanf("%d", &item);
	list1 = delete_by_key(list1, item);
	printf("list1 = ");
	print_list(list1);

	// insert_pos()
	printf("삽입하고 싶은 원하는 index: ");
	scanf("%d %d", &index, &item);
	list1 = insert_pos(list1, index, item);
	printf("list1 = ");
	print_list(list1);

	return 0;
}