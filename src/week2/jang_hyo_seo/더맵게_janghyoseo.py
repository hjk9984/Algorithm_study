# heapq는 가지고 있는 요소를 push, pop 할때마다 자동으로 정렬해준다.
import heapq 

def solution(scoville, K):
    heap = [] # heapq로 사용할 리스트를 초기화한다.
    for num in scoville: # 기존 리스트에 있던 요소들을 heappush로 heapq에 넣어준다. 
        heapq.heappush(heap, num)
    mix_cnt = 0 # 우선 음식을 섞은 횟수를 기록할 변수를 0으로 초기화해준다.
    while heap[0] < K: # 가장 작은 스코빌 지수가 k보다 작다면, loop을 계속 돌린다.
        try:
            heapq.heappush(heap, heapq.heappop(heap) + (heapq.heappop(heap) * 2))
        except IndexError: #error handling
            return -1
        mix_cnt += 1 # 에러가 나지 않고 무사히 계산을 끝냈다면 mix_cnt를 한 개 증가시켜준다.
    return mix_cnt