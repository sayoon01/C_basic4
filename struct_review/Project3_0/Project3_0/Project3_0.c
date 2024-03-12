#define _CRT_SECURE_NO_WARNINGS

#define MAX_VIDEO 100
#define MAX_CHAR 100

#include <stdio.h>
#include <string.h>

struct VideoInfo {
	char title[MAX_CHAR];
	int qty; // 수량
};

int main(void)
{
	int videoCount = 5;
	struct VideoInfo videoList[MAX_VIDEO] = { {"BeforeSunrise",1},{"BeforeSunset",3},{"BeforeMidnight",5},{"Casablanca",7},{"EdgeOfTomorrow",9} };
	char title[MAX_CHAR];
	int qty;
	int choice;
	//int flag = 0;
	//for (int i = 0; i < videoCount; i++) {
	//	scanf("%s", videoList[i].title);
	//	//while (getchar() != '\n');
	//	scanf("%d", &videoList[i].qty);
	//}

	
	printf("1(ALL Video 출력), 2(구입), 3(검색), 4(종료): ");
	scanf("%d", &choice);

	while (choice != 4){
		switch (choice) {
		case 1:
			printf("Video제목\t수량\n");
			printf("----------------------\n");
			for (int i = 0; i < videoCount; i++) {
				printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
			}
			break;
		case 2:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter video 수량: ");
			scanf("%d", &qty);

			strcpy(videoList[videoCount].title, title);
			videoList[videoCount].qty = qty;
			videoCount++;
			break;
		case 3:
			printf("Enter video 제목: ");
			scanf("%s", title);

			int i;
			int found = -1;
			for (i = 0; i < videoCount; i++) {
				if (strcmp(title,videoList[i].title==0)) {
					found = 1;
				}
			}

			if (found)
			{
				if (videoList[i].qty >= 1)
				{
					printf("대여 가능합니다.\n");
					videoList[i].qty--;
				}
				else
					printf("대여 가능하지 않습니다.\n");
			}
			else
				printf("그런 비디오는 없습니다.\n");
			//break;
		}
		printf("1(ALL Video 출력), 2(구입), 3(검색), 4(종료): ");
		scanf("%d", &choice);
	}
}