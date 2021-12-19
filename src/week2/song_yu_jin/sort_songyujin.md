# 정렬
C++ STL 에서 제공하는 sort 알고리즘을 사용한다.

    #include <algorithm>

## sort 기본 형태
 * sort(start,end)를 이용하면 [start,end) 범위의 인자를 오름차순(기본값,default)으로 정렬해 준다.  
 * sort(start,end,compare)를 이용하면 사용자가 정한 함수(compare)를 기준으로 정렬을 하게 된다.  
 * sort(start,end,grearter<자료형>())를 이용하면 [start,end) 범위의 인자를 내림차순으로 정렬해 준다.

## 오름차순 정렬
    
    int iv[10] = {1,3,4,2,6,7,2,10,12,5};
    sort(iv, iv+10);	//sort(iv 배열의 시작점,iv 배열의 시작점 + 10)

## 사용자 정의 정렬

    //int 정렬 값을 내림차순으로 만드는 함수(사용자가 만든 compare 함수)
    bool compare(const int &a, const int &b) {
        if(a > b)   return true;
        else    return false;
    }
    int iv[10] = {1,3,4,2,6,7,2,10,12,5};
    sort(iv, iv+10, compare); //sort(iv 배열의 시작점,iv 배열의 시작점 + 10,사용자 지정 함수(compare))

## 내림차순 정렬

    int iv[10] = {1,3,4,2,6,7,2,10,12,5};
    sort(iv,iv+10,greater<int>()); //sort(iv 배열의 시작점,iv 배열의 시작점 + 10,greater 사용

