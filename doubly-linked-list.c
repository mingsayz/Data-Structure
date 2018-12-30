#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct Node *prev; // struct Node를 가리키는 포인터 생성
	struct Node *next; // struct Node를 가리키는 포인터 생성
}Node;

Node *head,*tail; // head, tail을 전역 변수로 선언


void insert(int data){
	Node *node = (Node*)malloc(sizeof(Node)); // 삽입할 데이터를 받아올 node 구조체 포인터 생성
	node -> data = data; // 노드의 데이터안에 매개변수로 받아온 데이터 입력
	Node *cur; // 위치를 잡아줄 cur 구조체 포인터 생성
	cur = head->next; // head(시작) 부터 끝까지 검사하기 위해서 첫 위치 선언
	while(cur->data < data && cur != tail){ // 오름차순 정렬 할 것이므로 
		cur = cur->next; // cur에는 현재 삽입될 data보다 한단계 큰 값의 노드가 저장되어있음.
	}
	Node* prev = cur->prev; // cur 이전 노드값을 prev로 받아옴
	prev ->next = node; // prev의 next를 삽입할 node로 변경
	node ->prev = prev; // node의 prev를 prev를 가리키도록 만듬
	cur ->prev = node; // node 보다 한단계 큰 값의 노드이므로 cur의 prev가 node를 가리키도록 만듬
	node ->next = cur; // node의 next는 cur 이 됨
}

void removeFront(){
	Node *node = head->next; //헤드가 가리키고 있는 노드를 node 변수로 받아옴
	head ->next = node->next; //head의 next를 node의 next로 변경(노드가 가리키고 있던 주소)
	Node *next = node->next; //node가 가리키고 있는 노드(그 다음 단계 노드)를 next 변수로 받아옴
	next ->prev = head; //그 노드의 prev 값을 head로 변경
	free(node); // node 메모리 할당 해제
} 

void show(){
	Node *cur = head->next;
	while(cur != tail){
		printf("%d ",cur->data);
		cur = cur->next;
	}
}

int main(void){
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head -> next = tail;
	head -> prev = head;
	tail -> next = tail;
	tail -> prev = head;
	insert(2);
	insert(1);
	insert(9);
	insert(7);
	insert(12);
	removeFront();
	show();
	return 0;
}