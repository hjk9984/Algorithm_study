import heapq

def solution(operations):
    answer = []
    heapq.heapify(answer)
    
    for i in operations:
        command, num = i.split()
        num = int(num)
        if command == 'I':
            heapq.heappush(answer, num)
        else:
            if num == 1:
                if answer:
                    answer.pop(answer.index(heapq.nlargest(1, answer)[0]))
            else:
                if answer:
                    heapq.heappop(answer)
                
    if answer:
        return [heapq.nlargest(1, answer)[0], heapq.nsmallest(1, answer)[0]]
    else:
        return [0, 0]