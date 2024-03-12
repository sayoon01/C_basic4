#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

// 오류
void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
}

// 초기화
void init(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

// 공백 검출
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 검출
int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

// 삽입
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 1) rear를 하나 증가시키고
	q->data[q->rear] = item; // 2) data를 넣기
}

// 삭제
element dequeue(QueueType* q) {
	element item;

	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return;
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	item = q->data[q->front];

	return item;

	/*if (is_empty(q))
		error("큐가 공백상태입니다.");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}*/
}

// 엿보기
element peek(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return;
	}

	return q->data[(q->front + 1) % MAX_QUEUE_SIZE]; // front를 진짜로 전진시키지않고 전진이 된 상태만 확인
}

// 출력
void queue_print(QueueType* q) {
	int i;

	i = (q->front + 1) % MAX_QUEUE_SIZE;
	while (i <= q->rear) {
		i %= MAX_QUEUE_SIZE;
		printf("%d->", q->data[i]);
		i = (i + 1) % MAX_QUEUE_SIZE;
	}


	printf("끝\n");
}

int main(void) {
	QueueType q;

	init(&q);
	printf("front = %d, rear = %d\n", q.front, q.rear);

	enqueue(&q, 1);queue_print(&q);
	enqueue(&q, 2);queue_print(&q);
	enqueue(&q, 3);queue_print(&q);
	enqueue(&q, 4);queue_print(&q);
	enqueue(&q, 5);queue_print(&q);
	enqueue(&q, 6);queue_print(&q);
	enqueue(&q, 7);queue_print(&q);
	enqueue(&q, 8);	queue_print(&q);

	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));

	printf("front = %d, rear = %d\n", q.front, q.rear);

	return 0;
}