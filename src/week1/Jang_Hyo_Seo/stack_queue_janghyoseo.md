# Stack

![image](https://blog.kakaocdn.net/dn/eJXlhV/btqCIEOloxQ/5Kfl9PdVKpbWk7ldKV7La1/img.png)

### 개념

가장 나중에 쌓은 데이터를 가정 먼저 뺄 수 있는 데이터 구조이다. LIFO(Last-In, First-Out)방식을 사용한다.


### 구성요소

- ##### push()

  데이터를 스택에 쌓는 기능을 의미한다. python list의 append 메소드와 같다.

- ##### pop()

  데이터를 스택에서 꺼내는 기능을 의미한다. python list에 같은 기능이 있다.

  data_stack = list()
  
  data_stack.append(1) # [1]
  
  data_stack.append(2) # [1 2]
  
  data_stack.pop() # 2 출력

##### 장점

구조가 단순하고, 구현이 쉽다.
데이터 저장/불러오는 속도가 빠르다. 

##### 단점

데이터 최대 갯수를 사전에 정해주어야 한다. (python 재귀 함수는 1000번까지 가능)
저장 공간 낭비가 발생할 수 있다. (미리 최대 갯수를 넣을 공간을 확보하기 때문)


# Queue

![image](https://blog.kakaocdn.net/dn/xXlwr/btqCKAxDjvV/w2Ka83zVLTsUOGLS4rmmSK/img.png)

### 개념

먼저 넣은 데이터를 가장 먼저 꺼는 데이터 구조이다.
FIFO(First-In, First-Out : 선입선출) 또는 LILO(Last-In, Last-Out) 방식을 사용한다.


### 구성요소

- ##### Enqueue

  큐에 데이터를 넣는 기능을 의미한다. python list의 append() 메서드와 유사하다.
  
- ##### Dequeue 

  큐에서 데이터를 꺼내는 기능을 의미한다. python list의 pop(0) 메소드와 유사하다.


### 종류

- ##### Queue()

  일반적인 큐 자료구조

  import queue
  
  data_queue = queue.Queue() 
  
  data_queue.put(1) # 1 
  
  data_queue.put(2) # 1 - 2 
  
  data_queue.put(3) # 1 - 2 - 3 
  
  data_queue.get() # 1 출력 
  
  data_queue.get() # 2 출력

- ##### LifoQueue()

  나중에 입력된 데이터가 먼저 출력되는 구조 (Stack과 동일)
  
  data_queue = queue.LifoQueue() 
  
  data_queue.put(1) # 1 
  
  data_queue.put(2) # 2 - 1 
  
  data_queue.put(3) # 3 - 2 - 1 
  
  data_queue.get() # 3 출력 
  
  data_queue.get() # 2 출력
  
   
- ##### PriorityQueue()

  데이터마다 우선순위를 지정하여, 정렬된 큐로, 우선순위 높은 순으로 출력하는 자료 구조

  data_queue = queue.PriorityQueue() 
  
  data_queue.put((10, 1)) # (10, 1) 
  
  data_queue.put((5, 2)) # (5, 2) - (10, 1) 
  
  data_queue.put((15, 3)) # (5, 2) - (10, 1) - (15,3) 
  
  data_queue.get() # (5, 2) 출력 
  
  data_queue.get() # (10, 1) 출력

