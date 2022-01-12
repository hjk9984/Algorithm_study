# DFS


DFS 란 단어 뜻 그대로 깊이 우선 탐색이라는 뜻이다.

우선 DFS는 두 가지 정보를 우리가 알아야한다.

![logo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FzpBOM%2FbtrkqHBg3om%2FRQI24miYNBTPDVtQsUJokK%2Fimg.png)


위의 그림에서 D를 방문하고 H를 방문했다고 하자.

다음에는 어디로 가야 할까?

두 정보가 필요하다.


① 전에 방문한 정점(vertex)을 알아야 한다.
따라서 각 정점(vertex)의 방문 여부를 저장하는 자료구조가 필요하다.

- 한번 방문한 정점(vertex)이라면 들릴 필요가 없다.


② 더이상 방문 할 정점이 없으면 이전의 정점으로 돌아가야 합니다. ( 이전 정점의 정보를 알고 있어야 한다. )

- 위 DFS 예시에서 나오는거 처럼 H 의 자식노드가 없어 더이상 갈곳이 없다면 그 전 노드로 돌아가 방문하지 않은 i 노드를 방문해야한다.

 
이 두 가지를 충족시키는 방법은  Stack 자료구조를 사용하거나 재귀함수 를 이용하는 것이다.


----

## [ Recursion 이용한 DFS 구현 ]

``` c++
#include<iostream>
#include<vector>
 
using std::endl;
using std::cout;
 
const int adjacent2_size=7;  // 주어진 그래프의 vertex 개수
std::vector<std::vector<int>> adjacent = { 7 ,std::vector<int>(7,0)} ;  // 인접행렬의 표현 (V x V) 행렬
std::vector<bool> visited(adjacent2_size, false);
// 0 번 인덱스도 사용.
 
//  ==========================================================
//  < 1. Adjacency Matrix > 로 그래프를 표현했을때 DFS 
void DFS(int here) {     
 
	cout << "visit " << here << '\n';
	visited[here] = true;
 
	for (int i = 0; i < adjacent2_size; i++) {
		if (adjacent[here][i] != 0 && !visited[i]) {
 
			DFS(i);
		}
	}
}
```

```c++
//  ==========================================================
//   < 2. Adjacency list > 로 그래프를 표현했을때 DFS 
 
// 0 index는 안쓰고 1번 부터 쓸거기 때문에 +1 할당할때 +1을 하여 할당해준다.
std::vector<std::vector<int>> adjacent2(9); // 행이 9행인 2차원 vector 생성 / 열은 가변적.
std::vector<bool> visited2(adjacent2.size(), false);
 
 
void DFS2(int here) {
 
	visited2[here] = true;
	cout << "visit2 : " << here << '\n';
 
	for (int i = 0; i < adjacent2[here].size(); i++) {
		int next = adjacent2[here][i];
		if (!visited2[next]) {
			DFS2(next);
		}
	}
}
 ```

여기서 주의할 점은 !!


한번의 DFS로 모든 노드가 순회 된다는 보장은 없기 때문에 

모든 노드를 방문하여야 된다면, DFS를 한번 돌고 방문하지 않은 노드를 찾아서 DFS를 다시 실행 시켜줘야 된다.

 
```c++
for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
            //  인접 행렬로 표현했을때 행에서 1이 1개라면 자기 자신 말고는 인접한 노드가 없는 것이다.
			if (std::count(adjacent[i].begin(), adjacent[i].end(), 1) > 1) {  	
				Dfs(i);
			}
		}
	}
```
## [ Stack을 이용한 DFS 구현 ]

```c++ 
( 작은 노드 부터 실행하기 위해 sort 를 해주었다. )

std::vector<int> adj_list[10];
bool visited[10] = { false, };
std::stack<int> st;
 
// 인접 리스트로 구하기.
void DFS(int start) {
	st.push(start);
	visited[start] = true;
	std::cout << start << " ";
 
	while (!st.empty()) {
		int cur = st.top();
 
		st.pop();
 
		std::sort(adj_list[cur].begin(), adj_list[cur].end());
 
		for (size_t i = 0; i<adj_list[cur].size(); i++) {
 
			int next = adj_list[cur][i];
 
			if (!visited[next]) {
				st.push(cur);  < 위에서 pop()을 해줬기 때문에 cur를 다시 push 해준다.
				st.push(next);
				std::cout << next << " ";
				visited[next] = true;
				break;
			}
		}
	}
}
```


----

# BFS


BFS 란 단어 뜻 그대로 깊이 우선 탐색이라는 뜻이다.


DFS와 구현방법은 비슷하지만 결과는 확연히 다르다.

![logo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FzpBOM%2FbtrkqHBg3om%2FRQI24miYNBTPDVtQsUJokK%2Fimg.png)

 

마찬가지로 BFS를 구하기 위해 필요한 정보부터 알아보자.


① 전에 방문한 정점(vertex)을 알아야 한다. 따라서 각 정점(vertex)의 방문 여부를 저장하는 자료구조가 필요핟.

- 한번 방문한 정점(vertex)이라면 들릴 필요가 없다.

 

이 BFS는 DFS보다 간단하게 구현이 가능하다. 

 

Queue 자료구조 를 사용한다.



----

## [ Queue 이용한 BFS 구현 ]

``` c++
#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;
 
vector<vector<int>> adjacent{ 9 };
vector<bool> visited(9,false);
queue<int> q;
 
void BFS(int start) {
	q.push(start);
	cout << "Visit : " << start << endl;
	visited[start] = true;
	
	while (!q.empty()) {
		auto next = q.front();	
		q.pop();
 
		for (int i = 0; i < adjacent[next].size(); i++) {
			if (!visited[adjacent[next][i]]) {
				q.push(adjacent[next][i]);
				cout << "Visit : " << adjacent[next][i] << endl;
				visited[adjacent[next][i]] = true;
			}
		}		
	 }
}
void initMarks() {
	for (auto elem : visited) {	
		elem = false;
	}
}
void BFS() {
	BFS(0);
}
```

