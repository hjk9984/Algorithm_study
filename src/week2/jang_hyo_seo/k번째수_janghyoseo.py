def solution(array, commands):
    answer = []
    for command in commands:
        # commands에 있는 command(i, j, k)를 뽑는다.
        i, j, k = command[0], command[1], command[2]
        a = array[i-1:j] # array에서 슬라이싱을 하고 
        a.sort() # 정렬하고
        answer.append(a[k-1]) # 인덱싱한다
    return answer