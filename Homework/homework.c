#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int sorted[MAX];
int list[MAX];
int n,cnt1,cnt2,sum1,sum2,round,cnt3;
int average_compare_cnt = 0;
int average_move_cnt = 0;

// 정렬의 범위 first~last
void merge(int list[], int left, int mid, int right)
{
	cnt1 = 0;
	cnt3 = 0;
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	//분할 정렬된 리스트의 합병
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			sorted[k++] = list[i++];
			
		}
		else {
			sorted[k++] = list[j++];
			
		}
		cnt1++;
	}

	//남은 요소들 배열에 복사
	
	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
			
		}	
		
	}
	else{
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
		}
		
		
	}
	cnt3++;
	
	// sorted 배열의 list[]로 재복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

}

void merge_sort(int list[], int left, int right)
{
	cnt3 = 0;
	cnt2 = 0;
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;			// 중간을 위치를 구해 배열을 분할한다. -> 분할
		
		merge_sort(list, left, mid);		// 배열의 앞 부분을 정렬한다. -> 정복
		cnt2++;
		merge_sort(list, mid + 1, right);	// 배열의 뒷 부분을 정렬한다. -> 정복
		cnt2++;
		merge(list, left, mid, right);		// 정렬될 2개의 배열을 합병한다. -> 합병
		cnt2++;
		if (round == 0)
		{
			for (int k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}

	}	
	sum1 += cnt1 *cnt3;
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
	for (round = 0; round < n; round++) {
		
		merge_sort(list, 0, n-1);
		
	}

	printf("\n");
	average_move_cnt = sum2/MAX;
	average_compare_cnt = sum1/MAX;
	
	printf("\nMove Count average: %d\n", average_move_cnt-1);
	printf("Compare Count average: %d\n", average_compare_cnt);
	return 0;
}
