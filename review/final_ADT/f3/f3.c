#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;
// key를 이진 탐색 트리 root에 삽입한다. 

TreeNode* insert_node(TreeNode* root, element key) // 변경하지 말라
{
	TreeNode* p, * t; // p는 부모노드, t는 현재노드 
	TreeNode* n;	    // n은 새로운 노드

	t = root;
	p = NULL;

	// 탐색을 먼저 수행, 반복을 이용해서 search(위의 search함수 참조)
	while (t != NULL) { // 현재노드가 NULL이 될때까지
		//if( key == t->key ) return root; // (A)-1: 같은 key가 있는 경우 함수를 끝내는 부분을 주석처리함
		p = t; // 현재노드를 부모노드로 하고
		// 현재노드를 전진
		if (key <= t->data) // (A)-2: 값이 작거나 같은 경우 왼쪽으로 이동
			t = t->left;
		else
			t = t->right;
	}

	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL) exit(1);
	// 데이터 복사
	n->data = key;
	n->left = n->right = NULL;

	// 부모 노드와 링크 연결
	if (p != NULL)
		if (key <= p->data)
			p->left = n;
		else
			p->right = n;
	else // 애초에 트리가 비어있었으면
		root = n;

	return root;
}

void inorder(TreeNode* root)  // 변경하지 말라
{
	if (root) {
		inorder(root->left);	// 왼쪽서브트리 순회
		printf("%d ", root->data); 	// 노드 방문
		inorder(root->right);	// 오른쪽서브트리 순회
	}
}

void preorder(TreeNode* root)  // 변경하지 말라
{
	if (root) {
		printf("%d ", root->data); 	// 노드 방문
		preorder(root->left);	// 왼쪽서브트리 순회
		preorder(root->right);	// 오른쪽서브트리 순회
	}
}
void printCheck(TreeNode* node) // 변경하지 말라
{
	preorder(node); printf("\n");
	inorder(node); printf("\n");
}

void replaceKeyValue(TreeNode* root, int oldKey, int newKey)
{
	//문제 트리-2의 코드를 여기 넣는다
	if (root != NULL) {
		if (root->data == oldKey) {
			root->data = newKey;
		}

		if (root->left != NULL)
			replaceKeyValue(root->left, oldKey, newKey);

		if (root->right != NULL)
			replaceKeyValue(root->right, oldKey, newKey);
	}
}

int calcMax(int a, int b) // 변경하지 말라, 필요하면 사용
{
	if (a <= b)
		return b;
	else
		return a;
}
int get_max(TreeNode* node) // 변경하지 말라, 필요하면 사용
{
	if (node)
		return calcMax(calcMax(node->data, get_max(node->left)), get_max(node->right));
	else
		return INT_MIN;
}

int calcMin(int a, int b)// 변경하지 말라, 필요하면 사용
{
	if (a <= b)
		return a;
	else
		return b;
}
int get_min(TreeNode* node) // 변경하지 말라, 필요하면 사용
{
	if (node)
		return calcMin(calcMin(node->data, get_min(node->left)), get_min(node->right));
	else
		return INT_MAX; //가장 큰수를 나타내는 상수
}

int isBST(TreeNode* node) // 코드 작성
{
	if (node != NULL) {
		if (node->left != NULL) {
			if (node->left->data > node->data)
				return 0;

			return isBST(node->left);
		}

		if (node->right != NULL) {
			if (node->right->data <= node->data)
				return 0;

			return isBST(node->right);
		}

		return 1;
	}
}

int main(void) // 변경하지 마라
{
	int n;
	int oldKey, newKey;
	int key;

	TreeNode* root = NULL;

	scanf("%d", &n);
	while (n != -1) {
		root = insert_node(root, n);
		scanf("%d", &n);
	}

	for (int i = 0; i < 3; i++) {
		scanf("%d", &oldKey);
		scanf("%d", &newKey);
		replaceKeyValue(root, oldKey, newKey);
		printf("%d\n", isBST(root));
	}
}