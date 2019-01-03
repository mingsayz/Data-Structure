#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
} // 두 값을 바꿈

int main(void){
	int n,min,index;
	scanf("%d",&n); // 비교할 값들의 개수를 입력
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",&a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		min = INT_MAX; // 작은 값을 항상 선택할 수 있도록 가능한 큰값을 넣어둔다
		for (int j = i ; j < n ; j++){
			if (min > a[j]){
				min = a[j];
				index = j;
			}
		}
		swap(&a[i],&a[index]);
	}
	for (int i = 0; i < n ; i++) { 
		printf("%d",a[i]);
	}
	return 0;
}