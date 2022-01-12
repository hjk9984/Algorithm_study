#include<iostream>
#include<vector>
#include<unordered_set>

using std::cin; using std::cout;
using std::vector; 

vector<std::unordered_set<int>> opt; // opt[1] 은 n을 1번 사용해서 나타낼수 있는 수의 집합... opt[n] = n을 n번 사용해서 나타낼수 있는 수의 집합.

int dp(int number,int n,int answer) {
	
	opt[0].insert(0);
	opt[1].insert(n);
	if (number == n) {
		answer=1;
		return answer;
	}
	int input = n;
	for (int i = 2; i <= 8; i++) {
		for (int k = 1; k < i; k++) {
			for (std::unordered_set<int>::iterator itr = opt[i - k].begin(); itr != opt[i - k].end(); itr++) {
				for (std::unordered_set<int>::iterator itr2 = opt[k].begin(); itr2 != opt[k].end(); itr2++) {
					opt[i].insert((*itr)*(*itr2));
					opt[i].insert(*itr + (*itr2));
					opt[i].insert(*itr - (*itr2));
					if (*itr != 0) {
						opt[i].insert((*itr2) / *itr);
					}
					
				}
			}
		}
		input = input * 10 + n;
		opt[i].insert(input);
		std::unordered_set<int>::iterator itr = opt[i].find(number);
		if (itr != opt[i].end()) {
			answer=i;
			return answer;
		}
	}
	answer=-1;
	return answer;
}

int solution(int N, int number) {
    int answer=0;
    opt.resize(8+1);
    return dp(number,N,answer);
    
}