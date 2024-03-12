#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

typedef TreeNode* element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s)// 변경하지 말라.
{
    s->top = NULL;
}

int is_empty(LinkedStackType* s)// 변경하지 말라.
{
    return (s->top == NULL);
}

// 포화 상태 검출 함수
int is_full(LinkedStackType* s)// 변경하지 말라.
{
    return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item)// 변경하지 말라.
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}
// 삭제 함수
element pop(LinkedStackType* s) // 변경하지 말라.
{
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        element data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

TreeNode* insert_node(TreeNode* root, int data)  // 변경하지 말라. 
// 아직 배우지 않았으나 어떤 규칙으로 트리에 노드를 삽입한다.
{
    TreeNode* p, * t; // p는 부모노드, t는 현재노드 
    TreeNode* n;        // n은 새로운 노드

    t = root;
    p = NULL;

    // 탐색을 먼저 수행, 반복을 이용해서 search(위의 search함수 참조)
    while (t != NULL) { // 현재노드가 NULL이 될때까지
        if (data == t->data) return root;
        p = t; // 현재노드를 부모노드로 하고
        // 현재노드를 전진
        if (data < t->data)
            t = t->left;
        else
            t = t->right;
    }
    // data가 트리 안에 없으므로 삽입 가능
    n = (TreeNode*)malloc(sizeof(TreeNode));
    // 데이터 복사
    n->data = data;
    n->left = n->right = NULL;

    // 부모 노드와 링크 연결
    if (p != NULL)
        if (data < p->data)
            p->left = n;
        else
            p->right = n;
    else // 애초에 트리가 비어있었으면
        root = n;
    return root;
}

void preorder_iter(LinkedStackType* s, TreeNode* root)
{
    // 코드 작성
    while (1) {
        while (root != NULL) {
            printf("%d ", root->data);
            push(s, root);
            root = root->left;
        }

        if (is_empty(s))
            break;

        root = pop(s);
        root = root->right;
    }
}

int main(void)// 변경하지 말라.
{
    LinkedStackType s;
    TreeNode* root;
    int n;

    // 아래의 6줄은 트리를 만드는 부분으로 수업시간에 다루지 않았으므로 신경쓰지 않아도 된다.
    root = NULL;
    scanf("%d", &n);
    while (n != -1) {
        root = insert_node(root, n);
        scanf("%d", &n);
    }

    init(&s);
    //printf("전위 순회=");
    preorder_iter(&s, root);
    printf("\n");
    return 0;
}