#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct{
	int data;
	struct Node *next;
}Node;

typedef struct {
	Node *front; 
	Node *rear; // 새로운 값은 끝부분 (rear) 에 들어감 
	int count; //큐 안에 포함되어 있는 원소 개수
}Queue;

void push(Queue *queue, int data){ // 새로운 노드를 queue->rear가 되게 만듬
	Node *node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = NULL;
	if (queue -> count == 0){
		queue->front = node;
	}
	else {
		queue -> rear -> next = node;
	}
	queue -> rear = node;
	queue -> count++;
}

int pop(Queue *queue){ //front 부터 꺼내고 다음 노드(next)를 front로 만듬
	if (queue -> count == 0){
		printf("queue underflowed!!!");
		return -INF;
	}
	Node *node = queue->front;
	int data = node -> data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return data;
}

void show(Queue *queue){
	Node *cur = queue->front;
	printf("---front of queue---\n");
	while (cur != NULL){
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	printf("---rear of queue---\n");
}

int main(void){
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue,7);
	push(&queue,5);
	push(&queue,4);
	pop(&queue);
	push(&queue,6);
	pop(&queue);
	show(&queue);
	return 0;
}