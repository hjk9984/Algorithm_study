def solution(priorities, location):
    count = 0
    while (len(priorities) != 0):
        if location == 0: #출력 여부를 확인하는 맨 앞순서로 왔을 경우
            if (priorities[0] < max(priorities)): # 더 중요도가 큰 문서가 있으면
                priorities.append(priorities.pop(0)) # 맨 뒤로 보냄
                location = len(priorities) - 1 # location을 맨 끝으로 설정(배열길이-1)
            else:
                return count + 1
        else:
            if (priorities[0] < max(priorities)):
                priorities.append(priorities.pop(0))
                location -= 1 # 맨 앞 요소가 뒤로 갔기 때문에 location이 1 줄어듦
            else:
                priorities.pop(0)
                location -= 1 # 맨 앞 요소가 출력되었기 때문에 location이 1 줄어듦
                count += 1 # 출력번째 수 + 1

    return count