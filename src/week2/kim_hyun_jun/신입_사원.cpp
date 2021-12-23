// silver 1
// 신입 사원
// https://www.acmicpc.net/problem/1946

//하나라도 떨어지면 선발 x
//return 선발할 수 있는 신입사원의 최대 인원 수

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct state {
	int p, f;
};

bool compare(const state& a, const state& b) {
	return a.p < b.p;
}

int T, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<state> v;
		cin >> N;
		int n1, n2;
		int cnt = 0;

		for (int j = 0; j < N; j++) {
			cin >> n1 >> n2;
			v.push_back({ n1, n2 });
		}

		sort(v.begin(), v.end(), compare);


		int bound = 987654321;
		for (auto& e : v) {
			if (e.f < bound) {
				bound = e.f;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}