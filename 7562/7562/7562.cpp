#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int l;
pair<int, int> start_pos, end_pos;
int board[301][301];
bool visit[301][301];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void bfs(int start_x, int start_y)
{
	int x, y, nx, ny;
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	visit[start_y][start_x] = true;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == end_pos.first && y == end_pos.second) {
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx > -1 && ny > -1 && nx < l && ny < l && !visit[ny][nx])
			{
				q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
				board[ny][nx] = board[y][x] + 1;
			}
		}
	}
}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> l;
		fill(board[0], board[300], 0);
		fill(visit[0], visit[300], false);
		cin >> start_pos.first >> start_pos.second;
		cin >> end_pos.first >> end_pos.second;
		bfs(start_pos.first, start_pos.second);
		cout << board[end_pos.second][end_pos.first] << endl;
	}
}