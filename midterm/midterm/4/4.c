#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* insert_node(TreeNode* root, int key)  // 변경하지 말라. 아직 배우지 않았으나 어떤 규칙으로 트리에 노드를 삽입한다.
{
	TreeNode* p, * t; // p는 부모노드, t는 현재노드 
	TreeNode* n;	    // n은 새로운 노드

	t = root;
	p = NULL;

	// 탐색을 먼저 수행, 반복을 이용해서 search(위의 search함수 참조)
	while (t != NULL) { // 현재노드가 NULL이 될때까지
		//if( key == t->key ) return;
		p = t; // 현재노드를 부모노드로 하고
		// 현재노드를 전진
		if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}
	// key가 트리 안에 없으므로 삽입 가능
	n = (TreeNode*)malloc(sizeof(TreeNode));
	//if (n == NULL) return;
	// 데이터 복사
	n->key = key;
	n->left = n->right = NULL;

	// 부모 노드와 링크 연결
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	else // 애초에 트리가 비어있었으면
		root = n;
	return root;
}
// 짝수 노드의 개수 출력
int count_even(TreeNode* node) // 이 함수를 작성해서 제출
{
	int count = 0;

	// 빈칸(들)에 코드를 넣어라
	// 하나의 빈칸에 여러개의 문장을 넣을 수도 있고
	// 일부 빈칸(들)은 비워둬도 된다.
	if (node == NULL)
		return count;
	else if (node->key % 2 == 0) {
		count++;
		count_even(node->right); count_even(node->left);
	}
	else {
		count_even(node->right); count_even(node->left);
	}

	return count;
}

int main(void) // main은 변경하지 말라. 
{
	int n;

	TreeNode* root;

	// 아래의 6줄은 트리를 만드는 부분으로 수업시간에 다루지 않았으므로 신경쓰지 않아도 된다.
	root = NULL;
	scanf("%d", &n);
	while (n != -1) {
		root = insert_node(root, n);
		scanf("%d", &n);
	}

	printf("%d\n", count_even(root));
}
