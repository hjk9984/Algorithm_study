#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (auto e : commands) {
		int start = e[0] - 1;
		int end = e[1] - 1;
		int idx = e[2] - 1;

		vector<int> v(array.begin() + start, array.begin() + end);
		sort(v.begin(), v.end());
		answer.push_back(v[idx]);
		cout << v[idx] << endl;
	}
	return answer;
}