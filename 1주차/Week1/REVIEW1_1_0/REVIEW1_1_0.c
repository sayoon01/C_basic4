//20200990 컴퓨터학과 윤상아
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 

// 사용자가 입력한 문자열을 역순으로 출력하는 프로그램 (순환)
void print_reverse(char* str, int end) // <- 배열을 함수의 매개 포인터로 받을 수 있음 !! str (= &str[0])와 같기 때문이다 )
{
	printf("%c", str[end]);
	if (end == 0)
		return;
	else
		print_reverse(str, end - 1);
}

int main() 
{
	char str[100];
	printf("Enter any string:");
	scanf("%s", str);

	printf("Reversed String is: ");
	print_reverse(str, strlen(str) - 1);
	return 0;
}