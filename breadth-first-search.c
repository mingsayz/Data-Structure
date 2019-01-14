#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct{
  int index;
  struct Node *next;
}Node; // 연결리스트 정의

typedef struct{
  Node *front;
  Node *rear;
  int count;
}Queue; // queue 정의

Node** a; // 인접한 정점에 대한 정보를 담기위해 이차원 포인터
int n,m,c[MAX_SIZE]; //n : 정점 , m: 간선 , c: 방문한 정보

void addFront(Node *root,int index){
  Node *node = (Node*)malloc(sizeof(Node));
  node->index = index;
  node->next = root->next;
  root->next = node;
} //연결리스트 삽입 함수

void queuePush(Queue *queue,int index){
  Node *node = (Node*)malloc(sizeof(Node));
  node->index = index;
  node->next = NULL;
  if(queue->count ==0){
    queue->front = node;
  } // queue가 비어있으면 queue의 front에 node를 넣는다
  else{
    queue->rear->next = node; // 그게 아니면, 꼬리에 node를 넣는다
  }
  queue->rear = node; // 항상 꼬리는 node가 된다.
  queue->count++;
} // queue에 push하는 함수

int queuePop(Queue *queue){
  if(queue->count == 0){
    printf("queue underflowed!!!!\n");
    return -INF;
  } // queue가 비어있을경우 언더플로우 발생
  Node *node = queue->front; // front 노드를 꺼냄
  int index = node->index; // 해당 노드 인덱스 값
  queue->front = node->next; // 그 다음 노드를 front로 만듬
  free(node);
  queue->count--;
  return index;
} // queue에 pop하는 함수

void bfs(int start){
  Queue q; // queue 생성
  q.front = q.rear = NULL; // front , rear 초기화
  q.count = 0;
  queuePush(&q,start); //queue에 시작하는 인덱스 넣는다.
  c[start] = 1; // 해당 노드 방문처리
  while(q.count != 0){
    int x = queuePop(&q);
    printf("%d ",x);
    Node *cur = a[x]->next; //인접한 노드를 확인
    while(cur != NULL){
      int next = cur->index;
      if(!c[next]){ // 현재 방문하지 않은 상태라면
        queuePush(&q,next); // queue에 넣음
        c[next]=1; //방문 처리
      }
      cur = cur->next;
    }
  }
}

int main(void){
  scanf("%d %d",&n,&m);
  a = (Node**)malloc(sizeof(Node*)*(MAX_SIZE));
  for (int i = 1; i <= n ; i++){
    a[i] = (Node*)malloc(sizeof(Node));
    a[i]->next = NULL;
  }
  for (int i = 0 ; i < m ; i++){
    int x,y;
    scanf("%d %d",&x,&y);
    addFront(a[x],y);
    addFront(a[y],x);
  }
  bfs(1); //node 1을 기준으로 너비우선탐색 실행
  return 0;
}
