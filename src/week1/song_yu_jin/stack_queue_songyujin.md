# stack
stack은 대표적인 LIFO(Last In First Out) 구조로 마지막에 넣은 데이터가 처음으로 빠져나온다.

stack<자료형> stack  
데이터 추가하기 : stack.push(데이터)  
데이터 삭제하기 : stack.pop()
최상위 데이터 반환 : stack.top()  
사이즈 반환 : stack.size()  
빈 스택 확인 : stack.empty()  
스택의 내용 바꾸기: swap(stack1, stack2)


# queue
ueue은 대표적인 FIFO(First In First Out) 구조로 제일 처음에 넣은 데이터가 처음으로 빠져나온다. 스택과 달리 front 원소와 back 원소에 접근할 수 있다는 점이 특징이다.

queue<자료형> queue;  
데이터 추가하기 : queue.push(데이터)  
데이터 삭제하기 : queue.pop() // front 데이터 삭제
첫번째 데이터 반환 : queue.front()  
마지막 데이터 반환 : queue.back()  
사이즈 반환 : queue.size()  
빈 큐 확인 : queue.empty()  
큐의 내용 바꾸기: swap(queue1, queue2)  

