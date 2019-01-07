#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int index;
  int distance;
  struct Node *next;
}Node;

void addFront(Node *root,int index,int distance){
  Node *node = (Node*)malloc(sizeof(Node));
  node->index = index;
  node->distance = distance;
  node->next = root->next;
  root->next = node;
}

void showAll(Node *root){
  Node *cur = root->next;
  while(cur != NULL){
    printf("%d(거리 : %d )",cur->index,cur->distance);
    cur = cur->next;
  }
}

int main(void){
  int n,m;
  scanf("%d %d",&n,&m); // n: 노드의 개수 , m : 간선의 개수
  Node** a = (Node**)malloc(sizeof(Node*) * (n+1)); // 각 인덱스가 1부터 출발한다고 가정하므로 n+1
  for(int i = 1; i <= n ; i++){ // 노드 생성
    a[i] = (Node*)malloc(sizeof(Node));
    a[i]->next = NULL;
  }
  for(int i = 0 ; i < m ; i++){
    int x,y,distance;
    scanf("%d %d %d",&x,&y,&distance); // x , y 연결 distance: 가중치
    addFront(a[x],y,distance);
  }
  for(int i = 1 ; i <= n ; i++){ // 출력
    printf("원소 [%d] :",i);
    showAll(a[i]);
    printf("\n");
  }
  return 0;
}
