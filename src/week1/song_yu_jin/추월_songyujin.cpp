#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
	int n;
	unordered_map<string, int> in;
    
	cin >> n;
	for (int i=0; i<n; i++) {
		string number;
		cin >> number;
		in[number] = i;
	}

    vector<string> out(n);
    for (int i=0; i<n; i++) {
		string number;
		cin >> number;
		out[i] = number;
	}

    for (int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if (in[out[i]] > in[out[j]]) {
                answer++;
                break;
            }
        }
    }


	cout << answer << "\n";

	return 0;
}