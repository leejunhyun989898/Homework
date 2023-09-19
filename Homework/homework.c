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

    TreeNode* stack[100]; // 스택을 사용하여 노드를 저장
    int top = -1;

    stack[++top] = root; // 루트 노드를 스택에 추가

    while (top >= 0) {
        TreeNode* current = stack[top--]; // 스택에서 노드를 꺼내옴
        count++; // 노드 카운트 증가

        // 오른쪽 자식을 먼저 스택에 추가
        if (current->right)
            stack[++top] = current->right;

        // 왼쪽 자식을 스택에 추가
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
    // 노드가 NULL인 경우, 0을 반환합니다.
    if (root == NULL)
        return 0;

    // root->left 와 root->right가 NULL일 경우, 해당 노드의 데이터 값을 반환
    if (root->left == NULL && root->right == NULL)
        return root->data;
    else {
        // 왼쪽 서브트리를 계산하여 op1에 저장.
        float op1 = evaluate(root->left);

        // 오른쪽 서브트리를 계산하여 op2에 저장
        float op2 = evaluate(root->right);


        printf("%0.2f %c %0.2f = ", op1, root->data, op2);

        switch (root->data) {
        case '+':
            // 덧셈 연산을 수행 후 결과를 출력
            printf("%0.2f\n", op1 + op2);
            return op1 + op2;
        case '-':
            // 뺄셈 연산을 수행 후 결과를 출력
            printf("%0.2f\n", op1 - op2);
            return op1 - op2;
        case '*':
            // 곱셈 연산을 수행 후 결과를 출력
            printf("%0.2f\n", op1 * op2);
            return op1 * op2;
        case '/':
            // 나눗셈 연산을 수행 후 결과를 출력
            printf("%0.2f\n", op1 / op2);
            return op1 / op2;
        }

    }

    return 0;
}
int main(void)
{

    printf("수식의 값은 %0.2f입니다.\n", evaluate(exp));

    int nodeCount = get_node_count_iter(exp); // 반복적 방법으로 노드의 개수 계산
    printf("\n총 노드의 개수는 %d 입니다.\n", nodeCount);
    return 0;
}