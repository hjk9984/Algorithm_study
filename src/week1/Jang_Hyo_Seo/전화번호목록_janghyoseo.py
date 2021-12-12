def solution(phone_book):
    # 1. phone_book을 정렬한다.
    phone_book.sort()
    # 2. zip함수를 통해 for문을 2개 쓴 효과를 낸다.
    for a,b in zip(phone_book, phone_book[1:]):
    # 3. b가 a를 접두어로 가진다면 False를 return 한다.
        if b.startswith(a): 
            return False
    # 4. 그렇지 않다면 True를 return 한다.
    return True

# 다음은 zip함수의 예시이다.
# arr = [1, 2, 3], arr[1:] = [2, 3]의 zip의 결과는

# arr = [1, 2, 3]
# for i, j in zip(arr,arr[1:]):
#    print (i,j)
# > 1 2
# > 2 3
