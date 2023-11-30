#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX];
int n,round;
float cnt1, cnt2, sum1, sum2;

int partition(int list[],int left, int right) {
	cnt1 = 0;
	cnt2 = 0;
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high) {
			SWAP(list[low], list[high], temp);
			cnt1++;
		}
		cnt2++;
	} while (low < high);
	SWAP(list[left], list[high], temp);
	if (SWAP(list[left], list[high], temp)) {
		cnt1++;
	}
	
	sum1 += cnt1;
	cnt2++;
	return high;

}
void quick_sort(int list[], int left, int right) {

	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
		
		if (round == 0)
		{
			for (int k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}
	sum2 += cnt2;
}

int main(void)
{
	int i;
	n = MAX;
	int before_list[MAX];
	srand(time(NULL));

	for (round = 0; round < n; round++) {
		
		for (i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}
	}

	printf("Original list: ");
	for (round = 0; round < n; round++) {
		for (i = 0; i < n; i++) {
			if (i == 0) {
				printf("%d ", list[round]);
			}
		}
	}

	printf("\n\n");
	printf("Quick Sort\n");
	for (round = 0; round < n; round++) {

		quick_sort(list, 0, n - 1);

	}

	printf("\n");
	
	
	printf("\nMove Count average: %f\n", sum1/n);
	printf("Compare Count average: %f\n", sum2/n);
	return 0;
}
