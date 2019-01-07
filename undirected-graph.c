#include <stdio.h>

int a[1001][1001];
int n,m;

int main(void){
  scanf("%d %d",&n,&m); // n : 노드의 개수 , m : 간선의 개수
  for(int i = 0 ; i < m ; i++){
    int x,y;
    scanf("%d %d",&x,&y); // 1,2를 입력받았다면 그 두 가지를 연결하는 것
    a[x][y] = 1;
    a[y][x] = 1;
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1; j <= n ; j++){
      printf("%d",a[i][j]);
    }
    printf("\n");
  }
}
