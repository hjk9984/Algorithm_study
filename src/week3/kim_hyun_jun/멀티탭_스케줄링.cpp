// https://www.acmicpc.net/problem/1700
// gold 1
// 개인 문제: 멀티탭

#include <iostream>
#include <algorithm>
using namespace std;

//플러그가 남아있으면 거기를 우선적으로
//플러그가 다 차면 

int N, K, ans = 0;
int sch[101], plug[101] = { 0, };

int main()
{
	cin.sync_with_stdio(false);
	
	//입력하기
	cin >> N >> K;
	for (int i = 0; i < K; i++) 
		cin >> sch[i];

	for (int i = 0; i < K; i++) {
		bool plugin = false;

		//비어 있거나 플러그에 이미 꽂혀 있을 때
		for (int j = 0; j < N; j++) {
			if (plug[j] == 0 ||	plug[j] == sch[i]) {
				plug[j] = sch[i];
				plugin = true;
				break;
			}
		}
		if (plugin) continue;

		//뽑아야만 한다면
		int idx, device_idx = -1;
		for (int j = 0; j < N; j++) {
			int lastidx = 0;
			for (int k = i + 1; k < K; k++) {
				if (plug[j] == sch[k]) 
					break;
				lastidx++;
			}

			if (lastidx > device_idx) {
				idx = j;
				device_idx = lastidx;
			}
		}

		ans++;
		plug[idx] = sch[i];
	}

	cout << ans << "\n";
    return 0;
}

