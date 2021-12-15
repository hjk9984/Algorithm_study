#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> answer;
    string str;
    string bomb;
    cin >> str >> bomb;

    //bomb 문자열의 첫번째 문자부터 비교하려니까 너무 복잡하고 잘 안됨...
    //마지막 문자가 같으면 pop 하는 형식으로 구현함
    int index = 0; //answer 의 인덱스, 중간에 pop 하기 때문에 index가 줄어드는 경우 있으므로 따로 선언
    for(int i=0; i<str.size(); i++) {
        answer.push_back(str[i]);
        if (answer[index] == bomb[bomb.length()-1]) { //현재 answer 의 문자와 bomb 의 마지막 문자가 같으면 bomb 길이만큼 answer 앞 인덱스들 하나씩 비교
            bool same = true;
            for(int j=1; j<bomb.length(); j++) {
                if(answer[index-j] != bomb[bomb.length()-1-j]) {
                    same = false;
                    break;
                }
            }
            if(same == true) {
                for (int l=0; l<bomb.length(); l++){
                    answer.pop_back();
                    index--;
                }
            }
        }
        index++;
    }

    if (answer.empty()){
        cout << "FRULA";
    } else{
        for (int i=0; i<answer.size(); i++){
            cout << answer[i];
        }
    }
    cout << "\n";

    return 0;
}
