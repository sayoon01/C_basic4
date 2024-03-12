#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MIN, INT_MAX사용위해
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
//   root
//    15
//   4 15
// 15 16 25
//
//  root2
//    15
//  4   15
//15   16 25
//       28
TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;
TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // 추가
TreeNode m4 = { 25, NULL, &m7 }; // 변경
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

//이진 트리에서 비단말노드의 개수를 계산하는 함수
int get_nonleaf_count(TreeNode* node) {
	if (node == NULL) // 노드가 없다면 leaf도 없다
		return 0;
	else if (node->right == NULL && node->left == NULL) // 단말노드인 경우
		return 0;
	else // 비단말노드인 경우
		return 1 + get_nonleaf_count(node->left) + get_nonleaf_count(node->right);
}

//이진 트리에서 자식이 하나인 노드의 개수를 반환
int get_oneleaf_count(TreeNode* node) 
{
	if (node == NULL)
		return 0;
	else if (node->left == NULL && node->right == NULL) // 단말인 경우
		return 0;
	else if (node->left == NULL && node->right != NULL) // 오른쪽 자식만 사실은 node->right!=NULL필요 없음
		return 1 + get_oneleaf_count(node->right);
	else if (node->right == NULL && node->left != NULL)// 오른쪽 자식만
		return 1 + get_oneleaf_count(node->left);
	else
		return get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
}
//이진 트리에서 자식이 둘인 노드의 개수를 반환
int get_twoleaf_count(TreeNode* node) 
{
	if (node == NULL)
		return 0;
	else if (node->left == NULL && node->right == NULL) // 단말인 경우
		return 0;
	else if (node->left == NULL && node->right != NULL) // 오른쪽 자식만 사실은 node->right!=NULL필요 없음
		return get_twoleaf_count(node->right);
	else if (node->right == NULL && node->left != NULL)// 오른쪽 자식만
		return get_twoleaf_count(node->left);
	else
		return get_twoleaf_count(node->left) + get_twoleaf_count(node->right) + 1;
}
//두 개의 이진 트리가 같은 구조를 가지고 있고 대응되는 노드들이 같은 데이터를 가지고 있는지 검사하여 참이면 1 거짓이면 0
int equal(TreeNode* t1, TreeNode* t2) 
{
	//if (t1 == NULL && t2 == NULL) // 두 트리가 모두 NULL
	//	return TRUE;
	//if ((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) // 하나만 null
	//	return FALSE; 
	//if ((t1->data == t2->data) && equal(t1->left, t2->left) && equal(t1->right, t2->right))
	//	return TRUE;

	//return FALSE;
	if (t1 == NULL && t2 == NULL)
		return TRUE;
	else if (t1 == NULL)//&&t2!=NULL  ..(1)
		return FALSE;
	else if (t2 == NULL)//&&t1!=NULL ..(2)
		return FALSE; // (1),(2) if(t1==NULL||t2==NULL)
	else
	{
		if (t1->data != t2->data)
			return FALSE;
		else
			return equal(t1->left, t2->left) && equal(t1->right, t2->right);
	}
}
//이진 트리에서 노드값들 중 최대값을 반환
int get_max(TreeNode* node) {
	int left_max, right_max, max = 0;

	if (node != NULL) {
		max = node->data;

		left_max = get_max(node->left);
		right_max = get_max(node->right);
		if (left_max > max)
			max = left_max;
		if (right_max > max)
			max = right_max;
	}

	return max;
	// 완성 못시킴 위에 보삼
	//if (node) // if(node!=NULL)
	//	return max(node->data, max(get_max(node->left)), get_max(node->right));
	//else
	//	return INT_MIN; 
}
//이진 트리에서 노드값들 중 최소값을 반환
int get_min(TreeNode* node) {
	int left_min, right_min, min = INT_MAX;

	if (node != NULL) {
		min = node->data;

		left_min = get_min(node->left);
		right_min = get_min(node->right);
		if (left_min < min)
			min = left_min;
		if (right_min < min)
			min = right_min;
	}

	return min;

	//위에 봐라
	//if (node) // if(node!=NULL)
	//	return min(min(min(node->data, get_min(node->left))), get_min(node->right));
	//else
	//	return INT_MAX;
}
//이진 트리에서 노드들의 값을 1씩 증가
void node_increase(TreeNode* node) 
{
	if (node == NULL)
		return;
	else {
		node->data++;
		node_increase(node->left);
		node_increase(node->right); //세개 순서상관 없음 
	}
}
void preorder(TreeNode* root) // p271 코드 복사
{
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
// 주어진 이진 트리를 복제한 새로운 트리를 반환
TreeNode* copy(TreeNode* node) 
{
	TreeNode* clone = (TreeNode*)malloc(sizeof(TreeNode));

	if (node == NULL)
		return NULL;
	else {
		clone->data = node->data;
		clone->left = copy(node->left);
		clone->right = copy(node->right);
	}

	return clone;
}
int main(void)
{
	//TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	//int i, num;
	printf("가)\n");
	printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));
	printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
	printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
	printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
	printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));
	printf("\n 나)\n");
	/*num = search(root, 15, result);
	for (i = 0; i < num; i++)
		printf("(0x%p, %d), ", result[i], result[i]->data);*/
	printf("\n");
	printf("\n 다)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");
	printf("\n 라)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}