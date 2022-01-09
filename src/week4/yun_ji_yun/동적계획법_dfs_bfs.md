# Dynamic Programming
DP, 즉 동적계획법은 큰 문제를 작은 문제로 쪼개서 해결하는 방식이라는 점에서 '분할 정복법'과 비슷하다. 또한 전체 문제의 최적해가 부분 문제의 최적해들로 구성된다는 점에서 '탐욕법'과 비슷하기도 하다. 그러나 **중복되는 작은 문제, 반복되는 연산을 memozation 방식으로 해결한다**는 점에서 다른 방식들과 큰 차이가 있다.

피보나치 구현에 재귀를 활용했다면 시간복잡도는 O(2^n), 동적계획법을 활용했다면 O(n)

**->보다 효율적으로 문제를 해결할 수 있다!**
## **memozation**
한 번 해결한 문제/연산이 다시 되풀이 되지 않도록 저장해놓고 두고두고 활용하는 방식

동적계획법을 활용하는 데에는 두가지 방식이 있다. **Bottom-up 방식**과 **Top-down 방식**.

Bottom-up 방식은 직관적이어서 해결이 용이하다는 장점이 있지만 가독성이 떨어진다는 단점이 있고, Top-down 방식은 가독성이 좋다는 장점이 있지만 코드 작성이 힘들다는 단점이 있다. 

# DFS & BFS
그래프 탐색 알고리즘이다.
## DFS
깊이 우선 탐색은 해당 브랜치를 모두 탐색하고 다음 브랜치로 넘어가는 방법. 모든 노드를 방문하고자 하는 경우에 적합하다.

**스택/재귀함수**를 활용하여 구현한다.


![dfs](https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif)

## BFS
넓이 우선 탐색은 인접한 노드부터 먼저 탐색하는 방법. 최적해를 찾고자 하는 경우에 적합하다.

**큐**를 활용하여 구현한다.


![bfs](https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif)


#### 출처
https://gyoogle.dev/blog/algorithm/Dynamic%20Programming.html

https://gyoogle.dev/blog/algorithm/DFS%20&%20BFS.html