#include <stdio.h>
#define MAX_VALUE 10001 // 10001보다 크면 정렬할 수 없음. 인덱스가 10001까지므로. (메모리 소모는 퀵 정렬 등 보다 크지만 훨씬 빠르게 정렬할 수 있다는 장점이 있다)


int n,m;
int a[MAX_VALUE];

int main(){
	scanf("%d",%n);
	for(int i = 0; i < n ; i++){ 
		scanf("%d",&m); 
		a[m]++; // 값이 입력 될 때마다 해당 인덱스의 값을 1씩 증가,  이 과정 자체가 정렬이라고 볼 수 있다.
	}
	for(int i = 0; i < MAX_VALUE ; i++){
		while (a[i] != 0){
			printf("%d",i);
			a[i]--;
		}
	}
}