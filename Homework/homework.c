#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    int is_thread;
} TreeNode;



TreeNode s1 = { 4, NULL,NULL,1};
TreeNode s2 = { 5, NULL,NULL,1};
TreeNode s3 = { 3, &s1,&s2,0};
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



    return 0;
}