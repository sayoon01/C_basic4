#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 3
#define MAX_STRING_SIZE 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//typedef char[MAX_STRING_SIZE] element;
typedef struct {
	char name[MAX_STRING_SIZE];
}element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	//exit(1);
}

// 초기화 함수
void init(QueueType* q)
{
	q->front = q->rear = 0;
}
//공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return q->front == q->rear;
}
//포화 상태 검출 함수
int is_full(QueueType* q)
{
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}
//삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}
//엿보기 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	else {
		return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
	}
}
int get_count(QueueType* q)
{
	if (q->front <= q->rear)
		return q->rear - q->front; // is_empty(q)의 경우 포함
	else
		return MAX_QUEUE_SIZE - q->front + q->rear; //is_full(q)의 경우 포함
}
void print_queue(QueueType* q)
{
	/*int start = (q->front + 1) % MAX_QUEUE_SIZE;
	int end = (q->rear + 1) % MAX_QUEUE_SIZE;
	//인덱스에 +1을 하면 MAX_QUEUE_SIZE를 초과할 수 있기 때문에 %연산을 해준다.
	 
	// empty가 아닐때만 출력해야 공백상태가 되었을시 쓰레기값을 출력안할 수 있음
	if (is_empty(q)) {	
		for (int i = start; i != end; i = (i + 1) % MAX_QUEUE_SIZE) {
			printf("%s ", q->queue->name[i]);
		}
	}
	printf("\n");*/

	//best 
	int temp = (q->front + 1) % MAX_QUEUE_SIZE;
	while (temp != (q->rear + 1) % MAX_QUEUE_SIZE) {
		printf("%s ", q->queue[temp].name);
		temp = (temp + 1) % MAX_QUEUE_SIZE;
	}
	printf("\n");
}
void matching(QueueType* q1, QueueType* q2, element person)
{
	if (is_empty(q2)) {
		printf("아직 대상자가 없습니다.");

		if (is_full(q1))
			printf("대기자가 꽉찼으니 담기회를 이용\n");
		else
		{
			printf("기다려주십시오.\n");
			enqueue(q1, person);
		}
	}
	else {
		enqueue(q1, person);
		printf("커플이 탄생했습니다! ");
		printf("%s와 %s\n", dequeue(q1).name, dequeue(q2).name);
	}
}
int main(void)
{
	QueueType manQ, womanQ;
	element newPerson;
	char choice;

	init(&manQ);
	init(&womanQ);

	printf("미팅 주선 프로그램입니다.\n");
	printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit> : ");
	scanf("%c", &choice);

	while (choice != 'q')
	{

		if (choice == 'i') {

			printf("이름을 입력 : ");
			scanf("%s", newPerson.name);

			//버퍼비우기
			while ((getchar()) != '\n');

			char gen;
			printf("성별을 입력<m or f> : ");
			scanf("%c", &gen, sizeof(gen), newPerson);

			if (gen == 'm')
				matching(&manQ, &womanQ, newPerson);
			else
				matching(&womanQ, &manQ, newPerson);
		}
		else if (choice == 'c') {
			printf("남성 대기자 %d명 : ", get_count(&manQ));
			print_queue(&manQ);
			printf("여성 대기자 %d명 : ", get_count(&womanQ));
			print_queue(&womanQ);
		}
		else
			printf("잘못된 입력 , ");

		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit> : ");
		scanf(" %c", &choice);
	}
}