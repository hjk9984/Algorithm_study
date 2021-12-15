def solution(bridge_length, weight, truck_weights):
    time = 0 # 경과시간 
    bridge = [0] * bridge_length # [0, 0] 현재 다리 길이만큼
    
    while len(bridge) != 0:
        time += 1
        bridge.pop(0)
        if truck_weights:
            if sum(bridge) + truck_weights[0] <= weight: # 다리가 견딜 수 있는 무게 체크
                bridge.append(truck_weights.pop(0)) # 초마다 한칸씩 pop해주기 
            else:
                bridge.append(0)
    return time