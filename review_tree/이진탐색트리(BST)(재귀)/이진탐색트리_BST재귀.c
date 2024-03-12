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

// 탐색(recursive version)
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL)
		return NULL;

	if (key == node->key)
		return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

// 삽입(recursive version)
TreeNode* insert_node(TreeNode* root, int key) {
	// 트리가 공백이면 새로운 노드를 반환
	if (root == NULL)
		return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (key < root->key)
		root->left = insert_node(root->left, key);
	else if (key > root->key)
		root->right = insert_node(root->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return root;
}

// 이진탐색트리에서 가장 작은 수는 왼쪽으로 끝까지 가면 됨
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

// 삭제(recursive version)
TreeNode* delete_node(TreeNode* root, int key) {
	TreeNode* temp;

	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);

	// key == root->key
	else {
		// 경우1(단말 노드), 경우2(one_leaf)
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		// 경우3(two_left)
		temp = min_value_node(root->right);
		root->key = temp->key; // 후계 노드 복사
		root->right = delete_node(root->right, temp->key); // 후계 노드 삭제
	}

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