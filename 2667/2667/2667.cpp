#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, temp_house_count;
int map[25][25];
bool visit[25][25] = { false , };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int x, int y)
{
	int tx, ty;
	if (visit[y][x] || map[y][x] == 0)
		return;
	visit[y][x] = true;
	temp_house_count++;
	for (int i = 0; i < 4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx > -1 && ty > -1 && tx < N && ty < N)
			dfs(tx, ty);
	}
}

int main(void)
{
	int complex_count = 0;
	vector<int> house_count;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && map[i][j] == 1) {
				temp_house_count = 0;
				complex_count++;
				dfs(j, i);
				house_count.push_back(temp_house_count);
			}
		}
	}
	sort(house_count.begin(), house_count.end());
	cout << complex_count << endl;
	for (int i = 0; i < house_count.size(); i++)
	{
		cout << house_count[i] << endl;
	}
}