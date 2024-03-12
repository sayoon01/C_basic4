#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)
		return NULL;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL)
		return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
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
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;

		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void print_node(TreeNode* root)
{
	if (root) {
		printf("%d ", root->key);
		print_node(root->left);
		print_node(root->right);
	}
}

int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL) {
		if (get_height(node->left) > get_height(node->right))
			height = 1 + get_height(node->left);
		else
			height = 1 + get_height(node->right);
	}
	return height;
}

int get_node_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}
int get_max(TreeNode* node)
{
	int maxN;

	if (node == NULL)
		return -99999;

	maxN = node->key;

	if (maxN < get_max(node->left))
		maxN = get_max(node->left);
	if (maxN < get_max(node->right))
		maxN = get_max(node->right);

	return maxN;
}

int get_min(TreeNode* node)
{
	int minN;

	if (node == NULL)
		return 99999;

	minN = node->key;

	if (minN > get_min(node->left))
		minN = get_min(node->left);
	if (minN > get_min(node->right))
		minN = get_min(node->right);

	return minN;
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* temp = NULL;
	char c;
	int num;

	printf("Enter i(nsert), d(elete), s(earch), p(rint), h(eight), c(ount), m(ax), n(min), q(uit): ");
	scanf("%c", &c);
	while (getchar() != '\n');
	while (c != 'q') {
		if (c == 'i') {
			printf("삽입할 key값 입력: ");
			scanf("%d", &num);
			root = insert_node(root, num);
			while (getchar() != '\n');
		}
		else if (c == 'd') {
			printf("삭제할 key값 입력: ");
			scanf("%d", &num);
			root = delete_node(root, num);
			while (getchar() != '\n');
		}
		else if (c == 's') {
			printf("탐색할 key값 입력: ");
			scanf("%d", &num);
			temp = search(root, num);
			if (temp != NULL)
				printf("있음\n");
			else
				printf("없음\n");
			while (getchar() != '\n');
		}
		else if (c == 'p') {
			print_node(root);
			printf("\n");
		}
		else if (c == 'h') {
			printf("트리의 높이는 %d\n", get_height(root));
		}
		else if (c == 'c') {
			printf("노드의 개수는 %d\n", get_node_count(root));
		}
		else if (c == 'm') {
			printf("가장 큰 값은 %d\n", get_max(root));
		}
		else if (c == 'n') {
			printf("가장 작은 값은 %d\n", get_min(root));
		}
		printf("Enter i(nsert), d(elete), s(earch), p(rint), h(eight), c(ount), m(ax), n(min), q(uit): ");
		scanf("%c", &c);
		while (getchar() != '\n');
	}

}