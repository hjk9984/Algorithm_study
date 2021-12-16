/*  # 1번 풀이 (통과)
- 문제 : [추월]
- 접근 방식 : 차량 번호와 들어간 순서를 알면 나온 차량(key) 순서(value) 를 통해서 비교해 볼 수 있을것 같았다.
		예를 들어  A (1)  B (2) C (3)  D(4)  순으로 차량이 집입 했다고 하자.
		나오는 차량을 보니 D A B C 라면 D는 터널내에서 추월한 차량이다.
- 시간 복잡도 : O(n^2)
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using std::cout; using std::cin;
using std::vector; using std::string;

int n;
int cnt;

std::unordered_map<std::string, int> u_m;
vector<int> output;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {  // 진입 차량들 hash_map에 i 를 idx로 해서 집어 넣고
		string in;
		cin >> in;
		u_m.insert({ in,i });
	}    
	for (int j = 0; j < n; j++) {   // 나오는 차량들의 string을 hash_map에서 조회해서 idx를 가져오고 ouput이라는 벡터에 집어넣고
		string out;
		cin >> out;
		output.push_back({ u_m[out] });
	}

	for (int i = 0; i < n; i++) {  //    output 벡터가 4 1 3 2 라면 i=0 일때 4는 3보다 크기 때문에 추월 했다고 cnt++ 
                                    //  i=1일때  1 이라면 뒤에 1보다 작은 차가 없으니깐 추월 X 
		for (int j = i+1; j < n; j++) {
			if (output[i] > output[j]) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt;



	return 0;
}