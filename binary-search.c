#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;

int search(int start,int end,int target){ // 탐색 함수
  if(start > end) return -9999;
  int mid = (start + end) / 2; // 0~9 까지 인덱스를 확인한다고 했을때 중간값은 4가 됨.
  if(a[mid] == target) return mid;
  else if(a[mid] > target) return search(start,mid-1,target); // 왼쪽 구간에 대해서 다시 검색을 하도록 재귀적으로 함수 호출
  else return search(mid+1,end,target); // 오른쪽 구간에 대해서 다시 검색을 하도록 재귀적으로 함수 호출
}

int main(void){
  int n, target;
  scanf("%d %d",&n,&target);
  for (int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
  int result = search(0,n-1,target);
  if(result != -9999) printf("%d 번째 원소입니다 \n",result +1);
  else printf("원소를 찾을 수 없습니다.\n");
  return 0;
}
