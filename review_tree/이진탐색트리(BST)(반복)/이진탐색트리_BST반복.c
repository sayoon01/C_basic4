#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// 새로운 트리노드를 생성해서 반환
TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->key = item;
	temp->left = temp->right = NULL;

	return temp;
}

// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

// 탐색(반복)
TreeNode* search(TreeNode* node, int key) {
	while (node != NULL) {
		if (key == node->key)
			return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	return NULL;
}

// 탐색(삽입)
TreeNode* insert_node(TreeNode* root, int key) {
	TreeNode* p, * t, * n; // p는 부모노드, t는 현재노드, n는 새로운노드

	t = root;
	p = NULL;

	// 탐색을 먼저 수행
	while (t != NULL) {
		if (key == t->key)
			return root;

		p = t; // 현재 노드를 부모 노드로 하고

		// 현재 노드를 전진
		if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}

	n = new_node(key);

	// 부모 노드와 링크 연결
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	else // 애초에 트리가 비어있음
		root = n;

	return root;
}

// 삭제 함수 
TreeNode* delete_node(TreeNode* root, int key) {
	TreeNode* p, * child, * succ, * succ_p, * t;
	// key를 갖는 노드 t를 탐색, p는 t의 부모노드

	p = NULL;
	t = root;

	// key를 갖는 노드 t를 탐색한다.
	while (t != NULL && t->key != key) {
		p = t; // 자식노드를 부모가
		t = (key < t->key) ? t->left : t->right; // 자식노드 전진
	}

	// 탐색이 종료된 시점에 t가 NULL이면 트리안에 key가 없음
	if (t == NULL) { // 탐색트리에 없는 키
		printf("key is not in the tree");
		return root;
	}

	// 첫번째 경우: 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			// 부모노드의 자식필드를 NULL로 만든다.
			if (p->left == t) // 삭제하려는 것이 왼쪽 노드이면
				p->left = NULL;
			else
				p->right = NULL;
		}
		else//p가 NULL이면(즉 단 하나의 단말 노드이고 이걸 삭제하려면) 루트 삭제
			root = NULL;
	}

	// 두번째 경우: 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t) // 부모를 자식과 연결 
				p->left = child;
			else p->right = child;
		}
		else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
			root = child;
	}

	// 세번째 경우: 두개의 자식을 가지는 경우
	else {
		// 오른쪽 서브트리에서 후계자를 찾는다.
		succ_p = t;
		succ = t->right;
		// 후계자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		// 후속자가 가진 키값을 현재 노드에 복사
		t->key = succ->key;
		// 원래의 후속자 삭제
		t = succ;
	}
	free(t);
	return root;
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");

	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");

	root = delete_node(root, 40);
	inorder(root);

	return 0;
}