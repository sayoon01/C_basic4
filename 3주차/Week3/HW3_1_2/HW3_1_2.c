//연결리스트로 구현한 큐
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element; // 요소의 타입
typedef struct QueueNode { // 큐의 노드의 타입
	element item;
	struct QueueNode* link;
}QueueNode;
typedef struct { // 큐의 ADT 구현
	QueueNode* front, * rear; 
}QueueType;

//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
void init(QueueType* q)
{
	q->front = q->rear = NULL;
}
//공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return q->front == NULL;
}
//포화 상태 검출 함수
int is_full(QueueType* q) //항상 거짓, 포화 상태일 때가 없다. 연결리스트로 구현하였으므로
{
	return 0;
}
//삽입 함수
void enqueue(QueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리를 할당할 수 없습니다.");
	else {
		temp->item = item; //데이터 저장
		temp->link = NULL; // 링크 필드를 NULL
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			/*1*/q->rear->link = temp;
			/*2*/q->rear = temp; // (1), (2) 순서 바뀌면 안된다
		}
	}
}
//삭제 함수
element dequeue(QueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // 공백상태
		error("큐가 비어 있습니다.");
	else {
		item = temp->item; //데이터를 꺼낸다
		q->front = q->front->link;
		if (q->front == NULL) // 노드가 1개 일 경우
			q->rear = NULL;
		free(temp); // 동적 메모리 해제
		return item; // 데이터 반환
	}
}
// 연결된 큐 테스트 함수
void main()
{
	QueueType q;

	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
}