#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int list[MAX];
int n,cnt1,cnt2;

void selection_sort(int list[], int n)
{
	int sum1 = 0;
	int sum2 = 0;
	int average_compare_cnt = 0;
	int average_move_cnt = 0;
	int i, j,k,l, least, temp;
	for (l = 0; l < MAX; l++) {
		for (i = 0; i < n - 1; i++) {
			least = i;

			for (j = i + 1; j < n; j++) {
				cnt2++;
				if (list[j] < list[least])
				{
					least = j;

				}
			}
			SWAP(list[i], list[least], temp);
			cnt1++;
			if (l == 0)
			{
				for (k = 0; k < n; k++) {
					printf("%d ", list[k]);
				}
				printf("\n");

			}

		}
		sum1 += cnt1;
		sum2 += cnt2;
		cnt1 = 0;
		cnt2 = 0;
	}
	average_compare_cnt = sum2 / 20;
	average_move_cnt = sum1 / 20;
	printf("Move Count average: %d\n", average_move_cnt);
	printf("Compare Count average: %d\n", average_compare_cnt);

}

void insertion_sort(int list[], int n) {
	int i,j,key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void bubble_sort(int list[],int n){
	int i, j, temp;
	for (i = n-1; i >0; i--) {
		for (j = 0;j<i; j++)
			if (list[j] < list[j+1])
			{
				SWAP(list[j], list[j + 1], temp);
		
			}
	}
}

int main(void)
{
	int i;
	n = MAX;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}
	
	selection_sort(list, n);


	return 0;
}
