# 이분탐색(Binary Search)
정렬되어 있는 리스트에서 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 방법이며, 시작점, 끝점, 중간점을 이용하여 탐색 범위를 설정한다

## 이분탐색의 시간 복잡도
* 단계마다 탐색 범위를 2로 나누는 것과 동일하므로 연산 횟수는 log₂𝑁에 비례한다
* 예를 들어 초기 데이터 개수가 32개일 때, 이상적으로 1단계를 거치면 16개가량의 데이터만 남는다
* 이진 탐색은 탐색 범위를 절반씩 줄이며, 시간 복잡도는 𝑂(log𝑁) 을 보장한다

## 이분탐색 작동 방식
위치를 나타내는 3개의 L, R, M을 사용하여 코드를 표현한다.  
L := 탐색할 가치가 있는 범위의 왼쪽 끝 인덱스
R := 탐색할 가치가 있는 범위의 오른쪽  끝 인덱스
Result := 탐색한 X의 위치
M := (L+R) / 2  
찾으려는 데이터와 M 위치(중간점)에 있는 데이터를 반복적으로 비교한다.