#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> answer;
    int count = 0;
	int T, N;

	cin >> T;

	for(int i=0; i<T; i++) {
		cin >> N;
		vector<pair<int,int> > vec;
		int a, b;
        for(int j=0; j<N; j++) {
			cin >> a >> b;
			vec.push_back(make_pair(a, b)); //a: 서류 순위, b: 면접 순위
		}
		
		sort(vec.begin(), vec.end()); //서류 시험 순위대로 오름차순 정렬
		
		int ranking = vec[0].second;
		count++; //서류 시험이 가장 좋은 지원자는 이미 합격이므로
		for(int j=1; j<N; j++) {
			if (ranking > vec[j].second) {//면접 순위가 앞의 지원자의 면접 순위보다 좋으면 합격
				count++;
				ranking = vec[j].second;
			}
		}
		answer.push_back(count);
		count = 0;
	}

	for(int i=0; i<T; i++) {
		cout << answer[i] << endl;
	}
	return 0;
}