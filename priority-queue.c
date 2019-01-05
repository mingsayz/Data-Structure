#include <stdio.h>
#define MAX_SIZE 10000

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

typedef struct{
  int heap[MAX_SIZE];
  int count;
}priorityQueue;

void push(priorityQueue *pq,int data){
  if(pq->count >= MAX_SIZE) return;
  pq -> heap[pq->count] = data; // 데이터를 count(queue에 담겨 있는 원소의 개수에 해당하는 인덱스)
  int now = pq -> count; // 데이터가 들어갈 인덱스 값
  int parent = (pq->count -1) / 2; // 인덱스값이 6이라면 (6-1)/2 이므로 부모의 인덱스값은 2가 된다.
  // 새 원소를 삽입한 이후에 상향식으로 힙을 구성한다.
  while(now > 0 && pq->heap[now] > pq -> heap[parent]){ // 부모의 값보다 자신이 더 크다면
    swap(&pq -> heap[now], &pq->heap[parent]); // 자신이 부모가 됨. (위치를 바꿈)
    now = parent; // 자신을 부모로 바꿈
    parent = (parent -1) / 2; // 자신을 부모로 바꾼 후 상향하여 반복 비교
  }
  pq->count++;
}

int pop(priorityQueue *pq){
  if(pq->count <= 0) return -9999; // 추출할 값이 없다면, error 값 반환
  int res = pq -> heap[0]; // pop시킬 값(루트 노드)을 변수 res에 저장
  pq->count--; // count를 하나 줄임
  pq->heap[0] = pq->heap[pq->count]; //가장 마지막 인덱스의 노드를 루트노드에 넣는다.
  int now = 0, leftChild = 1, rightChild = 2;
  int target = now; // 새 원소를 추출한 이후에 하향식으로 힙을 구성한다. target은 바꾸고자 하는 자신 노드
  while (leftChild < pq->count){ // 원소가 존재할 때까지만 반복한다
    if(pq->heap[target] < pq->heap[leftChild]) target = leftChild; // 맨 처음, 루트 노드가 왼쪽 자식노드보다 작을때 target에 leftchild를 넣어줌.
    if(pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild; // 왼쪽 자식노드보다 오른쪽 자식노드가 더 클 때는 target에 rightchild를 넣어줌.
    //  rightChild < pq->count 이 구문은 오른쪽 자식노드의 인덱스값이 count보다 작을때 수행하기 위해 존재. (인덱스를 벗어나지 않도록 하기 위해)
    if(target == now) break; // 두 자식보다 자신이 더 클때는 바꿀 필요가 없으므로 종료
    else { // 그렇지 않다면 now와 target 스왑
      swap(&pq->heap[now],&pq->heap[target]);
      now = target;
      leftChild = now * 2 + 1; //하향식
      rightChild = now * 2 + 2; //하향식
    }
  }
  return res;
}

int main(void){
  int n, data;
  scanf("%d",&n);
  priorityQueue pq;
  pq.count = 0;
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&data);
    push(&pq,data);
  }
  for (int i = 0 ; i < n ; i++){
    int data = pop(&pq);
    printf("%d ",data);
  }
  return 0;
}
