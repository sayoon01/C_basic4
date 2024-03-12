/*미로 탐색 프로그램*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

typedef struct {
	int r;
	int c;
} element;
typedef struct
{	
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

element here = { 1,0 }, entry = { 1,0 };
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},

};
void init(StackType* sp)
{
	sp->top = -1;
}
int is_empty(StackType* sp)
{
	return sp->top == -1;
}
int is_full(StackType* sp)
{
	return sp->top == MAX_STACK_SIZE - 1;
}
void push(StackType* sp, element item)
{
	if (is_full(sp)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		sp->data[++(sp->top)] = item;
}
element pop(StackType* sp)
{
	if (is_empty(sp)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return sp->data[(sp->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];

}
void push_loc(StackType* sp, int r, int c)
{
	if (r < 0 || c < 0) return;

	if (maze[r][c] != '1' && maze[r][c] != '.') { // '1' 막혀있는 길 '.' 갔던 길
		element tmp;

		tmp.r = r;
		tmp.c = c;
		push(sp, tmp);
	}
}
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c ", maze[r][c]);
		}
		printf("\n");
	}
}



int main(void)
{
	int r, c;
	StackType s;

	init(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;

		maze[r][c] = '.';
		maze_print(maze);

		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공");
	return 0;
}