def solution(citations):
    citations.sort() # 오름차순 정렬을 한다. 
    l = len(citations) # l은 길이를 의미한다.
    for i in range (l): # 리스트의 길이 만큼 
        if citations[i] >= l-i: # h번 이상 인용된 논문이 h편 이상이면
# citations[i]는 i번 논문이 인용된 횟수
# l-i는 인용된 논문의 개수를 최댓값부터 하나씩 줄여나간 것이다. 
            return l-i
    return 0