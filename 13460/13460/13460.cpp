using namespace std;
#include <iostream>
#include <queue>
struct node
{
	int rx;
	int ry;
	int bx;
	int by;
	int find_count;
};

int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int N, M;
bool is_find_answer = false;
char map[10][10];
bool visit[10][10][10][10];
pair<int, int> blue_ball;
pair<int, int> red_ball;

int bfs()
{
	queue<node> q; // x, y, 횟수
	node start_node;
	start_node.rx = red_ball.first;
	start_node.ry = red_ball.second;
	start_node.bx = blue_ball.first;
	start_node.by = blue_ball.second;
	start_node.find_count = 0;
	q.push(start_node);
	visit[red_ball.second][red_ball.first][blue_ball.second][blue_ball.first] = true;
	while (!q.empty())
	{
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int find_count = q.front().find_count;
		q.pop();
		if (find_count == 10)
			return -1;
		for (int i = 0; i < 4; i++)
		{
			bool red_exit = false;
			int red_move_count = 0;
			int red_nx = rx;
			int red_ny = ry;
			while (true)
			{
				red_nx += dx[i];
				red_ny += dy[i];
				if (map[red_ny][red_nx] == 'O')
				{
					red_move_count++;
					red_exit = true;
					break;
				}
				if (map[red_ny][red_nx] != '.')
					break;
				red_move_count++;
			}
			red_nx = rx + dx[i] * red_move_count;
			red_ny = ry + dy[i] * red_move_count;

			bool blue_exit = false;
			int blue_move_count = 0;
			int blue_nx = bx;
			int blue_ny = by;
			while (true)
			{
				blue_nx += dx[i];
				blue_ny += dy[i];
				if (map[blue_ny][blue_nx] == 'O')
				{
					blue_move_count++;
					blue_exit = true;
					break;
				}
				if (map[blue_ny][blue_nx] != '.')
					break;
				blue_move_count++;
			}
			blue_nx = bx + dx[i] * blue_move_count;
			blue_ny = by + dy[i] * blue_move_count;
			if (red_exit == true & blue_exit == false)
			{
				return find_count + 1;
			}
			else if (blue_exit == true)
				continue;
			if (red_nx == blue_nx && red_ny == blue_ny) // 같은 위치
			{
				if (red_move_count < blue_move_count)
				{
					blue_nx -= dx[i];
					blue_ny -= dy[i];
				}
				else
				{
					red_nx -= dx[i];
					red_ny -= dy[i];
				}
			}
			if (!visit[red_ny][red_nx][blue_ny][blue_nx])
			{
				node n_node;
				n_node.rx = red_nx;
				n_node.ry = red_ny;
				n_node.bx = blue_nx;
				n_node.by = blue_ny;
				n_node.find_count = find_count + 1;
				q.push(n_node);
				visit[red_ny][red_nx][blue_ny][blue_nx] = true;
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> N >> M;
	cin.clear();
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'B')
			{
				blue_ball = make_pair(j, i);
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R')
			{
				red_ball = make_pair(j, i);
				map[i][j] = '.';
			}
		}
	}
	int answer = bfs();
	if (answer == -1)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << answer << '\n';
	}
}