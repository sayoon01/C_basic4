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
	Score* tp = (Score*)malloc(sizeof(Score)); // Score s;는 안됌 동적 할당 필수, 변수 생존 시간 떄문

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
	Score s1, s2; // 포인터 p1,p2 대신에 구조체변수 s1, s2를 사용
	Score* p3;

	//값을 대입한다.각각(50, 100), (70, 70)
	s1.midterm = 50; s1.final = 100;
	s2.midterm = 70; s2.final = 70;

	printScore(&s1);
	printScore(&s2);

	printf("-----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(&s1, &s2));

	printf("-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(&s1, &s2));

	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}