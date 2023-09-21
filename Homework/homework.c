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
    TreeNode* q = p->right; //q=p�� ������ ������

    // ���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ ������ ��ȯ
    if (q == NULL || p->is_thread == TRUE)
        return q;

    //���� ������ �ڽ��̸� �ٽ� ���� ���� ��� �̵�
    while (q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(TreeNode* t)
{
    TreeNode* q;
    q = t;
    while (q->left)q = q->left;//���� ���� ���� ��
    do {
        printf("%d ", q->data); //������ ���
        q = find_successor(q); //�ļ��� �Լ� ȣ��
    } while (q);
}




int main(void)
{
    //������ ����
    s1.right = &s3;
    s2.right = &s5;
    s4.right = &s11;
    s6.right = &s9;
    s8.right = &s10;
    
    printf("1. ���� ��ȸ ���\n");
    thread_inorder(exp);
    printf("\n\n");



    return 0;
}