#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode {
	element item;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* front, * rear;
} QueueType;

// 오류
void error(char* msg) {
	fprintf(stderr, "&s\n", msg);
}

// 초기화
void init(QueueType* q) {
	q->front = q->rear = NULL;
}

// 공백
int is_empty(QueueType* q) {
	return q->front == NULL;
	// q->rear == NULL;
}

// 포화
int is_full(QueueType* q) {
	return 0;
}

// 삽입
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));

	if (temp == NULL)
		error("메모리를 할당할 수 없습니다");
	else {
		temp->item = item;
		temp->link = NULL;

		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

// 삭제
element dequeue(QueueType* q) {
	QueueNode* temp = q->front;
	element item;

	if (is_empty(q))
		error("큐가 비어 있습니다");
	else {
		item = temp->item;
		q->front = q->front->link;

		if (q->front == NULL) // 노드가 한개일 경우
			q->rear = NULL;

		free(temp);
		return item;
	}
}

int main(void) {
	QueueType q;

	init(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));

	return 0;
}