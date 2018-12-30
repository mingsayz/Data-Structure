# 자료구조

* 자료구조의 필요성
  1. 데이터를 효과적으로 저장하고, 처리하는 방법에 대해서 바르게 이해할 필요가 있다.
  2. 자료구조를 제대로 이해하지 못하면 불필요하게 메모리와 성능을 낭비할 여지가 있다.
  3. 프로그램 내에서 int형 데이터가 100만개 가량 될때 원하는 데이터를 가장 빠르게 찾도록 해주는 자료구조를 찾기 위해서

---


## 기본적인 자료구조들
  1. 선형 구조
    - 배열
    - 연결 리스트
    - 스택
    - 큐
  2. 비선형 구조
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
  ```
    int main(void){
      int a,b;
      cin >> a >> b;
      int sum = 1;
      for (int i = 0 ; i < b ; i++){
        sum *= a;
      }
      cout << sum;
    }
  ```

  * 다음 알고리즘은 O(n^2)의 시간복잡도를 가진다.
  ```
    #include <iostream.h>

    using namespace std;

    int main(void){
      int n;
      cin >> n;
      for(int i = 0; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
          cout << "*";
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
    - $$ n^2 $$ : 1,000,000번의 연산
    - n^3 : 1,000,000,000번의 연산

  > 보통 연산의 횟수가 10억을 넘어가면 1초 이상의 시간이 소요된다.

  * 시간 복잡도를 표기할 때는 항상 큰 항과 계수만 표시한다.
    - O(3n^2 + n) =
---
