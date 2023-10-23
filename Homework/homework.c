#include <stdio.h>
#include <stdlib.h>
#define Max_e 200

typedef struct TreeNode {
	int weight;
	char ch;
	struct TreeNode* left;
	struct TreeNode* right;

} TreeNode;

typedef struct {
	TreeNode* ptree;
	char ch;
	int key;
} element;

typedef struct {
	element heap[Max_e];
	int heap_size;
} HeapType;
// ����
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
// �ʱ�ȭ
void init(HeapType* h) {
	h->heap_size = 0;
}
//���� ����� ������ heap_size�� ���� h�� item ����
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	//�θ� ���  ��
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; //���ο� ��� ����
}
//����
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while ((child <= h->heap_size)) {
		//���� ����� �ڽĳ�� �� �� ���� �ڽĳ�� ã��
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key < h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
// ���� Ʈ�� ���� 
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = right;
	node->right = left;
	return node;
}
//���� Ʈ�� ����
void destroy_tree(TreeNode* root) {
	if (root == NULL) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int is_leaf(TreeNode* root) {
	return !(root->left) && !(root->right);
}

void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top) {
	//1�� �����ϰ� ��ȯȣ��
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	//0�� �����ϰ� ��ȯȣ��
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}
	//�ܸ�����̸� �ڵ� ���
	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}
// ������ �ڵ� ���� 
void huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int codes[1000];
	int top = 0;
	heap = create();
	init(heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}
	for (i = 1; i < n; i++) {
		//�ּҰ��� ������ �ΰ��� ��带 ����
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		//�ΰ��� ��带 ��ħ
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap);//���� Ʈ��
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);
}

// �� ������ ����
void heap_sort(int a[], int n) {
	int i, j;
	HeapType* h;
	h = create();
	init(h);

	for (i = 0; i < n; i++) {
		element e;
		e.ch = ' ';
		e.key = a[i];
		e.ptree = NULL;
		insert_min_heap(h, e);
		for (j = 1; j <= h->heap_size; j++) {
			printf("%d ", h->heap[j].key);
		}
		printf("\n");
	}

	for (i = n - 1; i >= 1; i--) {
		// �ּҰ��� ������ �� ���� ��带 ����
		element e1 = delete_min_heap(h);
		element e2 = delete_min_heap(h);

		// �� ���� ��带 ��ħ
		TreeNode* x = make_tree(e1.ptree, e2.ptree);
		element e;
		e.ch = ' ';
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;

		// ��� ���� ����
		printf("%d + %d -> %d\n",e1.key,e2.key,e.key);
		
		for (j = 1; j <= h->heap_size; j++) {
			printf("%d ", h->heap[j].key);
		}
		printf("\n");

		// ���ο� ��带 ���� ����
		insert_min_heap(h, e);
	}
	free(h);
}

int main(void) {
	char ch_left[] = { 'a','e','i','o','u','s','t' };
	int freq[] = { 10,15,12,3,4,13,1 };
	int n = sizeof(freq) / sizeof(freq[0]);


	heap_sort(freq, n);


	huffman_tree(freq, ch_left, 7);

	return 0;
}

