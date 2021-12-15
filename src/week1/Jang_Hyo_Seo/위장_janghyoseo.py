def solution(clothes):
    # 1. 곱셈연산을 위한 answer 및 dict 초기화
    answer = 1
    dic_clothes = dict()
    
    for name, kind in clothes:
    # 2. kind가 dic_clothes에 없다면 1로 두고, 있다면 +1하기
        if kind not in dic_clothes:
            dic_clothes[kind] = 1
        else:
            dic_clothes[kind] += 1
    # > return dic_clothes  -> {"headgear":2,"eyewear":1}
    
    # 3. (val + 1) * (val + 1) ... -1 공식 적용하기
    for val in dic_clothes.values():
        answer *= (val+1)
    return answer-1