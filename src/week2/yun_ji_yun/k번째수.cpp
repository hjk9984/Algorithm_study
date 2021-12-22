#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAX_SIZE 100

int main() {
    /* 전처리 */
    int arr[MAX_SIZE] = {1, 5, 2, 6, 3, 7, 4};
    int command[3][MAX_SIZE] = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    int cnt_arr = sizeof(arr) / sizeof(arr[0]);
    int cnt_command = sizeof(command) / sizeof(command[0]);

    vector<int> answer;
    vector<int> array(arr, arr + cnt_arr);
    vector<vector<int> > commands(cnt_command, vector<int> (3,0));
    for(int i = 0; i < cnt_command; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            // commands.push_back(command[i][j]);
            commands[i][j] = command[i][j];
        }
    }
    /* 확인용 출력
    for(int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
        cout << endl;
    }
    cout << "\n";
    for(int i = 0; i < commands.size(); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            // commands.push_back(command[i][j]);
            cout << commands.at(i).at(j) << " ";
        }
        cout << endl;
    }
    */
    /* 코드 시작 */
    for(int i = 0; i < commands.size(); i++) {
        vector<int> tmp;
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
    }

    cout << "[";
    for(int i = 0; i < answer.size(); i++) {
        if (i != answer.size() - 1) {
            cout << answer[i] << ", ";
        } else {
            cout << answer[i];
        }
    }
    cout << "]\n";
}