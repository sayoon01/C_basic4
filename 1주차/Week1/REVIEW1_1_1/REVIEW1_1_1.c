//20200990 컴퓨터학과 윤상아
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 

//사용자가 입력한 문자열의 역문자열을 만드는 프로그램(순환)
// (조건 : 입력 문자열 str[]외 다른 배열 사용 X
void reverse_string(char* str, int s, int e)
{
	char tmp;

	if (s >= e) return;
	else
	{
		tmp = str[s];
		str[s] = str[e];
		str[e] = tmp;

		reverse_string(str, s + 1, e - 1);
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