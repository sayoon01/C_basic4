#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_STRING 100

typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
}element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
// 중위순회
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("---------------------------\n");
		printf("학번: %d\n", root->data.id);
		printf("이름: %s\n", root->data.name);
		printf("전화번호: %s\n", root->data.tel);
		printf("학과: %s\n", root->data.dept);
		inorder(root->right);
	}
}

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL; // <- 비어있는 경우

	if (key == node->data.id) return node;
	if (key < node->data.id)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* insert_node(TreeNode* root, element data)
{
	// 트리가 공백이면 새로운 노드를 반환한다
	if (root == NULL) return new_node(data);

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (data.id < root->data.id)
		root->left = insert_node(root->left, data);
	else if (data.id > root->data.id)
		root->right = insert_node(root->right, data);

	// 변경된 루트 포인터를 반환한다
	return root;
}
TreeNode* min_value_node(TreeNode* node)
{
	// 왼쪽으로 쭉 가서 끝까지
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->data.id)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {// 첫 번째나 두 번째 경우 
		// case 1 : 단말노드 `case 2-1 : one leaf node인데 오른쪽 자식 있음
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { // case 2-2 : one leaf node인데 왼쪽 자식 있음
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		// 세 번째 경우 case 3 : two leaves node 자식 노드가 두 개인 노드 
		temp = min_value_node(root->right);
		// 중위 순회시 후계 노드를 복사한다.
		root->data = temp->data;
		// 중위 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->data.id);
	}
	return root;
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
//int get_max(TreeNode* node)
//{
//	int maxN;
//
//	if (node == NULL)
//		return -99999;
//
//	maxN = node->key;
//	if (maxN < get_max(node->left))
//		maxN = get_max(node->left);
//	if (maxN < get_max(node->right))
//		maxN = get_max(node->right);
//
//	return maxN;
//
//}
//int get_min(TreeNode* node)
//{
//	int minN;
//
//	if (node == NULL)
//		return 99999;
//
//	minN = node->key;
//	if (minN > get_min(node->left))
//		minN = get_min(node->left);
//	if (minN > get_min(node->right))
//		minN = get_min(node->right);
//
//	return minN;
//}
int main(void)
{
	TreeNode* root = NULL;
	//TreeNode* temp = NULL;
	element ele;
	char c;
	int id;

	printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount),, q(uit): ");
	scanf("%c", &c);
	while (getchar() != '\n');
	while (c != 'q') {

		if (c == 'i') { // 입력
			printf("학번 입력: ");
			scanf("%d", &ele.id);
			printf("이름 입력: ");
			scanf("%s", &ele.name);
			printf("전화번호 입력: ");
			scanf("%s", &ele.tel);
			printf("학과 입력: ");
			scanf("%s", &ele.dept);
			
			root = insert_node(root, ele);
			while (getchar() != '\n');
		}
		else if (c == 'd') { // 삭제
			printf("삭제할 학번 : ");
			scanf("%d", &id);
			root = delete_node(root, id);
			while (getchar() != '\n');
		}
		else if (c == 's') {
			printf("탐색할 학번 : ");
			scanf("%d", &id);
			TreeNode* temp = search(root, id);
			if (temp != NULL)
			{
				printf("----------------------\n");
				printf("학번: %d\n", temp->data.id);
				printf("이름: %s\n", temp->data.name);
				printf("전화번호: %s\n", temp->data.tel);
				printf("학과: %s\n", temp->data.dept);
			}
			else
				printf("id가 %d인 학생은 없읍니다.\n",id);
			while (getchar() != '\n');
		}
		else if (c == 'p') {
			inorder(root);
			printf("\n");
		}
		else if (c == 'c') {
			printf("현재 저장된 학생의 총 수는 %d\n", get_node_count(root));
		}
		
		printf("Enter i(nsert), d(elete), s(earch), p(rint),c(count), q(uit): ");
		scanf("%c", &c);
		while (getchar() != '\n');
	}
}