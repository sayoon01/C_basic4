#define _CRT_SECURE_NO_WARNINGS

/* 단어 속 숫자의 합 찾기 */
//#include <stdio.h>
//
//
//int main(void)
//{
//	int sum = 0;
//	int flag = 0;
//	int num = 0;
//	char word[81];
//
//	printf("Enter a word : ");
//	scanf("%s", word);
//
//	for (int i = 0; word[i] != '\0'; i++) {
//
//		if (word[i] >= '0' && word[i] <= '9') {
//			if (flag)
//				num = num * 10 + word[i] - '0';
//			else
//				num = word[i] - '0';
//			flag = 1;
//		}
//		else {
//			if (flag)
//			{
//				sum += num;
//				flag = 0;
//				num = 0;
//			}
//		}
//	}
//
//	if (flag)
//		sum += num;
//
//	printf("글자 안의 수의 합은 %d",sum);
//}

/* 단어 속 단어 여부 */
/* 느슨한 패스워드 채킹 */
/* 2018 프논 학기말 고사 스트링 접합 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)