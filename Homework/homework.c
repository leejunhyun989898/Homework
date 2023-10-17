#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct HeapType {
    element* heap;
    int heap_size;
} HeapType;

// 최대 힙을 생성
HeapType* create(int size) {
    HeapType* h = (HeapType*)malloc(sizeof(HeapType));
    h->heap = (element*)malloc(sizeof(element) * (size + 1));
    h->heap_size = 0;
    return h;
}

// 힙 초기화
void init(HeapType* h) {
    h->heap_size = 0;
}

// 최대 힙에 원소를 삽입
void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item > h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

// 최대 힙에서 원소를 삭제하고 반환
element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
            child++;
        if (temp >= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

// 배열을 출력
void print_array(element a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 힙 정렬을 수행
void heap_sort(element a[], int n) {
    int i;
    HeapType* h;
    h = create(n);
    init(h);

    for (i = 0; i < n; i++) {
        insert_max_heap(h, a[i]);
        print_array(h->heap + 1, h->heap_size);
    }

    for (i = n - 1; i >= 0; i--) {
        a[i] = delete_max_heap(h);
        print_array(h->heap + 1, h->heap_size);
    }

    free(h);
}

int main() {
    element list[] = { 34,12,76,59,32,55,88,26,16,79,34,85,29,78,41,56,86 };
    int n = sizeof(list) / sizeof(list[0]);

    printf("<정렬>\n");
    heap_sort(list, n);

    print_array(list, n);

    return 0;
}
