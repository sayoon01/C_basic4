//!
//20200990 컴퓨터학과 윤상아
// 재귀 , for문 없애기 !! <- 재제출
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fact(int num)
{
	//1차 제출
	/*int factorial = 1;

	for (int i = 2; i <= num; i++) {
		factorial *= i;
	}

	return factorial;*/

	//2차 제출

	if (num == 0)
		return 1;
	else
		return num * fact(num - 1);
	
}

int main(void)
{
	int n;
	printf("Enter a number : ");
	scanf("%d", &n);

	printf("%d! = ", n);
	printf("%d\n", fact(n));
}