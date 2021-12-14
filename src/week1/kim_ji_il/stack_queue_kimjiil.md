# Stack

스택은 자료구조 중 하나로 LIFO(Last In First Out) 구조를 가지고 있다.

### Defined in header <queue>


` template
< class T, class Container = std::deque<T> >
class stack;
`


> 내부적으로는 vector ,deque, list container 의 구조로 구현되어 있고, stack과 같이 작동하도록 인터페이스들을 제공


![logo](https://media.vlpt.us/images/sbinha/post/17a3cf61-fb95-4970-b66c-92a71b99846b/Screenshot%202020-04-20%2019.07.55.png)


- 역추적, 괄호 검사, 후위 표기법 등등 에 자주 사용.

* 스택의 중요 함수
    * bool empty() cosnt
    * size_type size() const
    * const value_type top() const
    * void push(const value_type& val)
    * void pop()




스택을 이해하는데 도움이 될 만한 문제.

- 기본

    [BOJ_2504 괄호의 값](https://www.acmicpc.net/problem/2504)

    [BOJ_10799 쇠막대기](https://www.acmicpc.net/problem/10799)

- 응용

    [BOJ_17298 오큰수](https://www.acmicpc.net/problem/17298)

    [BOJ_6198 옥상 정원 꾸미기](https://www.acmicpc.net/problem/6198)


****
# Queue

Stack 과 다르게 FIFO 의 방식으로 동작된다.

### Defined in header <queue>

` template<
    class T, class Container = std::deque<T> >
    class queue; `

> 내부적으로는 deque, list container 의 구조로 구현되어 있고, stack과 같이 작동하도록 인터페이스들을 제공  

![logo](https://media.vlpt.us/images/sbinha/post/dbc199b3-6959-464e-872d-39c503fa0b1b/Screenshot%202020-04-20%2019.19.59.png)


* 큐의 중요 함수
    * bool empty() cosnt
    * size_type size() const
    * value_type front() const
    * value_type back() const
    * void push(const value_type& val)
    * void pop()

- 기본

    [BOJ_1158 요세푸스](https://www.acmicpc.net/problem/1158)

    [BOJ_1966 프린터 큐](https://www.acmicpc.net/problem/1966)