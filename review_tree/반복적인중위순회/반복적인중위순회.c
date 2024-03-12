//스택을 명시적으로 사용 , 연결스택!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef TreeNode* element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct StackType {
	StackNode* top;
} LinkedStackType;
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right; //자기 참조 구조체
} TreeNode;

void init(LinkedStackType* s) {
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return s->top == NULL;
}

void push(LinkedStackType* s, TreeNode* root) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));

	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = root;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	element item;

	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		temp = s->top;
		item = temp->data;
		s->top = s->top->link;
		free(temp);
	}

	return item;
}

void inorder_iter(TreeNode* root) {
	LinkedStackType s;
	init(&s);

	while (1) {
		while (root != NULL) {
			push(&s, root);
			root = root->left;
		}

		root = pop(&s);
		if (root == NULL) break;
	
		printf("%d ", root->data);
		root = root->right;
	}
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main(void) {
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");

	return 0;
}