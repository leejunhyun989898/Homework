#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int list[MAX];
int n,cnt1,cnt2,round;
int sum1 = 0;
int sum2 = 0;
int average_compare_cnt = 0;
int average_move_cnt = 0;
//선택 정렬
void selection_sort(int list[], int n)
{
	int i, j,k,l, least, temp;

	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			//비교횟수
			cnt2++;
			if (list[j] < list[least])
			{
				least = j;

			}
		}
		SWAP(list[i], list[least], temp);
		//이동횟수
		cnt1++;
		if (round == 0)
		{
			for (k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}
}
// 삽입 정렬 
void insertion_sort(int list[], int n) {
	int i,j,k,key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
			//비교횟수
			cnt2++;
		}
		if (round == 0) {
			for (k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}
		list[j + 1] = key;
		//이동횟수
		cnt1++;
	}
}
//버블정렬
void bubble_sort(int list[],int n){
	int i, j, temp;
	for (i = n-1; i >0; i--) {
		for (j = 0;j<i; j++)
			if (list[j] < list[j+1])
			{
				SWAP(list[j], list[j + 1], temp);
				//비교횟수
				cnt2++;
			}
		if (round == 0) {
			for (int k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}
		//이동횟수
		cnt1++;
	}
}

int main(void)
{
	int i;
	n = MAX;
	srand(time(NULL));
	printf("Selection sort\n\n");
	//20 라운드 반복
	for (round = 0; round < n; round++) {
		cnt1 = 0;
		cnt2 = 0;
		//랜덤 수 생성 후 배열 저장
		for (i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}
		//정렬 함수 호출
		selection_sort(list, n);
		sum1 += cnt1;
		sum2 += cnt2;
	}

	average_compare_cnt = sum2/MAX;
	average_move_cnt = (sum1)/MAX;

	printf("Move Count: %d\n",cnt1);
	printf("Compare Count: %d", cnt2);
	printf("\n\nMove Count average: %d\n", average_move_cnt);
	printf("Compare Count average: %d\n", average_compare_cnt);
	return 0;
}
