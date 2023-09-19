#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
    if (top < SIZE - 1)
        stack[++top] = p;
}

TreeNode* pop()
{
    TreeNode* p = NULL;
    if (top >= 0)
        p = stack[top--];
    return p;
}

int get_node_count_iter(TreeNode* root)
{
    int count = 0;
    if (root == NULL)
        return count;

    TreeNode* stack[100]; // ������ ����Ͽ� ��带 ����
    int top = -1;

    stack[++top] = root; // ��Ʈ ��带 ���ÿ� �߰�

    while (top >= 0) {
        TreeNode* current = stack[top--]; // ���ÿ��� ��带 ������
        count++; // ��� ī��Ʈ ����

        // ������ �ڽ��� ���� ���ÿ� �߰�
        if (current->right)
            stack[++top] = current->right;

        // ���� �ڽ��� ���ÿ� �߰�
        if (current->left)
            stack[++top] = current->left;
    }

    return count;
}




TreeNode s1 = { 4.0, NULL,NULL };
TreeNode s2 = { 5.0, NULL,NULL };
TreeNode s3 = { '*',&s1,&s2 };
TreeNode s4 = { 3.0, NULL,NULL };
TreeNode s5 = { '+', &s4,&s3 };
TreeNode s6 = { 2.0, NULL,NULL };
TreeNode s7 = { '+', &s6,&s5 };
TreeNode s8 = { 6.0, NULL,NULL };
TreeNode s9 = { 7.0, NULL,NULL };
TreeNode s10 = { '/', &s8,&s9 };
TreeNode s11 = { '-', &s7,&s10 };
TreeNode s12 = { 9.0, NULL,NULL };
TreeNode s13 = { '+', &s11,&s12 };
TreeNode* exp = &s13;

float evaluate(TreeNode* root)
{
    // ��尡 NULL�� ���, 0�� ��ȯ�մϴ�.
    if (root == NULL)
        return 0;

    // root->left �� root->right�� NULL�� ���, �ش� ����� ������ ���� ��ȯ
    if (root->left == NULL && root->right == NULL)
        return root->data;
    else {
        // ���� ����Ʈ���� ����Ͽ� op1�� ����.
        float op1 = evaluate(root->left);

        // ������ ����Ʈ���� ����Ͽ� op2�� ����
        float op2 = evaluate(root->right);


        printf("%0.2f %c %0.2f = ", op1, root->data, op2);

        switch (root->data) {
        case '+':
            // ���� ������ ���� �� ����� ���
            printf("%0.2f\n", op1 + op2);
            return op1 + op2;
        case '-':
            // ���� ������ ���� �� ����� ���
            printf("%0.2f\n", op1 - op2);
            return op1 - op2;
        case '*':
            // ���� ������ ���� �� ����� ���
            printf("%0.2f\n", op1 * op2);
            return op1 * op2;
        case '/':
            // ������ ������ ���� �� ����� ���
            printf("%0.2f\n", op1 / op2);
            return op1 / op2;
        }

    }

    return 0;
}
int main(void)
{

    printf("������ ���� %0.2f�Դϴ�.\n", evaluate(exp));

    int nodeCount = get_node_count_iter(exp); // �ݺ��� ������� ����� ���� ���
    printf("\n�� ����� ������ %d �Դϴ�.\n", nodeCount);
    return 0;
}