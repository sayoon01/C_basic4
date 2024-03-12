#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*LAB10_0*/
//struct student {
//	char name[20];
//	int midterm;
//	int final;
//};
//
//int main(void)
//{
//	//struct student aStudent; // 구조체 변수 선언시 메모리가 생김
//
//	//printf("Enter student name : ");
//	//scanf("%s", aStudent.name); // == &aStudent.name[0]
//
//	//printf("Enter midterm and final score : ");
//	//scanf("%d %d", &aStudent.midterm, &aStudent.final); // .(dot) 연산자는 구조체 변수 멤버 각각에 접근
//
//	//printf("이름\t중간\t학기말\t\n");
//	//printf("%s\t%d\t%d\n", aStudent.name, aStudent.midterm, aStudent.final);
//
//	struct student s[3];
//	for (int i = 0; i < 3; i++) {
//		printf("Enter student name : ");
//		scanf("%s", s[i].name);
//		printf("Enter midterm and final score : ");
//		scanf("%d %d", &s[i].midterm, &s[i].final);
//	}
//
//	printf("\n이름\t중간\t학기말\t\n");
//
//	for (int i = 0; i < 3; i++) {
//		printf("%s\t%d\t%d\n", s[i].name, s[i].midterm, s[i].final);
//	}
//}

/*LAB10_1*/
//struct customer {
//	char name[40];
//	int age;
//};
//
//int main(void)
//{
//  struct customer aCustomer;
//	//struct customer aCustomer = { "박수희",36 };
//	struct customer cArray[2] = { {"장동건",38},{"고소영",38} };
//
//  strcpy(aCustomer.name,"박수희");
//  aCustomer.age = 36;
// 
//	printf("이름 : %s , 나이 : %d\n", aCustomer.name, aCustomer.age);
//	for (int i = 0; i < 2; i++) {
//		printf("Name = %s, Age = %d\n", cArray[i].name, cArray[i].age);
//	}
//}

/*HW10_1*/
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
//
//	for (int i = 0; i < 3; i++) {
//		printf("Enter student name : ");
//		scanf("%s", s[i].name);
//
//		printf("Enter midterm and final score : ");
//		scanf("%d %d", &s[i].midterm, &s[i].final);
//
//		s[i].average = (s[i].midterm + s[i].final) / 2;
//	}
//
//	printf("이름\t중간\t학기말\t평균\n");
//	for (int i = 0; i < 3; i++) {
//		printf("%s\t%d\t%d\t%d\n", s[i].name, s[i].midterm, s[i].final, s[i].average);
//
//		if (s[i].average >= 80)
//			s[i].grade = 'A';
//		else if (s[i].average >= 50)
//			s[i].grade = 'B';
//		else
//			s[i].grade = 'F';
//	}
//
//	printf("이름\t학점\n");
//	for (int i = 0; i < 3; i++) {
//		printf("%s\t%c\n", s[i].name, s[i].grade);
//	}
//
//	int midTotal = 0, finTotal = 0;
//	for (int i = 0; i < 3; i++) {
//		midTotal += s[i].midterm;
//		finTotal  += s[i].final;
//	}
//
//
//	printf("중간고사의 평균 = %d\n", midTotal/3);
//	printf("기말고사의 평균 = %d\n", finTotal/3);
//}

/*LAB10_0*/
//struct student {
//	char name[20];
//	int midterm;
//	int final;
//};
//
//int main(void)
//{
//	struct student aStudent; // 구조체 변수 선언시 메모리가 생김
//	struct student* sp = &aStudent;
//
//	printf("Enter student name : ");
//	scanf("%s", aStudent.name); // == &aStudent.name[0]
//
//	printf("Enter midterm and final score : ");
//	scanf("%d %d", &aStudent.midterm, &aStudent.final); // .(dot) 연산자는 구조체 변수 멤버 각각에 접근
//
//	printf("이름\t중간\t학기말\t\n");
//	printf("%s\t%d\t%d\n", (*sp).name, (*sp).midterm, (*sp).final);
//
//	struct student s[3];
//	struct student* sp = s; // s == &s[0]
//
//	for (int i = 0; i < 3; i++) {
//		printf("Enter student name : ");
//		scanf("%s", sp->name);
//		printf("Enter midterm and final score : ");
//		scanf("%d %d", &sp->midterm, &sp->final);
//		sp++; // +sizeof(struct student)
//	}
//
//	sp = s; // sp위치 조정
//	printf("\n이름\t중간\t학기말\t\n");
//
//	for (int i = 0; i < 3; i++) {
//		printf("%s\t%d\t%d\n", (*sp).name,(*sp).midterm,(*sp).final);
//		sp++;
//	}
//}

/*LAB10_1*/
//struct customer {
//	char name[40];
//	int age;
//};
//
//int main(void)
//{
//	struct customer* cp;
//	struct customer aCustomer = { "박수희",36 };
//	struct customer cArray[2] = { {"장동건",38},{"고소영",38} };
//
//	cp = &aCustomer;
//	printf("이름 : %s , 나이 : %d\n", cp->name, cp->age);
//
//	cp = cArray; // &cArray[0]
//	for (int i = 0; i < 2; i++) {
//		printf("name = %s, age = %d\n", cp->name,cp->age);
//		cp++;
//	}
//}

/*LAB11_0*/
//int main(void)
//{
//	struct foo_t {
//		char c;
//		int x;
//		char c2;
//		int y;
//      <- data크기 16
//		/*int x;
//		int y;
//		char c;
//		char c2;*/
//     <-data크기 12
//	};
//
//	struct foo_t data;
//	struct foo_t* ptr = &data, * ptr2;
//
//	ptr2 = ptr;
// 
// 
//	printf("data.x 첫 주소값은 %d\n", &data.x);
//
//	printf("ptr이 가르키는 주소값은 %d\n", ptr);
//	printf("ptr2가 가르키는 주소값은 %d\n", ptr2);
//	return;
//}
