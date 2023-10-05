#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
typedef struct TreeNode {
    element data;
    struct TreeNode* left, * right;
} TreeNode;

int cnt = 0;

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

TreeNode* new_node(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* root, int item) // 수정된 인자 추가
{
    cnt++;
    if (root == NULL)
        return new_node(item);

    if (item < root->data)
        root->left = insert_node(root->left, item);
    else if (item > root->data)
        root->right = insert_node(root->right, item);

    return root;
}

TreeNode* min_value_node(TreeNode* node)
{
    if (node == NULL)
        return NULL;

    while (node->left != NULL) // 수정된 부분
        node = node->left;
    return node;
}

TreeNode* delete_node(TreeNode* root, int key)
{

    cnt++;
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else
    {

        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode* temp = root->left;
            return temp;
        }
        else {
            TreeNode* temp = min_value_node(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

TreeNode* search(TreeNode* root, int key) {
    TreeNode* node = root;
    while (node != NULL) {
        cnt++;
        if (key == node->data)
        {
            return node;
        }
        else if (key < node->data)
        {
            node = node->left;
        }
        else {
            node = node->right;
        }

    }
    return NULL;
}

TreeNode* Iteinsert_node(TreeNode* root, TreeNode* node) {
    while (1) {
        cnt++;
        if (root->data == node->data) return NULL;
        if (root->data > node->data) {
            if (root->left == NULL) {
                root->left = node;
                return node;
            }
            else root = root->left;
        }
        else {
            if (root->right == NULL) {
                root->right = node;
                return node;
            }
            else root = root->right;
        }
    }
}
TreeNode* Itedelete_node(TreeNode* root, int key) {
    TreeNode* parent = NULL;
    TreeNode* target = NULL;
    int target_value = 0;

    while (root->data != key) {
        cnt++;
        parent = root;
        if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    target = root;
    target_value = target->data;
    if (root->left != NULL && root->right != NULL) {
        root = root->right;
        while (1) {
            cnt++;
            parent = root;
            root = root->left;
            if (root->left == NULL)
                break;
        }
        target->data = root->data;
        parent->left = NULL;
    }
    else if (root->left == NULL && root->right == NULL) {
        if (parent->left == target)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else {
        if (target->right == NULL) {
            target->data = target->left->data;
            target->right = target->left->right;
            target->left = target->left->left;

        }
        else {
            target->data = target->right->data;
            target->left = target->right->left;
            target->right = target->right->right;
        }
    }
    return target;
}

void inorder(TreeNode* root)
{
    if (root) {
        cnt++;
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main(void)
{
    TreeNode* tree = root;
    char c;
    int n = 0;
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("| s     : 검색             |\n");
    printf("| i     : 노드 추가        |\n");
    printf("| d     : 노드 삭제        |\n");
    printf("| t     : 중위 순회        |\n");
    printf("| I     : 노드 추가(반복)  |\n");
    printf("| D     : 노드 삭제(반복)  |\n");
    printf("| e     : 종료             |\n");
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

    while (1) {
        printf("메뉴 입력: ");
        scanf_s(" %c", &c, sizeof(c));  // 문자 입력 오류 방지
        if (c == 's') {
            printf("검색할 값 입력: ");
            scanf_s("%d", &n);
            TreeNode* result = search(tree, n);
            if (result != NULL && n == result->data) {
                printf("방문한 노드의 수: %d\n", cnt);
                printf("검색 성공: %d\n", result->data);
                printf("중위 순회 결과: ");
                inorder(tree);
                printf("\n\n");
                cnt = 0;
            }
            else {
                printf("검색 실패.\n");
            }
        }
        else if (c == 'i') {
            printf("삽입할 값 입력: ");
            scanf_s("%d", &n);
            tree = insert_node(tree, n);
            printf("방문한 노드의 수: %d\n", cnt);
            inorder(tree);
            printf("\n\n");
            cnt = 0;
        }
        else if (c == 'd') {
            printf("삭제할 값 입력: ");
            scanf_s("%d", &n);
            tree = delete_node(tree, n);
            printf("방문한 노드의 수: %d\n", cnt);
            inorder(tree);
            printf("\n\n");
            cnt = 0;
        }
        else if (c == 't') {
            inorder(tree);
            printf("\n방문한 노드의 수: %d\n", cnt);
            printf("\n\n");
            cnt = 0;
        }
        else if (c == 'I') {
            printf("삽입할 값 입력: ");
            scanf_s("%d", &n);
            TreeNode* newNode = new_node(n);
            TreeNode* result = Iteinsert_node(tree, newNode);
            if (result != NULL) {
                printf("노드 추가: %d\n", result->data);
            }
            printf("방문한 노드의 수: %d\n", cnt);
            inorder(tree);
            printf("\n\n");
            cnt = 0;
        }
        else if (c == 'D') {
            printf("삭제할 값 입력: ");
            scanf_s("%d", &n);
            TreeNode* result = Itedelete_node(tree, n);
            if (result != NULL) {
                printf("노드 삭제: %d\n", result->data);
                free(result); // 삭제된 노드는 메모리에서 해제
            }
            printf("방문한 노드의 수: %d\n", cnt);
            inorder(tree);
            printf("\n\n");
            cnt = 0;
        }

        else if (c == 'e') {
            printf("종료\n");
            break;
        }
    }
    return 0;
}
