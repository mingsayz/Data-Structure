#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct Node *leftChild;
	struct Node *rightChild;
}Node;

Node* initNode(int data,Node* leftChild,Node* rightChild){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return node;
} // 노드 생성

void preorder(Node* root){
	if(root){
		printf("%d ",root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
} // 이진 트리의 전위 순회 알고리즘(자기 자신 먼저 출력)

void inorder(Node* root){
	if(root){
		inorder(root->leftChild);
		printf("%d ",root->data);
		inorder(root->rightChild);
	}
} // 이진 트리의 중위 순회 알고리즘(왼쪽에서부터 차례대로 방문)

void postorder(Node* root){
	if(root){
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d ",root->data);
	}
}// 이진 트리의 후위 순회 알고리즘

int main(void){
	Node* n7 = initNode(21,NULL,NULL);
	Node* n6 = initNode(14,NULL,NULL);
	Node* n5 = initNode(6,NULL,NULL);
	Node* n4 = initNode(1,NULL,NULL);
	Node* n3 = initNode(17,n6,n7);
	Node* n2 = initNode(5,n4,n5);
	Node* n1 = initNode(10,n2,n3);
	preorder(n1);
	printf("\n");
	inorder(n1);
	printf("\n");
	postorder(n1);
	return 0;
}
