//20200990 컴퓨터학과 윤상아
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 

//사용자가 입력한 문자열의 역문자열을 만드는 프로그램(반복)
// (조건 : 입력 문자열 str[]외 다른 배열 사용 X
void reverse_string(char* str, int s, int e)
{
	char tmp;

	for (int i = 0; i < (e + 1) / 2; i++)
	{
		tmp = str[s + i];
		str[s + i] = str[e - i];
		str[e - i] = tmp;
	}
}
int main()
{
	char str[100];

	printf("Enter any string:");
	scanf("%s", str);
	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);

	return 0;
}