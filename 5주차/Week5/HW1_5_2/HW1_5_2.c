//단순 연결 리스트로 구현된 ADT 활용 연습 #2 텍스트에디터
//컴퓨터학과 20200990 윤상아
#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHAR_PER_LINE 100
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char line[MAX_CHAR_PER_LINE]; //1)한 라인을 포함하는 노드를 구성하기 위해 element의 타입을 이렇게 바꾼다
}element;
typedef struct ListNode { // 여기서는 구조체명 생략 불가능
	element data;
	struct ListNode* link;
}ListNode; // 이 시점 이후 구조체타입

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void display_te(ListNode* head)// text editor를 위해 변경
{
	int i = 1;
	ListNode* p;

	if (head == NULL)
		return;

	printf("--------text edited--------\n");
	for (p = head; p != NULL; p = p->link) {
		printf("(%d) %s", i++, p->data.line);
	}
}
ListNode* insert_first(ListNode* head, element value) 
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; p->link = head; // 배열로는 문자열복사 X 구조체변수는 가능
	p->link = head;
	head = p;

	return head;
}
ListNode* insert_next(ListNode* head, ListNode* pre, element value) 
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* p;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = value;
	newNode->link = NULL;

	if (head == NULL) {
		head = newNode;
	}
	else {
		for (p = head; p->link != NULL; p = p->link);
		p->link = newNode;
	}
	return head;
}

ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* p = head;

	if (pos == 0) {
		return insert_first(head, value);
	}
	else {
		for (int i = 0; i < pos - 1; i++)
			p = p->link;
		return insert_next(head, p, value);
	}
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;

	removed = head;
	head = removed->link;
	free(removed);

	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;

	if (head == NULL)
		error("삭제할 항목이 없음");
	if (head->link == NULL) {
		free(temp);
		head = NULL;
	}
	else {
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}

		removed = temp;
		prevTemp->link = NULL;
		free(removed);
	}

	return head;
}
ListNode* delete_next(ListNode* head, ListNode* pre) {
	ListNode* p = pre->link;
	pre->link = p->link;
	free(p);

	return head;
}
ListNode* delete_pos(ListNode* head, int pos) {
	ListNode* p = head;
	int i;

	if (pos == 0) {
		return delete_first(head);
	}
	else {
		for (i = 0; i < pos - 1; i++) 
			p = p->link;
		return delete_next(head, p);
	}
}
element get_entry(ListNode* head, int pos) {
	ListNode* p = head;
	int i;

	for (i = 0; i < pos - 1; i++) 
		p = p->link;

	return p->data;
}

char askChoice(void) 
{
	char choice;

	printf("------------------------------\n");
	printf("a: 텍스트 끝에 라인 추가\n");
	printf("i: 라인 번호로 라인 추가\n");
	printf("d: 라인 번호로 라인 삭제\n");
	printf("v: 라인 번호로 해당 라인 출력\n");
	printf("p: 전체 텍스트 출력\n");
	printf("q: 끝\n");

	printf("메뉴 선택:");

	scanf("%c", &choice);

	return choice;
}
int main(void)
{
	ListNode* list = NULL;
	char choice;
	int lineNb;
	element newElement;

	while ((choice = askChoice()) != 'q') {
		switch (choice) {
		case 'a':
			printf("텍스트 끝에 삽입할 라인: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

			list = insert_last(list, newElement);
			display_te(list);
			break;
		case 'i':
			printf("삽입할 라인 번호: ");
			scanf("%d", &lineNb);

			printf("삽입할 라인: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

			list = insert_pos(list, lineNb - 1, newElement);
			display_te(list);
			break;
		case 'd':
			printf("삭제할 라인 번호: ");
			scanf("%d", &lineNb);
			while (getchar() != '\n');

			list = delete_pos(list, lineNb - 1);
			display_te(list);
			break;
		case 'v':
			printf("출력할 라인 번호: ");
			scanf("%d", &lineNb);
			while (getchar() != '\n');

			printf("%s\n", get_entry(list, lineNb).line);
			break;
		case 'p':
			display_te(list);
			while (getchar() != '\n');
		}
	}
}