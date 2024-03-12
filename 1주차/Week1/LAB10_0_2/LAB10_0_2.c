//20200990 컴퓨터학과 윤상아
#define _CRT_SECURE_NO_WARNINGS

//A.typedef를 이용하여 Student 타입을 정의하여 프로그램을 수정하라. 
//B.포인터 sp만을 사용하여 프로그램하라. aStudent를 사용하지않으려면 어떻게 해야하는가 ? ->연산자를 통해 구조체 포인터 sp를 이용해 구조체 변수에 접근 !
//① sizeof(Student)의 값은 ? 28 byte
//② Student 타입의 메모리를 생성하여 sp가 가르키게 하는 문장은 ? 4번문장

typedef struct student {
	char name[20];
	int midterm;
	int final;
} Student; // <- A

#include <stdio.h>
int main(void)
{
	struct student aStudent;
	struct student* sp = &aStudent; //4) sp가 aStudent를 가르키게한다

	printf("Enter student name: ");
	scanf("%s", sp->name); //5)
	printf("Enter midterm and final score: ");
	scanf("%d %d", &sp->midterm, &sp->final); //6)
	printf("\n이름\t중간\t학기말\n");
	printf("%s\t%d\t%d\n", sp->name, sp->midterm, sp->final); //7)
}