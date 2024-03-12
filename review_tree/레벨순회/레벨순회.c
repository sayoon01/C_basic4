//큐를 명시적으로 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// 원형 큐 코드 시작
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류
void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	//exit(1);
}

// 초기화
void init(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

// 삭제
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;

		return q->data[q->front];
	}
}

// 레벨 순회
void level_order(TreeNode* ptr) {
	QueueType q;

	init(&q);

	if (ptr == NULL)
		return;

	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("[%d] ", ptr->data);

		if (ptr->left)
			enqueue(&q, ptr->left);

		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}


TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("레벨 순회=");
	level_order(root);
	printf("\n");

	return 0;
}