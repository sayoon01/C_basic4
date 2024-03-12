#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.
TreeNode* insert_node(TreeNode* root, int key)  // 변경하지 말라. 아직 수업시간에서 다루지 않은 부분이다.
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
// 전위 순회
void preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->key); 	// 노드 방문
		preorder(root->left);	// 왼쪽서브트리 순회
		preorder(root->right);	// 오른쪽서브트리 순회
	}
}
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// 왼쪽서브트리 순회
		printf("%d ", root->key); 	// 노드 방문
		inorder(root->right);	// 오른쪽서브트리 순회
	}
}
void printCheck(TreeNode* node)
{
	preorder(node); printf("\n");
	inorder(node); printf("\n");
}

TreeNode* copy_addChild(TreeNode* root)
{
	// 코드 추가

	TreeNode* clone = (TreeNode*)malloc(sizeof(TreeNode));

	if (root == NULL)
		return NULL;
	else {
		clone->key = root->key;
		clone->left = copy_addChild(root->left);
		clone->right = copy_addChild(root->right);
	}

	return clone;
}

int main(void) // main은 변경하지 말라. 
{
	int key;

	TreeNode* root, * root2;

	// 아래의 6줄은 트리를 만드는 부분으로 수업시간에 다루지 않았으므로 신경쓰지 않아도 된다.
	root = NULL;
	scanf("%d", &key);
	while (key != -1) {
		root = insert_node(root, key);
		scanf("%d", &key);
	}

	root2 = copy_addChild(root);
	printCheck(root2);
}