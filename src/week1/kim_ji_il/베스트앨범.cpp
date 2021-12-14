/*  # 1번 풀이 (통과)
- 문제 : [베스트 앨범]
- 접근 방식 : visual studio에서 풀었고, 중간 중간에 이렇게 푸는게 맞나? 싶어 구글링 했던 문제.
            1.먼저 출력될 장르 찾기 위해 map과 temp(vector)로 재생횟수 정렬.
            2.장르,인덱스,재생횟수를 담은 sii(hash_map) 를 문제조건 2,3에 맞게 정렬 - 구조체 comp 활용.
            3.먼저 출력될 장르 순으로 정렬되어 있는 temp 이용해서 answer에 push_back.
- 시간 복잡도 :  ?
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

struct comp {
	bool operator()(pair<int,int> a,pair<int,int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};

unordered_map <string, vector<pair<int, int>>> sii; // 장르 ,{ 인덱스, 재생횟수 }

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> m;

	for (size_t i = 0; i < genres.size(); i++) {
		m[genres[i]] = m[genres[i]] + plays[i];
		sii[genres[i]].push_back({ i,plays[i] });
	}

	vector<pair<string, int>> temp(m.begin(), m.end());

	sort(temp.begin(), temp.end(), cmp);  // temp - [pop 3100], [classic 2450]
	
	int genres_number = temp.size();  // 장르 개수.

	for (int i = 0; i < genres_number; i++) {
		sort(sii[temp[i].first].begin(), sii[temp[i].first].end(),comp()); // 문제의 2,3 조건대로 정렬.
	}

	for (int i = 0; i < genres_number; i++) {

		answer.push_back(sii[temp[i].first][0].first);

		if (sii[temp[i].first].size() >= 2) {
			answer.push_back(sii[temp[i].first][1].first);
		}
		
	}	
	return answer;
}