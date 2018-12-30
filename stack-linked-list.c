#include <stdio.h>
#include <stdlib.h>
#define INF 99999999 // 오류 메세지값

typedef struct{
	int data;
	struct Node *next;
}Node;

typedef struct{
	Node *top; // 
}Stack; // 항상 최상단 노드가 Top이 된다. top이 어딘지 잡아주기 위함.

void push(Stack *stack, int data){
	Node *node = (Node*)malloc(sizeof(Node)); // 새로 push할 노드 생성
	node -> data = data; // 노드에 매개변수로 받아온 data 값 입력
	node -> next = stack ->top; // 노드가 top(최상단 노드)를 가리키도록 설정
	stack -> top = node; //최상단 노드는 새로 push한 node가 됨
}

void pop(Stack *stack){
	if (stack->top == NULL){
		printf("stack underflowed!!!!\n");
		return -INF;
	}
	Node *node = stack->top; // top이 가리키는 노드를 node변수로 받음
	int data = node->data;
	stack -> top = node ->next; // 두번째 노드가 최상단 노드가 되도록 바꿈
	free(node); //node의 메모리 할당 해제
	return data;
}

void show(Stack *stack){
	Node *cur = stack -> top;
	printf("----stack's top----\n");
	while(cur != NULL){
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	printf("----stack's bottom----\n");
}

int main(void){
	Stack stack;
	stack.top = NULL;
	push(&stack,7);
	push(&stack,5);
	push(&stack,4);
	pop(&stack);
	push(&stack,6);
	pop(&stack);
	show(&stack);
	return 0;
}	
