#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int sorted[MAX];
int list[MAX];
int n,cnt1,cnt2,sum1,sum2,round;
int average_compare_cnt = 0;
int average_move_cnt = 0;
//gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위 first~last
inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j];
			cnt1++;
		}
		list[j + gap] = key;
		cnt2++;
	}
}

void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0)gap++;
		for (i = 0; i < gap; i++) //부분리스트의 개수= gap
		{
			inc_insertion_sort(list, i, n - 1, gap);
		}
		if (round == 0)
		{
			for (int k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}
	sum1 += cnt1;
	sum2 += cnt2;
}

int main(void)
{
	int i;
	n = MAX;
	int before_list[MAX];
	srand(time(NULL));

	for (round = 0; round < n; round++) {
		cnt1 = 0;
		for (i = 0; i < n; i++) {
			list[i] = rand() % 100;
			if (round == 0) {
				before_list[i] = list[i];
			}

		}

	}

	printf("Original list: ");
	for (round = 0; round < n; round++) {
		printf("%d ", before_list[round]);
	}
	printf("\n\n");
	for (round = 0; round < n; round++) {
		
		cnt2 = 0;

		shell_sort(list, n);
	}

	printf("\n");
	average_move_cnt = sum2/MAX;
	average_compare_cnt = sum1/MAX;
	
	printf("\nMove Count average: %d\n", average_move_cnt-1);
	printf("Compare Count average: %d\n", average_compare_cnt);
	return 0;
}
