//20200990 컴퓨터학과 윤상아
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1) typedef으로 구조체 타입 Score 정의
typedef struct score {
	int midterm;
	int final;
} Score;

void printScore(Score* p) //2)
{
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
}

Score* biggerScore(Score* p1, Score* p2) //3)
{
	if ((p1->midterm + p1->final) > (p2->midterm + p2->final))
		return p1;
	else
		return p2;
}

Score* totalScore(Score* p1, Score* p2) //4)
{
	Score* tp = (Score*)malloc(sizeof(Score));

	tp->midterm = p1->midterm + p2->midterm;
	tp->final = p1->final + p2->final;

	return tp;
}

Score* createScore(int m, int f) //5)
{
	Score* tp = (Score*)malloc(sizeof(Score));

	tp->midterm = m;
	tp->final = f;

	return tp;
}

int main(void) 
{
	Score* p1, * p2, * p3;

	//1)p1, p2에 Score를 저장하기위한 메모리를 할당하고 
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score)); // malloc 함수 : 주어진 메모리크기 만큼의 메모리를 생성(할당)하여 그것을 가리키는 포인터를 반환한다

	//값을 대입한다.각각(50, 100), (70, 70)
	p1->midterm = 50; p1->final = 100;
	p2->midterm = 70; p2->final = 70;

	printScore(p1);
	printScore(p2);

	printf("-----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));

	printf("-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(p1, p2));

	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}