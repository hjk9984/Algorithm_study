# Heap

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbm4BhE%2FbtqCJmldPZk%2F56CvdNjSO51RJYnfcmzA10%2Fimg.png)

### 개념

최댓값과 최솟값을 빠르게 찾기 위해 고안된 자료구조

- 각 노드의 key값이 해당 노드의 자식노드의 key값보다 작지 않거나 크지 않은 완전 이진트리

- 키 값의 대소관계는 부모-자식 노드 사이 간에만 성립하며 형제 노드 사이에는 영향을 미치지 않음

- 자식노드의 최대 개수는 힙의 종류에 따라 다르지만 이진트리에서는 최대 2개 (완전이진트리를 사용한다고 가정하자.)

- i번째 노드의 자식노드가 2개인데 왼쪽 자식노드는 2i, 오른쪽 자식노드는 2i+1이고, 부모노드는 i/2가 된다.

### 종류

- ##### 최대 힙 (max heap)

- 각 노드의 키 값이 그 자식노드의 키 값보다 작지 않은 힙

- key(T.parent(v)) > key(v)
 
- ##### 최소 힙 (min heap)

- 노드의 키 값이 그 자식노드의 키 값보다 크지 않은 힙

- key(T.parent(v)) < key(v)

 
### 구성요소

- ##### 삽입 연산 (insertion)

- 삽입하고자 하는 값을 트리의 가장 마지막 원소에 추가한다.


- 부모노드와의 대소관계를 비교하면서 만족할 때까지 자리 교환을 반복한다.

- ##### 삭제 연산 (deletion)

- 힙에서는 루트 노드만 삭제가 가능하므로 루트 노드를 제거한다.

- 가장 마지막 노드를 루트로 이동시킨다.

- 자식노드와 비교하여 조건이 만족할 때까지 이동시킨다.


### 시간복잡도

- O(log n)

### heapq 모듈

- 파이썬에서 제공하는 힙큐 모듈, 일반적인 리스트를 min heap처럼 다룰 수 있게 해줌

- ##### 모듈 임포트

import heapq

- ##### 노드 추가 : heappush 메소드를 이용

heap = [] 

heapq.heappush(heap, 1)

- ##### 노드 삭제 : heappop 메소드 이용

가장 작은 원소를 꺼내어 리턴, 자동적으로 그 다음으로 작은 원소가 루트노트가 됨

return heapq.heappop(heap)

- 최소값을 꺼내지 않고 리턴만 하려면 인덱스로 접근하기

print(heap[0])

주의할 점 : 인덱스 1이 2번째로 작다는 보장은 없으므로 n번째로 작은 원소를 얻고 싶다면 n-1개의 원소를 빼내야 함.

- ##### 기존에 사용한 리스트를 힙으로 변환하기 : heapify 메소드 이용

시간복잡도는 O(n)

tmp = [7, 5, 8, 3]

heapq.heapify(tmp)

- ##### 최대 힙 만들기 : 우선순위가 포함된 튜플 이용하기

import heapq

nums = [4, 1, 7, 3, 8, 5]

heap = []

for num in nums:

  heapq.heappush(heap, (-num, num))  # (우선 순위, 값)

while heap:

  print(heapq.heappop(heap)[1])  # index 1
