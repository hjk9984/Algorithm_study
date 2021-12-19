# heap

완전 이진 트리의 일종으로 최댓값이나 최솟값을 빠르게 찾기 위해 만들어진 자료구조이다.

일종의 느슨한 정렬 상태를 유지한다.
    - 큰 값이 상위 Level / 작은 값이 하위 Level 
    - 힙 트리에서는 중복된 값을 허용한다.
    * BST( 이진 검색 트리 )에서는 중복된 값 허용 X




> 힙은 아래와 같은 성질이 있어, 배열로 구현 할때 가장 효율적이다.
    
    - 왼쪽 자식의 인덱스 = ( 부모 인덱스 ) * 2
    - 오른쪽 자식의 인덱스 = ( 부모 인덱스 ) * 2 +1
    
    
![logo](https://gmlwjd9405.github.io/images/data-structure-heap/heap-index-parent-child.png)



* Heap 의 삽입
    * 1. 새로운 노드를 heap의 마지막 노드에 이어서 삽입한다.(=배열의 마지막 idx에 원소를 추가한다.)
    * 2. 새로운 노드를 부모 노드와 비교해서 힙의 성질을 만족할때까지 반복한다. ( heapify )

* Heap 의 삭제
    * 1. 루트 노드를 삭제한다.
    * 2. 루트 노드에 힙의 가장 마지막 노드를 복사한다.
    * 3. 자식 노드로 내려가면서 힙의 성질을 만족할때까지 반복한다. ( heapify )


****
# priority Queue

우선 순위 개념을 큐에 도입한 자료구조.

### Defined in header <queue>

` template <class T, class Container = vector<T>,
  class Compare = less<typename Container::value_type> > class priority_queue; `

> 배열, 덱, 힙으로 구현이 가능하며, 이 중 힙(heap)으로 구현하는것이 가장 효율적이다.


![logo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbGZTvs%2Fbtq4SciStOA%2FjqKisQkqk8c96wJuokdDpK%2Fimg.png)


* 우선 순위 큐의 중요 함수
    * empty()
    * size()
    * top() O(1)
    * push() - O(logn)
    * pop() - O(logn) pop()자체는 O(1)이나 pop()하고 heapify O(logn)

