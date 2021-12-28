#include <iostream>//메인 출력용
#include <string>
#include <map>
using namespace std;

//숫자만들고
//소수인지아닌지 체크

bool check[7];
map<int,int> m;

bool checknum(int num)
{
    if(num < 2)
        return false;
    for(int i=2; i<num; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

void makeNum(string num, string numbers)
{
    if(num != "")
    {
        int tmp = stoi(num);
        m[tmp]++;
    }
   // int n = stoi(num);
    //소수 검사
    for(int i=0; i<numbers.size(); i++)
    {
        if(!check[i])
        {
            check[i] = true;
            makeNum(num+numbers[i], numbers);
            check[i] = false;
        }
    }
    
}


int solution(string numbers) {
    int answer=0;
	makeNum("",numbers);
    for(auto p : m)
    {
        if(checknum(p.first))
            answer++;
    }
    return answer;
}