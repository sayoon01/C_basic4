#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	//exit(1);
}

// 초기화 함수
void init(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}

// 공백 검출
int is_empty(QueueType* q) {
	return (q->rear == q->front);
}

// 포화 검출
int is_full(QueueType* q) {
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

// 삽입
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}

	q->data[++(q->rear)] = item;
}

// 삭제
element dequeue(QueueType* q) {
	element item;

	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}

	item = q->data[++(q->front)];
	return item;
}

// 출력
void queue_print(QueueType* q) {
	int i;

	for (i = q->front + 1; i <= q->rear; i++) {
		printf("%d->", q->data[i]);
	}
	printf("끝\n");
}

int main(void) {
	int item;
	QueueType q;

	init(&q);
	//queue_print(&q);

	enqueue(&q, 10);queue_print(&q);
	enqueue(&q, 20);queue_print(&q);
	enqueue(&q, 30);queue_print(&q);
	enqueue(&q, 40);queue_print(&q);
	enqueue(&q, 50);queue_print(&q);
	enqueue(&q, 10);queue_print(&q);

	item = dequeue(&q);queue_print(&q);
	item = dequeue(&q);queue_print(&q);
	item = dequeue(&q);queue_print(&q);

	return 0;
}