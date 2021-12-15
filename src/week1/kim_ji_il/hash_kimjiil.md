# Hash


C++ 11 이후에는 [std::unordered_map] 이라는 container가 등장했고, 기존의 std::map과 달리 해시 테이블로 구현되어 있기 때문에 자동 정렬도 없으며, 검색, 삽입 ,삭제 연산이 평균적으로 상수 시간에 가능해졌다.


## Defined in header <unordered_map>


`template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator< std::pair<const Key, T> >> class unordered_map;
`


> 내부적으로 key,value 구조인 map과 동일하며, hash를 이용하기에 key를 통한 value로의 접근이 빠르다. 



![logo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbGm0cS%2FbtqCNFEUyk9%2F2rcyQv7sG3opNYivGmS9zK%2Fimg.png)



- 해쉬 충돌 (hash collision)

    key에 비해 bucket 사이즈가 제한적이기에 key가 달라도 해시 함수가 동일한 값을 반환할 수 있다. 이때를 해쉬 충돌이라고 한다.

    해시 충돌은 불가피하며 활률을 낮춤으로서 충돌을 피하는것이 최선의 방법이다.


* 해쉬 충돌 해결 방법

    * chanining

        * 해쉬 충돌이 일어나면 value가 저장되는 공간을 vector와 같은 가변 배열로 구현하여, 충돌시 기존 value에 이어서 다음 요소에 추가하도록 하는 방법.

        * 이때 bucket의 인덱스엔 상수시간으로 접근 하지만, 해당 인덱스에 value 값이 여러개 일땐 접근에 O(n)의 시간이 소요된다.


        ![logo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F9SCxJ%2FbtqCKASz8n9%2F84uennZSvflmb2iMACab9k%2Fimg.png)


    * open addressing

        * 충돌이 발생하면 해당 인덱스가 아닌 비어 있는 인덱스로 할당하는 방법.

        * linear probing, Quadratic probing, Double hashing 의 방법이 있다.


        ![logo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FdJIE3R%2FbtqCO09GqpK%2FBBs0CLeCwntMYytbRtFDZ0%2Fimg.png)



* unorderd_map 의 중요 함수
    * empty()
    * size()
    * max_size()
    
    * operator[]
    * at

    * insert()
    * erase()
    * clear()
    
    * bucket_count()
    * rehash()
    * reserve()


##### 21.12-14 추가

[ std::unordered_set  erase 할 때 주의할 점 ]
```
by position (1)	 iterator erase ( const_iterator position );
by key      (2)	 size_type erase ( const key_type& k );  // erase 한 개수 리턴.
range       (3)	 iterator erase ( const_iterator first, const_iterator last );
```    




erase 하고 iterator 오류 나지 않기 위해 아래와 같이 쓰려고 했는데, 안돼서 당황했던 경험이 있다.

`itr = set.erase(key);`
    
key 를 인자로 받는 (2)의 erase는 iterator를 리턴하지 않고 원소를 몇개 지웠는지 size_type을 반환한다. (set, mulitset 도 마찬가지)


