// https://www.acmicpc.net/problem/1449
// silver 3
// 개인 문제: 수리공 환승

#include <iostream>
#include <algorithm>
using namespace std;

int N, L, cur = 0, ans = 0;
int map[1001] = { 0, };

int main()
{
	cin.sync_with_stdio(false);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	if (L == 1) {
		cout << N;
		return 0;
	}

	sort(map, map + N);

	for (int i = 0; i < N; i++) {
		cur = map[i];
		for (int j = 0; j < L-1; j++) {
			if (i + 1 < N) {
				if (map[i + 1] <= cur + L - 1) {
					i++;
				}
			}
		}
		ans++;
	}

	cout << ans;
    return 0;
}

