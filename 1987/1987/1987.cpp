#include <iostream>
using namespace std;
int R, C;
int answer;
string str[20];
bool visit[26];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(pair<int, int> pos, int count)
{
	int x = pos.first;
	int y = pos.second;
	if (visit[str[y].at(x) - 'A'])
	{
		answer = max(answer, count);
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && ny >= 0 && nx < C && ny < R)
		{
			visit[str[y].at(x) - 'A'] = true;
			dfs(make_pair(nx, ny), count + 1);
			visit[str[y].at(x) - 'A'] = false;
		}
	}
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		cin >> str[i];
	}
	dfs(make_pair(0, 0), 0);
	cout << answer << '\n';
}