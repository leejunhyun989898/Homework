#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;
} TreeNode;

int cnt = 0;

TreeNode* new_node(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
    if (node == NULL) return new_node(key);
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    cnt++;
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
    else
    {
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
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

TreeNode* search(TreeNode* root, int key) {
    TreeNode* node = root;
    while (node != NULL) {
        cnt++;
        if (key == node->key)
        {
            return node;
        }
        else if (key < node->key)
        {
            node = node->left;
        }
        else {
            node = node->right;
        }

    }
    return NULL;
}


void inorder(TreeNode* root)
{
    if (root) {
        cnt++;
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

TreeNode s1 = { 25, NULL, NULL };
TreeNode s2 = { 16, NULL, &s1 };
TreeNode s3 = { 42, NULL, NULL };
TreeNode s4 = { 46, &s3, NULL };
TreeNode s5 = { 55, NULL, NULL };
TreeNode s6 = { 53, &s4, &s5 };
TreeNode s7 = { 41, &s2, &s6 };
TreeNode s8 = { 62, NULL, NULL };
TreeNode s9 = { 64, NULL, NULL };
TreeNode s10 = { 63, &s8, &s9 };
TreeNode s11 = { 70, NULL, NULL };
TreeNode s12 = { 65, &s10, &s11 };
TreeNode s13 = { 74, &s12, NULL };
TreeNode s14 = { 60, &s7, &s13 };
TreeNode* root = &s14;

int main(void)
{


    char c;
    int n = 0;
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf("| s     : �˻�             |\n");
    printf("| i     : ��� �߰�        |\n");
    printf("| d     : ��� ����        |\n");
    printf("| t     : ���� ��ȸ        |\n");
    printf("| I     : ��� �߰�(�ݺ�)  |\n");
    printf("| D     : ��� ����(�ݺ�)  |\n");
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");




    while (1) {
        printf("�޴� �Է�: ");
        scanf_s(" %c", &c, sizeof(c));  // ���� �Է� ���� ����
        if (c == 's') {
            printf("�˻��� �� �Է�: ");
            scanf_s("%d", &n);
            TreeNode* result = search(root, n);
            if (result != NULL && n == result->key) {
                printf("�湮�� ����� ��: %d\n", cnt);
                printf("�˻� ����: %d\n", result->key);
                printf("���� ��ȸ ���: ");
                inorder(root);
                printf("\n");
                cnt = 0;
            }
            else {
                printf("�˻� ����.\n");
            }
        }
        else if (c == 'i')
        {

            printf("������ �� �Է�: ");
            scanf_s("%d", &n);
            TreeNode* result = search(root, n);
            insert_node(root, n);
            printf("�湮�� ����� ��: %d\n", cnt);
            inorder(root);
            printf("\n\n");
            cnt = 0;
        }
        else if (c == 'd') {
            printf("������ �� �Է�: ");
            scanf_s("%d", &n);
            delete_node(root, n);
            printf("�湮�� ����� ��: %d\n", cnt);
            inorder(root);
            printf("\n\n");
            cnt = 0;
        }
        else if (c == 't') {
            inorder(root);
            printf("\n�湮�� ����� ��: %d\n", cnt);
            printf("\n\n");
            cnt = 0;
        }
        else if (c == "c")
        {
            printf("����");
            break;
        }
            
    }
    return 0;
}
