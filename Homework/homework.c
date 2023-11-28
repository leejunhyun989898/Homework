#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int sorted[MAX];
int list[MAX];
int n,cnt1,cnt2,sum1,sum2,round,cnt3;
int average_compare_cnt = 0;
int average_move_cnt = 0;

// ������ ���� first~last
void merge(int list[], int left, int mid, int right)
{
	cnt1 = 0;
	cnt3 = 0;
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	//���� ���ĵ� ����Ʈ�� �պ�
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

	//���� ��ҵ� �迭�� ����
	
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
	
	// sorted �迭�� list[]�� �纹��
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
		mid = (left + right) / 2;			// �߰��� ��ġ�� ���� �迭�� �����Ѵ�. -> ����
		
		merge_sort(list, left, mid);		// �迭�� �� �κ��� �����Ѵ�. -> ����
		cnt2++;
		merge_sort(list, mid + 1, right);	// �迭�� �� �κ��� �����Ѵ�. -> ����
		cnt2++;
		merge(list, left, mid, right);		// ���ĵ� 2���� �迭�� �պ��Ѵ�. -> �պ�
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
