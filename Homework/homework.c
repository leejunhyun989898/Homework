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


// �θ� ��带 ã�� �Լ�
TreeNode* parent(TreeNode* root, TreeNode* child) {
    if (root == NULL || root == child)
        return NULL;  // ��Ʈ�� NULL�̰ų� ã�� ��尡 ��Ʈ�� ��� �θ� ����

    // ���� �ڽ� ��尡 ��Ʈ�� ���� ��� �Ǵ� ������ ����� ���
    if ((root->left == child) || (root->right == child))
        return root;  // �θ� ��带 ã����

    // ���� ����Ʈ������ ã��
    TreeNode* left_parent = parent(root->left, child);
    if (left_parent != NULL)
        return left_parent;

    // ������ ����Ʈ������ ã��
    return parent(root->right, child);
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


    // �θ� ��� ã�� �� ��� ����
    TreeNode* child1 = &s1;
    TreeNode* parent1 = parent(exp, child1);
    printf("��� 4�� �θ�: %d\n", parent1->data);
    
    TreeNode* child2 = &s2;
    TreeNode* parent2 = parent(exp, child2);
    printf("��� 5�� �θ�: %d\n", parent2->data);

    TreeNode* child3 = &s4;
    TreeNode* parent3 = parent(exp, child3);
    printf("��� 6�� �θ�: %d\n", parent3->data);

    return 0;
}