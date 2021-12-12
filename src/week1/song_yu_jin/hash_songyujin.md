# hash 자료구조

## 컨테이너의 종류
STL 컨테이너는 크게 시퀀스 컨테이너와 연관 컨테이너로 나뉜다.

시퀀스 컨테이너 : vector, list, deque 와 같이 순서 있게 자료를 보관  
연관 컨테이너 : 어떠한 key와 짝을 이루어 자료를 보관하며 만들어진 key  값을 이용해서 O(1) 시간만에 자료에 접근 가능

## 연관 컨테이너의 종류
map, set : 정렬된 상태로 자료 저장  
unordered_map, unordered_set, hash_map, hash_set : 정렬 하지 않으며 자료를 저장


## hash_map
hash_map은 해시 테이블을 자료구조로 사용하므로 많은 자료를 저장하고 있어도 검색이 빠르다. 그러나 저장한 자료가 적을 때는 메모리 낭비와 검색 시 오버헤드가 생깁니다. 컨테이너에 추가나 삭제를 하는 것은 list나 vector, deque가 hash_map보다 빠르다. 또 적은 요소를 저장하고 검색할 때는 vector나 list가 훨씬 빠를 수 있다. 

hash_map을 사용하는 경우
1. 많은 자료를 저장하고, 검색 속도가 빨라야 한다.
2. 너무 빈번하게 자료를 삽입, 삭제 하지 않는다.  
 
동작 원리

hash는 어떤 데이터를 특정 연산을 통해 특별한 값(보통 integer)으로 변환시켜주는 개념이며 이 hash 연산으로 인해 key를 통한 value로의 접근이 빠르다.(unordered_map도 기본적으로 해시맵과 동일)

## hash_map 과 unordered_map 의 차이
hash_map과 unordered_map은 유사한 컨테이너인데 hash_map은 비표준(namespace가 stdext)이고 unordered_map은 표준(namespace가 std)이다. 성능도 unordered_map이 더 우월하고 표준이므로 unordered_map 사용을 권장한다.

## unordered_map 사용법
#include <unordered_map>

std::unordered_map<자료형, 자료형>  
std::unordered_multimap<자료형, 자료형> // 중복 키를 허용  
empty() :맵이 비어있는지 확인하는 함수  
size() : 맵의 크기를 확인하는 함수  
operator [] : 맵에서 key를 통해 value를 지정하는 operator // map_name[key] = value  
find(key) : 맵에서 key에 해당하는 원소를 찾는 함수  
count(key) : 맵에서 key에 해당하는 원소의 갯수를 반환하는 함수  
insert({key, value}) : 맵에 pair<key,value> 를 추가하는 함수  
erase(key) : 맵에서 key에 해당하는 원소를 제거하는 함수  
clear() : 맵을 초기화하는 함수

## unordered_map 탐색 방법
index로 접근할 수 없고 iterator로 접근하여야 한다.  
시작 : begin(), 끝 : end()  
key : iter->first, value : iter->second  
반복문 사용 시 auto 활용 or pair< key_type, value_type > 사용