# Heap
힙은 최댓값 및 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된 완전이진트리를 기본으로 한 자료구조다. 최댓값 혹은 최솟값을 O(logN)에 찾을 수 있다. (일반 배열은 O(N)). 

## Max Heap   
최대 힙은 완전 이진트리의 root 부분에 최댓값이 항상 존재한다. 

## Min Heap
최소 힙은 완전 이진트리의 root 부분에 최솟값이 항상 존재한다.       

# Priority queue
힙 자료구조롤 응용한 대표적인 사례가 우선순위 큐이다. 우선순위 큐는 우선순위를 순차적으로 가져올 수 있는 push/pop이 가능한 자료로 꼭 힙으로 구현할 필요는 없지만 힙으로 구현하는 것이 시간복잡도 면에서 큰 효율을 낼 수 있기 때문에 주로 힙으로 구현한다.

우선순위 큐는 기본적으로 Max Heap, 즉 원소를 pop하면 큰 수부터 내림차순으로 된다. 오름차순으로 하고 싶은 경우에는 원소에 전체적으로 음수를 취해주거나 우선순위 큐를 선언함에 있어 인자를 넣어 Min Heap을 만들어 주면 된다.

## 사용법
우선순위 큐의 사용법은 일반 큐와 동일하지만 front 대신에 top을 쓴다는 차이점이 있다. 
 	
    //Max Heap
	priority_queue<int> p_qu_l;
	p_qu_l.push(1);
	p_qu_l.push(9);
	p_qu_l.push(5);
	sz = p_qu_l.size();
	for(int i=0;i<sz;i++){
		cout << p_qu_l.top() << ',';
		p_qu_l.pop();
	}cout << '\n';
	--> 9, 5, 1,

    //Min Heap
	priority_queue<int, vector<int>, greater<int>> p_qu_g;
	p_qu_g.push(1);
	p_qu_g.push(9);
	p_qu_g.push(5);
	sz = p_qu_g.size();
	for(int i=0;i<sz;i++){
		cout << p_qu_g.top() << ',';
		p_qu_g.pop();
	}cout << '\n';
    --> 1, 5, 9,

우선순위 큐는 특히 pair와 함께 사용되는 경우가 많은데 비교 우선순위는 pair의 첫번째 요소로 먼저 비교하고 같은 경우 그 두번째 요소로 비교하는 방식이다.

    //pair를 사용한 우선순위 큐
    priority_queue<pair<int,int>> temp;
	temp.push(make_pair(3,100));
    temp.push(make_pair(-2,140));
	temp.push(make_pair(3,50));
	temp.push(make_pair(49,12));
	temp.push(make_pair(300,-20));
	int sz = temp.size();
	for(int i=0;i<sz;i++){
		cout << temp.top().first << ',' << temp.top().second << '\n';
		temp.pop();
	}
    --> 300, -20
        49, 12
        3, 100
        3, 50
        -2, 140