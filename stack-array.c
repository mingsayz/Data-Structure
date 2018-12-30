#include <stdio.h>
#define SIZE 10000
#define INF 99999999 // 오류 메세지값

int stack[SIZE];
int top = -1; // top을 전역변수로 선언

void push(int data){
	if(top == SIZE -1){
		printf("stack overflowed!!!");
		return;
	}
	stack[++top] = data;
}

int pop(){
	if(top == -1){
		printf("stack underflowed!!!");
		return -INF; //오류값 반환
	}
	return stack[top--];
}

void show(){
	printf("-----stack's top-----\n");
	for(int i = top ; i>= 0 ; i --){
		printf("%d\n",stack[i]);
	}
	printf("-----stack's bottom-----\n");
}

int main(void){
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	show();
	return 0;
}