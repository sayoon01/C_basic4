// 20200990 컴퓨터학과 윤상아

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

///*LAB11_1_1*/
//// 1) typedef으로 구조체 타입 Score 정의하라.
//typedef struct score {
//	int midterm;
//	int final;
//} Score;
//
////1)성적 출력
//void printScore(Score s) // call by value
//{
//	printf("중간고사 성적은 %d\n", s.midterm);
//	printf("기말고사 성적은 %d\n", s.final);
//}
//
////2)성적  비교
//Score biggerScore(Score s1, Score s2) // call by value
//{
//	return ((s1.midterm + s1.final) > (s2.midterm + s2.final)) ? s1 : s2;
//}
//
////3)총합
//Score totalScore(Score s1, Score s2)
//{
//	/*Score total;
//
//	total.midterm = s1.midterm + s2.midterm;
//	total.final = s1.final + s2.final;*/
//
//	Score total = { s1.midterm + s2.midterm,s1.final + s2.final };
//	return total;
//}
//
//Score createScore(int mid, int fin)
//{
//	//Score s;
//	//s.midterm = mid;
//	//s.final = fin;
//	Score s = { mid,fin };
//	return s;
//}
//int main(void)
//{
//	Score s1, s2, s3;
//	s1.midterm = 50;
//	s1.final = 100;
//	s2.midterm = 70;
//	s2.final = 70;
//
//	printf("1)--------------------------\n");
//	printScore(s1);
//	printScore(s2);
//
//	printf("2)--------------------------\n");
//	printf("둘중 성적이 좋은 점수 : \n");
//	printScore(biggerScore(s1, s2));
//
//	printf("3)--------------------------\n");
//	printf("두 성적의 총 합 : \n");
//	printScore(totalScore(s1, s2));
//
//	printf("4)--------------------------\n");
//	s3 = createScore(99, 99);
//	printScore(s3);
//}

/*LAB11_1_2*/
// 1) typedef으로 구조체 타입 Score 정의하라.
typedef struct {
	int midterm;
	int final;
} Score;

//1)성적 출력
// 매개변수 변경
void printScore(Score *sp) // call by value
{
	printf("중간고사 성적은 %d\n", sp->midterm);
	printf("기말고사 성적은 %d\n", sp->final);
}

//2)성적  비교
//매개변수 변경, 반환타입변경
Score *biggerScore(Score *sp1, Score *sp2) // call by value
{
	if ((sp1->midterm + sp1->final) > (sp2->midterm + sp2->final))
		return sp1;
	else
		return sp2;
}

//3)총합
void totalScore(Score *sp1, Score *sp2,Score *tmp)
{
	/*Score total;

	total.midterm = s1.midterm + s2.midterm;
	total.final = s1.final + s2.final;*/

	tmp->midterm = sp1->midterm + sp2->midterm;
	tmp->final = sp1->final + sp2->final;
	
}

Score createScore(int mid, int fin)
{
	//Score s;
	//s.midterm = mid;
	//s.final = fin;
	Score s = { mid,fin };
	return s;
}
int main(void)
{
	Score s1, s2, temp;
	s1.midterm = 50;
	s1.final = 100;
	s2.midterm = 70;
	s2.final = 70;

	printf("1)--------------------------\n");
	printScore(&s1);
	printScore(&s2);

	printf("2)--------------------------\n");
	printf("둘중 성적이 좋은 점수 : \n");
	printScore(biggerScore(&s1, &s2));

	printf("3)--------------------------\n");
	printf("두 성적의 총 합 : \n");
	totalScore(&s1, &s2, &temp);
	printScore(&temp);

	printf("4)--------------------------\n");
	/*temp = createScore(99, 99);
	printScore(&temp);*/
	printScore(createScore(99, 99));
 
 
}

/*LAB11_2*/
//struct student {
//	char name[20];
//	int midterm;
//	int final;
//	int average;
//};
//
//typedef struct student Student;
//// 구조체명, 타입 선언 두개로 나눠서 할 수도 있음
//
//// 학생들의 이름, 중간, 기말 평균 출력
//void printStudent(Student *s) //<- 매개변수는 구조체포인터
//{
//	printf("%s\t", s->name);
//	printf("%d\t%d\t%d\n", s->midterm, s->final, s->average);
//}
//void readStudentScore(Student *s)
//{
//	printf("Enter student name : ");
//	scanf("%s", s->name);
//	printf("Enter midterm and final score : ");
//	scanf("%d %d", &s->midterm, &s->final);
//}
//void calculateStudentAverage(Student* s)
//{
//	s->average = (s->midterm + s->final) / 2;
//}
//int main(void)
//{
//	Student s[40]; // <- 구조체 배열
//	int num, i;
//
//	printf("Enter a number of student : ");
//	scanf("%d", &num);
//
//	// 학생들 정보 입력 
//	for (i = 0; i < num; i++)
//	{
//		readStudentScore(&s[i]);
//		/*printf("Enter student name : ");
//		scanf("%s", s[i].name);
//		printf("Enter midterm and final score : ");
//		scanf("%d %d", &s[i].midterm, &s[i].final);*/
//	}
//
//	//학생들의 평균 계산
//	/*for(i = 0; i < num; i++)
//	{
//		s[i].average = (s[i].midterm + s[i].final) / 2;
//	}*/
//	for (i = 0; i < num; i++)
//	{
//		calculateStudentAverage(&s[i]);
//	}
//
//	// 학생들의 정보 출력
//	printf("\n이름\t중간\t학기말\t평균\n");
//	for (i = 0; i < num; i++)
//	{
//		printStudent(&s[i]);
//	}
//}

/*HW11_1*/
//struct student {
//	char name[20];
//	int midterm;
//	int final;
//	int average;
//	char grade;
//};
//
//int main(void)
//{
//	struct student s[3];
//	struct student* sp = s;
//
//	// 학생들의 정보 입력받고 평균 구하기
//	for (int i = 0; i < 3; i++) {
//		printf("Enter student name : ");
//		scanf("%s", sp->name);
//
//		printf("Enter midterm and final score : ");
//		scanf("%d %d", &sp->midterm, &sp->final);
//
//		sp->average = (sp->midterm + sp->final) / 2;
//		sp++; 
//	}
//
//	sp = s; // 포인터 가르키는 위치 조정
//	// 성적 출력 후  평균을 통해 점수 매기기
//	printf("이름\t중간\t학기말\t평균\n");
//	for (int i = 0; i < 3; i++) {
//		printf("%s\t%d\t%d\t%d\n", sp->name, sp->midterm, sp->final, s[i].average);
//
//		if (sp->average >= 80)
//			sp->grade = 'A';
//		else if (s[i].average >= 50)
//			sp->grade = 'B';
//		else
//			sp->grade = 'F';
//		sp++;
//	}
//
//	sp = s;
//	//이름과 학점 출력
//	printf("이름\t학점\n");
//	for (int i = 0; i < 3; i++) {
//		printf("%s\t%c\n", sp->name, sp->grade);
//		sp++;
//	}
//
//	sp = s;
//	//학생들의 중간 평균 , 기말 평균 각각 구하기
//	int midAverage = 0, finAverage = 0;
//	for (int i = 0; i < 3; i++) {
//		midAverage += sp->midterm;
//		finAverage += sp->final;
//		sp++;
//	}
//	midAverage /= 3;
//	finAverage /= 3;
//
//	printf("중간고사의 평균 = %d\n", midAverage);
//	printf("기말고사의 평균 = %d\n", finAverage);
//}

/*HW13_1*/ 
//struct student {
//	char name[20];
//	int midterm;
//	int final;
//	int average;
//};
//typedef struct student Student;
//// typedef사용하여 Student 정의
//
//struct cClass {
//	int num;
//	Student s[40]; // 구조체 안의 구조체
//};
//typedef struct cClass CClass;
//// typedef 사용하여 CClass 정의
//
//void readStudentScore(Student* sp)
//{
//	printf("Enter student name : ");
//	scanf("%s", sp->name);
//	printf("Enter midterm and final score : ");
//	scanf("%d %d", &sp->midterm, &sp->final);
//}
//void calculateStudentAverage(Student* sp)
//{
//	sp->average = (sp->midterm + sp->final) / 2;
//}
//void printStudent(Student* sp)
//{
//	printf("%s\t", sp->name);
//	printf("%d\t%d\t%d\n", sp->midterm, sp->final, sp->average);
//}
//
//int main(void)
//{
//	CClass cp;
//	int i;
//	Student all = { "Total",0,0,0 };
//
//	printf("Enter a number of student : ");
//	scanf("%d", &cp.num);
//
//	
//	for (i = 0; i < cp.num; i++)
//	{
//		readStudentScore(&cp.s[i]);
//
//		/*printf("Enter student name : ");
//		scanf("%s", cp.s[i].name);
//		printf("Enter midterm and final score : ");
//		scanf("%d %d", &cp.s[i].midterm, &cp.s[i].final);*/
//	}
//
//	for (i = 0; i < cp.num; i++)
//	{
//		calculateStudentAverage(&cp.s[i]);
//		//cp.s[i].average = (cp.s[i].midterm + cp.s[i].final) / 2;
//	}
//
//	printf("\n 이름\t 중간\t 학기말\t 평균\n");
//	for (i = 0; i < cp.num; i++)
//		printStudent(&cp.s[i]);
//
//
//}

/*HW11_2*/
//struct student {
//	char name[20];
//	int midterm;
//	int final;
//	int average;
//};
//typedef struct student Student;
//// typedef사용하여 Student 정의
//
//struct cClass {
//	int num;
//	Student s[40]; // 구조체 안의 구조체
//};
//typedef struct cClass CClass;
//// typedef 사용하여 CClass 정의
//
////void readStudentScore(Student* sp)
////{
////	printf("Enter student name : ");
////	scanf("%s", sp->name);
////	printf("Enter midterm and final score : ");
////	scanf("%d %d", &sp->midterm, &sp->final);
////}
////void calculateStudentAverage(Student* sp)
////{
////	sp->average = (sp->midterm + sp->final) / 2;
////}
////void printStudent(Student* sp)
////{
////	printf("%s\t", sp->name);
////	printf("%d\t%d\t%d\n", sp->midterm, sp->final, sp->average);
////}
//void readClass(CClass* cp)
//{
//	for (int i = 0; i < cp->num; i++)
//	{
//		printf("Enter student name : ");
//		scanf("%s", cp->s[i].name);
//		printf("Enter midterm and final score : "); // 질문 cp->s[i]->name은 안되는지???
//		scanf("%d %d", &cp->s[i].midterm, &cp->s[i].final);
//	}
//}
//void calculateClassAverage(CClass* cp)
//{
//	for (int i = 0; i < cp->num; i++)
//	{
//		cp->s[i].average = (cp->s[i].midterm + cp->s[i].final) / 2;
//	}
//}
//void printClass(CClass* cp)
//{
//	for (int i = 0; i < cp->num; i++)
//		printf("%s\t%d\t%d\t%d\n", cp->s[i].name, cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
//}
//int main(void)
//{
//	CClass cp;
//
//	Student all = { "Total",0,0,0 };
//	
//	printf("Enter a number of student : ");
//	scanf("%d", &cp.num);
//
//	readClass(&cp);
//
//	calculateClassAverage(&cp);
//
//	printf("\n이름\t중간\t학기말\t평균\n");
//	printClass(&cp);
//}
