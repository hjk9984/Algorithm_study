from collections import deque # 1. 양방향 큐 deque를 불러온다
def solution(prices):
    queue_price = deque(prices) # 2. prices list를 deque로 만들어준다
    answer = [] # 3. 가격이 안떨어지는 시간을 넣어주기 위해 answer list를 만들어준다
    while queue_price:
        sec = 0 # 4. second를 초기화해준다
        price = queue_price.popleft() # 5. deque의 왼쪽 element를 가져옴과 동시에 삭제한다
        for q in queue_price: # 6. answer에 sec를 append 해주는 과정이다
            sec += 1
            if price > q: 
                break
        answer.append(sec)
    return answer
