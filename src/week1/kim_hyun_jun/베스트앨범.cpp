// hash
// 공통 문제 베스트앨범

// return 베스트앨범에 들어갈 노래의 고유번호를 순서대로 
// 장르별 2곡씩 추가
// #song <= 10,000
// #play is unique

#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

//풀이: 비교해야하는 요소들이 많기 때문에 struct을 구현해서 풀었다.
//바로 노래를 정렬하면 기존의 인덱스를 기억하지 못하니
//고유번호를 먼저 만들어줌
//고유번호와 함께 song이라는 구조체를 만들고 이 구조체를 비교하는 함수를 만들고
//정렬을 했다. 이때 genres의 수는 최대 10,000이므로 nlogn으로도 풀 수 있다.
map<string, int> genre_count;

struct song{
    int num;
    string genre;
    int plays;
};

bool compare(const song& a, const song& b){             // n번째 원소, n+1번째 원소
    if(genre_count[a.genre] == genre_count[b.genre]){
        if(a.plays == b.plays){
            return a.num < b.num;
        }
        else
            return a.plays > b.plays;
    }
    else
        return genre_count[a.genre] > genre_count[b.genre];
}

vector<int> solution(vector<string> genres, vector<int> plays){
    vector<song> v;

    //플레이 횟수 합치기 O(n)
    for(int i=0; i<genres.size(); i++){
        genre_count[genres[i]] += plays[i];
        v.push_back({i, genres[i], plays[i]});
    }

    //합쳐서 나온 정렬된 장르 벡터 구하기 O(nlogn)
    sort(v.begin(), v.end(), compare);

    //정렬된 장르 벡터를 비교함수에 넣어서 사용하기 O(n)
    //이때 2개를 넘어가면 continue
    map<string, int> check2;
    vector<int> ans;
    for(auto& e : v){
        if(check2[e.genre] >= 2) continue;
        ans.push_back(e.num);
        check2[e.genre]++;
    }

    return ans;
}

//새로 알게된 점: 오랜만에 비교함수를 짜서 헷갈렸다.
//sort는 기본적으로 오름차순으로 정의되어있고
//비교함수는 n, n+1번째 원소가 있을 때 true를 리턴하면 두 원소를 바꾸지 않고
//false를 리턴하면 두 원소를 바꾼다.
//오름차 순은 return a.num < b.num으로 나온다.