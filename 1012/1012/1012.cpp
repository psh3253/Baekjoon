#include <iostream>
#include <utility>
using namespace std;

int map[50][50] = { 0, };
bool visit[50][50] = { false, };
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };

void dfs(pair<int, int> loc)
{
	int x = loc.first;
	int y = loc.second;
	if (visit[y][x])
		return;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dirX[i];
		int ny = y + dirY[i];
		if (map[ny][nx] == 1 && !visit[ny][nx] && nx > -1 && ny > -1 && nx < 50 && ny < 50)
		{
			dfs(make_pair(nx, ny));
		}
	}

}

int main(void)
{
	int T, M, N, K;
	int worm = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		// map과 visit 초기화
		worm = 0;
		for (int j = 0; j < 51; j++)
		{
			for (int k = 0; k < 51; k++)
			{
				map[j][k] = 0;
				visit[j][k] = false;
			}
		}

		// 배추 위치 설정
		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int j = 0; j < 50; j++)
		{
			for (int k = 0; k < 50; k++)
			{
				if (map[j][k] == 1 && !visit[j][k])
				{
					worm++;
					dfs(make_pair(k, j));
				}
			}
		}
		cout << worm << endl;
	}
	return 0;
}