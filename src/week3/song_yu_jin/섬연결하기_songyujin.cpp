//탐욕법
//https://programmers.co.kr/learn/courses/30/lessons/42861

//풀이법 검색하여 해결
//신장 트리(Spanning Tree) : 그래프 내의 모든 정점들을 포함하는 그래프의 부분집합 트리
//최소 신장 트리(Minimum Spanning Tree) : 가중치가 있는 그래프에서 최소 가중치를 가진 신장 트리
//최소 신장 트리를 구하는 대표적인 알고리즘 : Prim 알고리즘과 Kruskal 알고리즘

//크루스칼 알고리즘의 동작 원리
//  1. 모든 간선들의 가중치를 오름차순으로 정렬한다.
//  2. 가중치가 가장 작은 간선을 선택한다.
//  3. 2에서 선택한 간선이 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 2개의 노드를 서로 연결한다.
//  4. 위의 과정을 반복한다.

//해당 문제는 크루스칼 알고리즘로 풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
int Parent[100];
vector<pair<int, pair<int, int>>> Edge;
 
int Find_Parent(int A)
{
    if (A == Parent[A]) return A;
    return Parent[A] = Find_Parent(Parent[A]);
}
 
bool Same_Parent(int A, int B)
{
    A = Find_Parent(A);
    B = Find_Parent(B);
    if (A == B) return true;
    return false;
}
 
void Union(int A, int B)
{
    A = Find_Parent(A);
    B = Find_Parent(B);
    Parent[B] = A;
}
 
int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    for (int i = 0; i< n; i++) Parent[i] = i;
    for (int i = 0; i < costs.size(); i++)
    {
        int Node1 = costs[i][0];
        int Node2 = costs[i][1];
        int Cost = costs[i][2];
        Edge.push_back(make_pair(Cost, make_pair(Node1, Node2)));
    }
    sort(Edge.begin(), Edge.end());
    for (int i = 0; i < Edge.size(); i++)
    {
        int Cost = Edge[i].first;
        int Node1 = Edge[i].second.first;
        int Node2 = Edge[i].second.second;
 
        if (Same_Parent(Node1, Node2) == false)
        {
            Union(Node1, Node2);
            answer = answer + Cost;
        }
    }
    return answer;
}



