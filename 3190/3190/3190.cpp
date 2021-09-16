#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[101][101];

int main(void)
{
	queue<pair<int, char>> q;
	queue<pair<int, int>> pos;
	int N, K, L;
	int x, y;
	int second;
	int time, direction;
	char command;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> y >> x;
		board[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> second;
		cin >> command;
		q.push(make_pair(second, command));
	}
	time = 0;
	direction = 1;
	x = 1;
	y = 1;
	board[1][1] = 2;
	pos.push(make_pair(1, 1));
	while (true)
	{
		if (!q.empty() && q.front().first == time)
		{
			if (q.front().second == 'L')
			{
				direction--;
				if (direction == -1)
					direction = 3;
			}
			else
			{
				direction++;
				if (direction == 4)
					direction = 0;
			}
			q.pop();
		}
		if (direction == 0)
		{
			if (x < 1 || y - 1 < 1 || x > N || y > N || board[y - 1][x] == 2)
				break;
			if (board[y - 1][x] == 1)
			{
				pos.push(make_pair(x, y - 1));
				board[y - 1][x] = 2;
				y--;
			}
			else
			{
				pos.push(make_pair(x, y - 1));
				board[y - 1][x] = 2;
				board[pos.front().second][pos.front().first] = 0;
				pos.pop();
				y--;
			}
		}
		else if (direction == 1)
		{
			if (x < 1 || y < 1 || x + 1 > N || y > N || board[y][x + 1] == 2)
				break;
			if (board[y][x + 1] == 1)
			{
				pos.push(make_pair(x + 1, y));
				board[y][x + 1] = 2;
				x++;
			}
			else
			{
				pos.push(make_pair(x + 1, y));
				board[y][x + 1] = 2;
				board[pos.front().second][pos.front().first] = 0;
				pos.pop();
				x++;
			}
		}
		else if (direction == 2)
		{
			if (x < 1 || y < 1 || x > N || y + 1> N || board[y + 1][x] == 2)
				break;
			if (board[y + 1][x] == 1)
			{
				pos.push(make_pair(x, y + 1));
				board[y + 1][x] = 2;
				y++;
			}
			else
			{
				pos.push(make_pair(x, y + 1));
				board[y + 1][x] = 2;
				board[pos.front().second][pos.front().first] = 0;
				pos.pop();
				y++;
			}
		}
		else
		{
			if (x - 1 < 1 || y < 1 || x > N || y > N || board[y][x - 1] == 2)
				break;
			if (board[y][x - 1] == 1)
			{
				pos.push(make_pair(x - 1, y));
				board[y][x - 1] = 2;
				x--;
			}
			else
			{
				pos.push(make_pair(x - 1, y));
				board[y][x - 1] = 2;
				board[pos.front().second][pos.front().first] = 0;
				pos.pop();
				x--;
			}
		}
		time++;
	}
	cout << time + 1 << '\n';
}