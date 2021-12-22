/*  # 1번 풀이 (통과)
- 문제 : 백준 18870 [ 좌표 압축 ]   https://www.acmicpc.net/problem/18870
- 접근 방식 : 
	
- 시간 복잡도 : 
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, X, cnt = 0;
vector<pair<int, int>> v, ans;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> X;
		v.push_back({ X,i }); // {Xi,기존순서}
	}

	sort(v.begin(), v.end());

	ans.push_back({v[0].second, 0});

	for (int i = 1; i < N; i++)
	{
		if (v[i-1].first == v[i].first)
		{
			ans.push_back({ v[i].second, cnt }); // {기존순서, Xi'}
		}
		else 
		{
			ans.push_back({ v[i].second, ++cnt }); // {기존순서, Xi'}
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < N; i++)
		cout << ans[i].second << " ";
}