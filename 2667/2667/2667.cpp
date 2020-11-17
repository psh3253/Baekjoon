#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, house;
int map[25][25] = { 0, };
bool visit[25][25] = { false, };
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };

void dfs(pair<int, int> p)
{
	int x = p.first;
	int y = p.second;
	if (visit[y][x])
		return;
	visit[y][x] = true;
	house++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dirX[i];
		int ny = y + dirY[i];
		if (map[ny][nx] == 1 && !visit[ny][nx] && nx > -1 && ny > -1 && nx < n && ny < n)
				dfs(make_pair(nx, ny));
	}
}

int main(void)
{
	vector<int> houseCount;
	int complex = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	// 행
	{
		for (int j = 0; j < n; j++)	// 열
		{
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++)	// 행
	{
		for (int j = 0; j < n; j++)	// 열
		{
			if(map[i][j] == 1 && !visit[i][j])
			{
				complex++;
				house = 0;
				dfs(make_pair(j, i));
				houseCount.push_back(house);
			}
		}
	}
	sort(houseCount.begin(), houseCount.end());
	cout << complex << endl;
	for(int i=0; i<complex; i++)
	{
		cout << houseCount[i] << endl;
	}
}