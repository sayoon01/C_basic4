//20200990 컴퓨터학과 윤상아
// 재귀 , for문 없애기 <- 재제출 check
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_fact_exp(int n)
{	
	//1차 제출
	/*for (int i = n; i >= 2; i--) {
		printf("%d * ", i);
	}
	printf("1\n");*/

	//2차 제출
	if (n == 0 || n == 1) {
		printf("%d", 1);
	}
	else {
		printf("%d * ", n);
		print_fact_exp(n - 1);
	}
}

/*if(*/
int main(void)
{
	int n;

	printf("Enter a number : ");
	scanf("%d", &n);

	printf("%d! = ", n);
	print_fact_exp(n);
	printf("\n");
}