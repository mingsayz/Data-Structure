#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data[100];
	struct Node *next;
}Node;

typedef struct Stack{
	Node *top;
}Stack;

void push(Stack *stack, char * data){
	Node *node = (Node*)malloc(sizeof(Node)); // 새로 push할 노드 생성
	strcpy(node->data,data);// 노드에 매개변수로 받아온 data 값 입력
	node -> next = stack ->top; // 노드가 top(최상단 노드)를 가리키도록 설정
	stack -> top = node; //최상단 노드는 새로 push한 node가 됨
}

char *getTop(Stack *stack){
	Node *top = stack->top;
	return top->data;
}

char *pop(Stack *stack){
	if (stack->top == NULL){
		printf("stack underflowed!!!!\n");
		return NULL;
	}
	Node *node = stack->top; // top이 가리키는 노드를 node변수로 받음
	char *data = (char *)malloc(sizeof(char) * 100);
	strcpy(data, node->data);
	stack -> top = node ->next; // 두번째 노드가 최상단 노드가 되도록 바꿈
	free(node); //node의 메모리 할당 해제
	return data;
}

int getPriority(char *i){
	if (!strcmp(i, "(")) return 0;
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
	return 3;
} // 우선 순위 함수 만들기 +,- 만났을 때는  1, *,/ 만났을때는 2 반환하여 우선 순위를 높게 만듬

char *transition(Stack *stack, char **s,int size){ // 들어오는 문자열을 s로 받음
	char res[1000] = "";
	char *res_ptr = res;
	for (int i = 0 ; i < size ; i++){
		if(!strcmp(s[i],"+") || !strcmp(s[i],"-") || !strcmp(s[i],"*") || !strcmp(s[i],"/")) {
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
				strcat(res,pop(stack)); strcat(res," ");
			}
			push(stack,s[i]);
		}
		else if(!strcmp(s[i],"(")) push(stack,s[i]); //"("를 만나면 바로 스택에 집어 넣음
		else if(!strcmp(s[i],")")){ // ")"인 경우 "(" 가 나올때까지 스택에서 뽑아서 res에 붙여씀
			while (strcmp(getTop(stack),"(")){
				strcat(res,pop(stack)); strcat(res," ");
			}
			pop(stack); //pop을 해줌으로써 "(" 여는괄호까지 나오게끔 한다
		}
		else { strcat(res,s[i]); strcat(res," ");} // 일반 숫자일 경우 바로 res변수에 붙여쓴다.
	}
	while (stack->top != NULL){
		strcat(res,pop(stack)); strcat(res," "); // 남아있는 문자열이 있다면 다 뽑아내줌
	}
	return res_ptr;
} 

void calculate(Stack *stack,char **s,int size){
	int x,y,z;
	for (int i = 0 ; i < size ; i ++){
		if(!strcmp(s[i],"+") || !strcmp(s[i],"-") || !strcmp(s[i],"*") || !strcmp(s[i],"/")) {
			x = atoi(pop(stack));
			y = atoi(pop(stack));
			if (!strcmp(s[i],"+")) z = y + x;
			if (!strcmp(s[i],"-")) z = y - x;
			if (!strcmp(s[i],"*")) z = y * x;
			if (!strcmp(s[i],"/")) z = y / x;
			char buffer[100];
			sprintf(buffer,"%d",z); //숫자를 다시 문자형태로 바꿈
			push(stack,buffer);
		}
		else {
			push(stack,s[i]);
		}
	}
	printf("%s\n",pop(stack));
}

int main(void){
	Stack stack;
	stack.top = NULL;
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	int size = 1;
	for (int i = 0 ; i < strlen(a) ; i++){
		if (a[i] == ' ') size++;
	}
	char *ptr = strtok(a," ");
	char **input = (char **)malloc(sizeof(char *) * size);
	for (int i = 0 ; i < size ; i++){
		input[i] = (char*)malloc(sizeof(char) * 100);
	}
	for (int i = 0 ; i < size ; i++){
		strcpy(input[i],ptr);
		ptr = strtok(NULL," ");
	}
	char b[1000] = "";
	strcpy(b, transition(&stack,input,size));
	printf("후위 표기법 : %s\n",b);
	size = 1;
	for (int i = 0 ; i < strlen(b)-1 ; i++){ //마지막은 항상 공백이 들어가므로 1을 빼기
		if (b[i] ==' ') size++;
	}
	char *ptr2 = strtok(b," ");
	for (int i = 0 ; i < size ; i++){
		strcpy(input[i],ptr2);
		ptr2 = strtok(NULL," ");
	}
	calculate(&stack,input,size);
	return 0;
}
