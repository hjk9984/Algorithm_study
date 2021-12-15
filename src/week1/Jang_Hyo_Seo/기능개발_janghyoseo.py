import math
def solution(progresses, speeds):
    answer = [] 
    
    # 1. math.ceil 을 활용해서 소요시간을 각각 구한다. (소수점 올림)
    # 2. progresses = [7, 3, 9]
    progresses = [math.ceil((100-a)/b) for a,b in zip(progresses, speeds)] 
    # 3. a에 가장 오래걸린 소요 시간의 인덱스를 저장해둔다. 우선 초기값으론 0 인덱스이다.
    a = 0 
    for i in range(len(progresses)):
        if progresses[i] > progresses[a] : 
            answer.append(i-a)
            a = i
    answer.append(len(progresses)-a)
    return answer