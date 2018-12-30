# 자료구조

* 자료구조의 필요성
  1. 데이터를 효과적으로 저장하고, 처리하는 방법에 대해서 바르게 이해할 필요가 있다.
  2. 자료구조를 제대로 이해하지 못하면 불필요하게 메모리와 성능을 낭비할 여지가 있다.
  3. 프로그램 내에서 int형 데이터가 100만개 가량 될때 원하는 데이터를 가장 빠르게 찾도록 해주는 자료구조를 찾기 위해서

---


## 기본적인 자료구조들
  * 선형 구조
    - 배열
    - 연결 리스트
    - 스택
    - 큐
  * 비선형 구조
    - 트리(Tree)
    - 그래프(Graph)

---

## 자료구조와 알고리즘
  - 효율적인 자료구조 설계를 위해 알고리즘 지식이 필요하다.
  - 효율적인 알고리즘을 작성하기 위해서는 문제 상황에 맞는 적절한 자료구조가 사용되어야 한다.
  - 따라서 자료구조론과 알고리즘 이론은 모두 동일선상에 놓을 수 있다.

---

## 프로그램의 성능 측정 방법론

1. 시간 복잡도(Time Complexity)란 알고리즘에 사용되는 연산 횟수를 의미한다.
2. 공간 복잡도(Space Complexity)란 알고리즘에 사용되는 메모리의 양을 의미한다.

> 효율적인 알고리즘을 사용한다고 가정했을 때 일반적으로 시간과 공간은 반비례 관계이다.

  * 시간 복잡도를 표현할 때는 최악의 경우를 나타내는 Big-O 표기법을 사용한다. 다음 알고리즘은 O(n)의 시간 복잡도를 가진다.

  ```cpp
    int main(void){
      int a,b;
      cin >> a >> b;
      int sum = 1;
      for (int i = 0 ; i < b ; i++){
        sum \*= a;
      }
      cout << sum;
    }
  ```

  * 다음 알고리즘은 O(n^2)의 시간복잡도를 가진다.
  ```cpp
    #include <iostream.h>

    using namespace std;

    int main(void){
      int n;
      cin >> n;
      for(int i = 0; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
          cout << "\*";
        }
        cout << '\n';
      }
    }
  ```

  * 다음 알고리즘은 1의 시간 복잡도를 가진다.

  ```cpp
    int main(void){
      int a,b;
      cin >> a >> b;
      cout << a + b;
    }

  ```

![Big-O](https://joshuajangblog.files.wordpress.com/2016/09/1.jpg?w=638)

  * [예시] : n이 1000일 때
    - n : 1000번의 연산
    - nlogn : 약 10000번의 연산 (1000 * log1000)
    - n^2 : 1,000,000번의 연산
    - n^3 : 1,000,000,000번의 연산

  > 보통 연산의 횟수가 10억을 넘어가면 1초 이상의 시간이 소요된다.

  * 시간 복잡도를 표기할 때는 항상 큰 항과 계수만 표시한다.
    - O(3n^2 + n) = O(n^2)
    - 현실적인 다양한 문제에서는 시간 제한이 1초 정도라고 생각하면 된다.

  * 공간 복잡도를 표기할 때는 일반적으로 MB 단위로 표기한다.
    - int a[1000] : 4 KB (int 는 4byte이므로)
    - int a[1000000] : 4 MB
    - int a\[2000\]\[2000\] : 16 MB

---

## 연결리스트

  * 연결 리스트의 필요성
    - 일반적으로 배열을 사용하여 데이터를 순차적으로 저장하고, 나열할 수 있다.
    - 배열을 사용하는 경우 메모리 공간이 불필요하게 낭비될 수 있다.

---

  * 배열 기반의 리스트
    - 데이터를 순차적으로 저장하고, 처리할 때는 배열 기반의 리스트를 간단히 이용할 수 있다.

  ```c
  #include <stdio.h>
  #define INF 1000

  int arr[INF];
  int count = 0;

  void addBack(int data){
  	arr[count] = data;
  	count ++;
  }

  void addFirst(int data){
  	for(int i = count; i >= 1 ; i--){
  		arr[i] = arr[i - 1];
  	}
  	arr[0] = data;
  	count ++;
  }

  void show(){
  	for (int i = 0; i< count ; i++){
  		printf("%d",arr[i]);
  	}
  }

  void removeAt(int index){
  	for (int i = index ; i < count -1 ; i++){
  		arr[i] = arr[i + 1];
  	}
  	count--;
  }

  int main(void){
  	addBack(5);
  	addBack(6);
  	addBack(7);
  	addFirst(3);
  	addFirst(1);
  	removeAt(1);
  	show();
  	return 0;
  }
  ```
  * 위와 같은 배열 기반 리스트의 특징
    - 배열로 만들었으므로 특정한 위치의 원소에 즉시 접근할 수 있다는 장점이 있다.
    - 데이터가 들어갈 공간을 미리 메모리에 할당해야 한다는 단점이 있다.
    - 원하는 위치로의 삽입이나 삭제가 비효율적이다. (하나하나 앞으로 밀어줘야 함)

---

## 연결 리스트
  * 일반적으로 연결 리스트는 구조체와 포인터를 함께 사용하여 구현한다.
  * 연결 리스트는 리스트의 중간 지점에 노드를 추가하거나 삭제할 수 있어야 한다.
  * 필요할 때마다 메모리의 공간을 할당 받는다.

---

## 단일 연결 리스트
  * 단일 연결 리스트는 다음과 같은 형태.
  * 포인터를 이용해 단방향적으로 다음 노드를 가리킨다.
  * 일반적으로 연결 리스트의 시작 노드를 헤드(head)라고 하며 별도로 관리한다.
  * 다음 노드가 없는 끝 노드의 다음 위치 값으로는 NULL을 넣는다.
![단일연결리스트](https://t1.daumcdn.net/cfile/tistory/2115D641533FDD5E3A)

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct Node \*next;
} Node;

Node \* head;

int main(void){
	head = (Node*)malloc(sizeof(Node));
	Node \* node1 = (Node*)malloc(sizeof(Node));
	node1 -> data = 1;
	Node \* node2 = (Node*)malloc(sizeof(Node));
	node2 -> data = 2;
	head -> next = node1;
	node1 -> next = node2;
	node2 -> next = NULL;
	Node \* cur = head->next;
  while (cur != NULL){
		printf("%d",cur->data);
		cur = cur->next;
	}
	return 0;
}
```
