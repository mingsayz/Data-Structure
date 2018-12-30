#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct Node *next; // Node 구조체를 가리킬 next 포인터 선언
} Node;

Node *head; //head 포인터 전역 변수로 선언 (head는 항상 맨 앞에 존재)

void addFront(Node *root,int data){ // 맨 앞에 추가하는 형식
	Node *node = (Node*)malloc(sizeof(Node)); // 새로 추가할 노드의 메모리 공간 할당 (node)
	node -> data = data; // 그 노드에 매개변수로 받아온 data 입력
	node -> next = root -> next; //head가 가리키고 있던 구조체의 next 값을 node의 next값으로 넣어줌
	root -> next = node; // head의 next 값은 새로 만든 node를 가리키도록 만듬
}
// insert node function

void removeFront(Node *root){ // 맨 앞 값 제거
	Node *front = root->next; // head가 가리키던 구조체를 front 변수로 받아옴
	root->next = front->next; // head가 front 다음의 구조체를 가리키도록 만듬
	free(front); // front 메모리 할당 해제
}
// remove node function

void freeAll(Node *root){
	Node *cur = head->next;
	while(cur != NULL){
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}
// 모든 할당된 메모리를 해제한다.
void showAll(Node *root){
	Node *cur = head->next;
	while (cur != NULL){
		printf("%d ",cur->data);
		cur = cur -> next;
	}
}

int main(void){
	head = (Node*)malloc(sizeof(Node));
	head -> next = NULL;
	addFront(head,2);
	addFront(head,1);
	addFront(head,7);
	addFront(head,9);
	addFront(head,8);
	removeFront(head);
	showAll(head);
	freeAll(head);
	return 0;
	
}
