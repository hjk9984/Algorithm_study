#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<string,int> a , pair<string,int> b){
    return a.second > b.second;    
}


bool cmpM(pair<int,int> a , pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
                
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> m;
    vector<pair<string,int>> v;
    vector<pair<int,int>> music;

    for(int i=0; i<genres.size(); i++)
    {
        m[genres[i]] += plays[i];
        music.push_back({i,plays[i]});
    }
    
    for(auto a : m)
        v.push_back({a.first,a.second});
    sort(v.begin(),v.end(),cmp);
    sort(music.begin(),music.end(),cmpM);
    
    for(int i=0; i<v.size(); i++)
    {
        int cnt = 0;
        for(int j=0; j<genres.size(); j++)
        {
            if(v[i].first == genres[music[j].first])
            {
                //cout << v[i].first << " " << music[j].first << endl;
                answer.push_back(music[j].first);
                cnt++;
            }
            if(cnt == 2)
                break;
        }
    }
    
    
    //장르별 재생횟수 정리
    //장르내 만힝 재생된 노래 재생 if(장르별정리배열[발라드] == geners[발라드)
    //고유번호 sort
   
    return answer;
}