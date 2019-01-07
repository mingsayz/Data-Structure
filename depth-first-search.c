#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct{
  int index;
  struct Node *next;
}Node;

Node** a;
int n,m,c[MAX_SIZE];

void addFront(Node *root,int index){
  Node *node = (Node*)malloc(sizeof(Node));
  node->index = index;
  node->next = root->next;
  root->next = node;
}

void dfs(int x){
  if(c[x]) return; //해당 노드를 방문한적이 있다면
  c[x] = 1; // 방문했다고 방문 처리
  printf("%d ",x);
  Node *cur = a[x]->next;
  while (cur != NULL){
    int next = cur->index; //연결 되어있는 다음 노드 확인
    dfs(next);
    cur = cur->next;
  }
}

int main(void){
  scanf("%d %d",&n,&m); //n = 정점 , m = 간선
  a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE)); // 정점의 개수만큼 할당
  for (int i = 1 ; i <= n ; i++){ // a 배열 초기화
    a[i] = (Node*)malloc(sizeof(Node));
    a[i]->next = NULL;
  }
  for (int i = 0 ; i < m ; i++){ // 간선의 개수만큼 반복
    int x,y; // x,y 연결
    scanf("%d %d",&x,&y);
    addFront(a[x],y); //x라는 정점의 연결리스트에 y를 추가함으로써 연결되있다고 표현
    addFront(a[y],x); //y에서도 x로 갈 수있으므로
  }
  dfs(1);
  return 0;
}
