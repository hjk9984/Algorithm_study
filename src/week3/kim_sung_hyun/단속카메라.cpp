#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 진출 순서대로 정렬하기 위한 bool함수
bool comp(vector<int>& a, vector<int>& b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end(), comp);
	int camera = -30001;
	for (int i = 0; i < routes.size(); ++i) {
		if (routes[i][0] > camera) {
			camera = routes[i][1];
			++answer;
		}
	}
	return answer;
}
