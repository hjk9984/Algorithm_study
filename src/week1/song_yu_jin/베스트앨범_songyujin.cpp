//해시
//https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = plays.size();
    
    map<int, string> id_genre; //key: id(고유번호), value: genre
    map<string, int> genre_plays; //key: genre, value: plays
    map<int, int> id_plays; //key: id, value: plays
    
    for(int i=0; i<size; i++) {
        id_genre[i] = genres[i]; //0 - classic, 1 - pop, 2 - classic, 3 - classic, 4 - pop
    }   
    for(int i=0; i<size; i++) {
        genre_plays[genres[i]] += plays[i]; //classic - 1450, pop - 3100 
    }    
    for(int i=0; i<size; i++) {
        id_plays[i] = plays[i]; //0 - 500, 1 - 600, 2 - 150, 2 - 150, 3 - 800, 4 - 2500
    }
    
    //1. 속한 노래가 많이 재생된 장르를 먼저 수록
    //genre_plays map을 plays 내림차순으로 정렬해야함 = key가 아닌 value 값으로 정렬
    //map 자료구조는 기본적으로 key 값 기준 오름차순 기반 정렬되어 있다
    //그러나 map에는 정렬 함수가 따로 없어서, map -> vector 로 변환 후 정렬
    vector<pair<string, int>> genre_plays2(genre_plays.begin(), genre_plays.end());
    sort(genre_plays2.begin(), genre_plays2.end(), [] (auto &x, auto &y) {return x.second > y.second;});
    //genre_plays2 : pop - 3100, classic - 1450
    
    
    //2. 장르 내에서 많이 재생된 노래를 먼저 수록
    for (auto & [key, value] : genre_plays2) {
        map<int, int> id_plays2 ; //key: id, value: plays, 1. 조건에 해당하도록 id_plays를 장르 별로 선별
                                  //ex) 장르가 pop이면 id_plays 맵에서 pop인 id만 선별 
        for(int i=0; i< size; i++) {
            if(key == id_genre[i]) {
                id_plays2[i] = id_plays[i];
            }
        }
        
        //많이 재생된 순서로 정렬하기 위해 아래와 같이 정렬
        vector<pair<int, int>> id_plays3(id_plays2.begin(), id_plays2.end());
        sort(id_plays3.begin(), id_plays3.end(), [] (auto &x, auto &y) {return x.second > y.second;}); 
            
        //최종 답
        answer.push_back(id_plays3[0].first);
        if (id_plays3.size() > 1) {
            answer.push_back(id_plays3[1].first);            
        }
    }

    return answer;
}