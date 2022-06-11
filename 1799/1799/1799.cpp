#include <iostream>
#include <vector>
using namespace std;

int M;
int answer[2];
int map[10][10];
bool right_up_visit[19];
bool right_down_visit[19];
void backtracking(int r, int c, int cnt, int color)
{
	if(c >= M)
	{
		r++;
		if (c % 2 == 0)
			c = 1;
		else
			c = 0;
	}
	if (r == M)
	{
		answer[color] = max(answer[color], cnt);
		return;
	}
	if (!right_up_visit[r + c] && !right_down_visit[r - c + M - 1] && map[r][c] == 1)
	{
		right_up_visit[r + c] = true;
		right_down_visit[r - c + M - 1] = true;
		backtracking(r, c + 2, cnt + 1, color);
		right_up_visit[r + c] = false;
		right_down_visit[r - c + M - 1] = false;
	}
	backtracking(r, c + 2, cnt, color);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	backtracking(0, 0, 0, 0);
	backtracking(0, 1, 0, 1);
	cout << answer[0] + answer[1] << '\n';
}