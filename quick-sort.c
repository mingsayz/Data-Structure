#include <stdio.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
} // 두 값을 바꿈

void quickSort(int start,int end){
	if(start >= end) return;
	int key = start, i = start + 1 , j = end, temp; //i는 왼쪽에서 출발하는 인덱스, j는 오른쪽에서 출발하는 인덱스
	while(i <= j){ //엇갈릴 때까지 반복
		while(i <= end && a[i] <= a[key]) i++; // 왼쪽에서부터 a[key]보다 작은 값을 찾았을 때마다 오른쪽으로 이동,  결과적으로 a[key]보다 큰 값이 선택될 수 있도록 만듬
		while(j > start && a[j] >= a[key]) j--; //오른쪽에서부터 a[key]보다 큰 값을 찾아가면서 왼쪽으로 하나씩 이동, 결과적으로 a[key]보다 작은 값이 선택될 수 있도록 만듬
		if (i > j) swap(&a[key], &a[j]); // 엇갈린 상태면 a[key]와 a[j]를 바꿈
		else swap(&a[i],&a[j]); // 아니면 a[i], a[j]를 바꿔주면 됨
	}
	quickSort(start,j-1); // 재귀적으로 두번 호출
	quickSort(j+1,end); // 재귀적으로 두번 호출
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n ; i++) scanf("%d",&a[i]);
	quickSort(0,n-1);
	for(int i = 0; i < n ; i++)printf("%d",a[i]);
	return 0;
}