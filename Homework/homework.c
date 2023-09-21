#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    int is_thread;
} TreeNode;



TreeNode s1 = { 4, NULL,NULL,1 };
TreeNode s2 = { 5, NULL,NULL,1 };
TreeNode s3 = { 3, &s1,&s2,0 };
TreeNode s4 = { 6, NULL,NULL,1 };
TreeNode s5 = { 2, &s3,&s4,0 };
TreeNode s6 = { 10, NULL,NULL,1 };
TreeNode s7 = { 11, NULL,NULL,0 };
TreeNode s8 = { 8, NULL,NULL,1 };
TreeNode s9 = { 9, &s6,&s7,0 };
TreeNode s10 = { 7, &s8,&s9,0 };
TreeNode s11 = { 1, &s5,&s10,0 };
TreeNode* exp = &s11;



TreeNode* find_successor(TreeNode* p)
{
    TreeNode* q = p->right; //q=p의 오른쪽 포인터

    // 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터 반환
    if (q == NULL || p->is_thread == TRUE)
        return q;

    //만약 오른쪽 자식이면 다시 가장 왼쪽 노드 이동
    while (q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(TreeNode* t)
{
    TreeNode* q;
    q = t;
    while (q->left)q = q->left;//가장 왼쪽 노드로 감
    do {
        printf("%d ", q->data); //데이터 출력
        q = find_successor(q); //후속자 함수 호출
    } while (q);
}


// 부모 노드를 찾는 함수
TreeNode* parent(TreeNode* root, TreeNode* child) {
    if (root == NULL || root == child)
        return NULL;  // 루트가 NULL이거나 찾을 노드가 루트인 경우 부모 없음

    // 만약 자식 노드가 루트의 왼쪽 노드 또는 오른쪽 노드인 경우
    if ((root->left == child) || (root->right == child))
        return root;  // 부모 노드를 찾았음

    // 왼쪽 서브트리에서 찾기
    TreeNode* left_parent = parent(root->left, child);
    if (left_parent != NULL)
        return left_parent;

    // 오른쪽 서브트리에서 찾기
    return parent(root->right, child);
}


int main(void)
{
    //스레드 설정
    s1.right = &s3;
    s2.right = &s5;
    s4.right = &s11;
    s6.right = &s9;
    s8.right = &s10;

    printf("1. 중위 순회 결과\n");
    thread_inorder(exp);
    printf("\n\n");


    // 부모 노드 찾기 및 출력 예시
    TreeNode* child1 = &s1;
    TreeNode* parent1 = parent(exp, child1);
    printf("노드 4의 부모: %d\n", parent1->data);
    
    TreeNode* child2 = &s2;
    TreeNode* parent2 = parent(exp, child2);
    printf("노드 5의 부모: %d\n", parent2->data);

    TreeNode* child3 = &s4;
    TreeNode* parent3 = parent(exp, child3);
    printf("노드 6의 부모: %d\n", parent3->data);

    return 0;
}