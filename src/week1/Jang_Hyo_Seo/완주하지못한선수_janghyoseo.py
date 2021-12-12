def solution(participant, completion):
    
    # 1. 두 list를 sorting 한다.
    participant.sort()
    completion.sort()
    # 2. completeion list의 len만큼 participant를 찾아서 없는 사람을 찾는다
    for i in range(len(completion)):
         if participant[i] != completion[i]:
                return participant[i]
    # 3. 전부 다 돌아도 없을 경우에는 마지막 주자가 완주하지 못한 선수이다.
    return participant[-1]

