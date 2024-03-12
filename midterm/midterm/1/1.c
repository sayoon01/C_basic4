
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 ======
#define MAX_QUEUE_SIZE 4
typedef int element;
typedef struct { // 큐 타입
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

void nodeIncrease(QueueType* q) // 이 함수를 작성한다
{
	int n = 10;
	for (int i = (q->front + 1) % MAX_QUEUE_SIZE; i <= q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
		i %= MAX_QUEUE_SIZE;
		q->queue[i] = q->queue[i] * n;
		n = n * 10;
	}
}

void print_queue(QueueType* q) // 이 함수를 작성한다
{
	// 코드를 작성한다
	int i;

	i = (q->front + 1) % MAX_QUEUE_SIZE;
	while (i <= q->rear) {
		i %= MAX_QUEUE_SIZE;
		printf("%d->", q->queue[i]);
		i = (i + 1) % MAX_QUEUE_SIZE;
	}
	printf("end\n");
}

int main(void) // 변경하지 말라
{
	QueueType q;
	char choice;
	element data;

	init_queue(&q);
	scanf("%c", &choice);
	while (choice != 'q') {
		switch (choice) {
		case 'e':
			scanf("%d", &data);
			enqueue(&q, data);
			break;
		case 'd':
			dequeue(&q);
		}
		while (getchar() != '\n');
		scanf("%c", &choice);
	}

	nodeIncrease(&q);
	print_queue(&q);

	return 0;
}