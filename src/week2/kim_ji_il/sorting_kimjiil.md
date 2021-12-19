
# sort


* 정렬 알고리즘

    * Quick Sort
        - 퀵소트는 하나의 피봇이 있어서 피봇보다 작은 값들을 앞으로, 큰 값들을 뒤로 보낸 다음, 다시 나뉘어진 그룹을 정렬하는 top-down 식 정렬 알고리즘이다.
    ----
    * Heap Sort
        - 힙 소트는 max-heap을 이용해서 처음에 max-heap으로 O(nlogn)으로 전체를 max-heap으로 만든 다음, Max 값을 계속 추출 O(logn) 함으로써 max-heap이 최대 값을 뽑는데 최적화 되어있는 것을 이용한다.
    ----
    * Merge Sort
        - 머지 정렬은 bottom-up으로 정렬 그룹이 2개 이하일때를 종료 조건으로 하고, 하위 그룹의 머지 정렬이 끝나면 상위 그룹에서 두 개의 그룹을 합치는 것으로 동작한다.
    ----
    * Bubble Sort
        - 버블소트는 항상 연달아 있는 2개의 값을 계속 비교해서 방울이 떠오르는 것과 유사하게 동작하는 정렬이다.
    ----
    * Selection Sort
        - 하나의 값을 선택해서 그 값이 최소(최대) 값인지 구분하여 계속 최소 값을 선택해가면서 다른 값들과 비교하는 정렬 방법이다.
    ----
    * Insertion Sort
        - 삽입 정렬은 항목을 점차적으로 정렬해나가면서 하나씩 항목을 추가해가면서 뒤에서부터 삽입 해서 정렬되는 위치까지 삽입시키는 알고리즘이다
----
  


### [ 정렬 알고리즘 시간 복잡도 ]

![logo](https://media.vlpt.us/images/kyoung-jnn/post/331bf240-9074-40e5-985e-5f809f81a8e4/image.png)



----
  
코딩 테스트에서는 정렬 함수를 구현하기 보다 STL에 있는 std::sort 함수 사용.

STL <algorithm> 에서 제공해주는 정렬 함수

### Defined in header <algorithm>

` template<typename T>
void sort(T start, T  end, Compare comp); `  


> 내부적으로 intro srt라는 정렬 방법으로 구현되어있다. 이 방법은 quick sort에 heap sort와 insertion sort를 혼합한 방식으로 최악의 경우에도 O(nlogn)의 시간복잡도를 보장해준다.


* 함수 파라미터인 first와 end는 반드시 RandomIterator 이여야 한다. 따라서 list의 경우에는 sort 함수로 정렬을 수행 할 수 없다. ( list의 경우 순차 접근 반복자)

* quick sort는 최악의 경우 O(n^2)의 시간복잡도를 가진다.

* std::sort 함수의 정렬의 default는 오름차순이다.



```
// 함수 객체를 이용한 정렬
  struct comp{
    bool operator()(int a, int b) const { return a < b; }
  } ;
  std::sort(s.begin(), s.end(), comp());
  for (auto a : s) {
    std::cout << a << " ";
  }
  std::cout << '\n';

  // 람다 함수를 이용한 정렬
  std::sort(s.begin(), s.end(), [](int a, int b) { return a > b; });
  
  for (auto a : s) {
    std::cout << a << " ";
  }

```
