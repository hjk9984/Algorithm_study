# Heap
최댓값 및 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된, 즉 우선순위 큐를 위해 고안된 자료구조이다. **부모노드의 키값과 자식노드의 키값 사이에 대소관계**가 성립되며, 형제노드 사이에서는 성립되지 않는다. 

**완전이진트리**를 기본으로 한다. 이진탐색트리와는 달리 중복값이 허용된다.

* Max Heap(최대힙)

    부모노드의 키값 > 자식노드의 키값
    
    가장 큰 값이 루트노드에

* Min Heap(최소힙)

    부모노드의 키값 < 자식노드의 키값

    가장 작은 값이 루트노드에

### insert 연산
**힙 트리의 성질을 유지하면서 새로운 요소를 추가해야한다!**

마지막 노드에 이어 추가한다. 자식노드와 부모노드간 대소비교 후 구조 조정에 들어간다. 정상적인 힙 트리가 될 때까지 반복한다.

### delete 연산
힙 트리에서는 루트노드의 우선순위가 가장 높으므로 루트노드를 삭제해야한다. insert 연산과 마친가지로 삭제가 이뤄진 후에도 힙트리의 성질을 유지해야 한다.

루트노드를 삭제하고 그 자리에 마지막 노드를 가져온다. 새로운 루트노드와 자식노드간의 대소비교 후 구조 조정!

-> 두 연산 모두 최악의 경우, 새로 추가된 노드가 루트노드까지 도달 / 새로운 루트노드가 가장 마지막 노드까지 도달해야하기 때문에 시간복잡도가 O(log2n)이다

### (C++ STL) priority_queue
* **push()**: 삽입
* **pop()**: top원소 삭제
* **top()**: top원소 반환
* **empty()**: true/false 반환
* **size()**: 원소의 수 반환

기본적인 사용법 
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Max Heap
    priority_queue<int, vector<int> ,less<int> > pq;

    pq.push(1);
    pq.push(9);
    pq.push(9);
    pq.push(5);
    pq.push(0);
    pq.push(5);

    pq.pop();
    pq.pop();

    cout << "Max Heap pq: ";
    while( !pq.empty() ) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

}
```
**참고한 코드**

https://kbj96.tistory.com/15
