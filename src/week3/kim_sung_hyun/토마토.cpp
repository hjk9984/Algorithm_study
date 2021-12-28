#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<math.h>
using namespace std;

struct tomato
{
	int y;
	int x;
	int h;
	int time;
};

int M, N, H;
bool check[101][101][101];
int dir[6][3] = { {-1,0,0} ,{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} }; //y,x,h
int maxTime;
queue<tomato> q;


int checkTomato() {

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				//1은 익은 토마토 -1 빈자리 0 안익은토마토
				if (!check[j][k][i])
					return -1;
			}
		}
	}
	return maxTime;
}



void bfs()
{
	while (!q.empty())
	{
		tomato temp = q.front();
		q.pop();
		maxTime = max(maxTime, temp.time);

		for (int i = 0; i < 6; i++)
		{
			int ny = temp.y + dir[i][0];
			int nx = temp.x + dir[i][1];
			int nh = temp.h + dir[i][2];

			if (ny > -1 && nx > -1 && nh > -1 && ny < N && nx < M && nh < H)
			{
				if (!check[ny][nx][nh])
				{
					check[ny][nx][nh] = true;
					tomato nTomato;
					nTomato.y = ny;
					nTomato.x = nx;
					nTomato.h = nh;
					nTomato.time = temp.time + 1;
					q.push(nTomato);
				}
			}
		}
	}
}


int main() {
	scanf("%d %d %d", &M, &N, &H);
	bool startFlag = false;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				//1은 익은 토마토 -1 빈자리 0 안익은토마토
				int value = 0;
				scanf("%d",&value);
				if (value == 1)
				{
					check[j][k][i] = true;
					tomato t;
					t.h = i;
					t.y = j;
					t.x = k;
					t.time = 0;
					q.push(t);
				}
				else if (value == -1)
					check[j][k][i] = true;
				else
					startFlag = true;
			}
		}
	}

	if (!startFlag)
		printf("0");
	else
	{
		bfs();
		printf("%d", checkTomato());
	}



}