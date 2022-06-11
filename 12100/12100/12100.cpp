#include <iostream>
using namespace std;
int N;
int answer;

bool is_promise(int boardA[20][20], int boardB[20][20])
{
	bool promise = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (boardA[i][j] != boardB[i][j])
				promise = true;
		}
	}
	return promise;
}

void backtracking(int board[20][20], int r, int n)
{
	int temp_board_up[20][20];
	int temp_board_down[20][20];
	int temp_board_left[20][20];
	int temp_board_right[20][20];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer = max(answer, board[i][j]);
		}
	}
	if (r == n)
		return;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp_board_up[i][j] = board[i][j];
			temp_board_down[i][j] = board[i][j];
			temp_board_left[i][j] = board[i][j];
			temp_board_right[i][j] = board[i][j];
		}
	}
	// 위
	for (int current_x = 0; current_x < N; current_x++)
	{
		int current_y = 0;
		for (int i = 0; i < N; i++)
		{
			if (temp_board_up[i][current_x] == 0)
				continue;
			bool is_combine = false;
			for (int j = i + 1; j < N; j++)
			{
				if (temp_board_left[j][current_x] != temp_board_left[i][current_x] && temp_board_left[j][current_x] != 0)
					break;
				if (temp_board_up[i][current_x] == temp_board_up[j][current_x] && temp_board_up[i][current_x] != 0)
				{
					temp_board_up[current_y][current_x] = board[i][current_x] * 2;
					if (current_y != i)
						temp_board_up[i][current_x] = 0;
					temp_board_up[j][current_x] = 0;
					is_combine = true;
					current_y++;
					break;
				}
			}
			if (!is_combine && temp_board_up[current_y][current_x] == 0)
			{
				temp_board_up[current_y][current_x] = temp_board_up[i][current_x];
				temp_board_up[i][current_x] = 0;
				current_y++;
			}
			else if (!is_combine && temp_board_up[current_y][current_x] != 0)
			{
				current_y++;
			}
		}
	}
	if (is_promise(board, temp_board_up))
		backtracking(temp_board_up, r + 1, n);

	// 아래
	for (int current_x = 0; current_x < N; current_x++)
	{
		int current_y = N - 1;
		for (int i = N - 1; i > -1; i--)
		{
			if (temp_board_down[i][current_x] == 0)
				continue;
			bool is_combine = false;
			for (int j = i - 1; j > -1; j--)
			{
				if (temp_board_left[j][current_x] != temp_board_left[i][current_x] && temp_board_left[j][current_x] != 0)
					break;
				if (temp_board_down[i][current_x] == temp_board_down[j][current_x] && temp_board_down[i][current_x] != 0)
				{
					temp_board_down[current_y][current_x] = board[i][current_x] * 2;
					if (current_y != i)
						temp_board_down[i][current_x] = 0;
					temp_board_down[j][current_x] = 0;
					is_combine = true;
					current_y--;
					break;
				}
			}
			if (!is_combine && temp_board_down[current_y][current_x] == 0)
			{
				temp_board_down[current_y][current_x] = temp_board_down[i][current_x];
				temp_board_down[i][current_x] = 0;
				current_y--;
			}
			else if (!is_combine && temp_board_down[current_y][current_x] != 0)
			{
				current_y--;
			}
		}
	}
	if (is_promise(board, temp_board_down))
		backtracking(temp_board_down, r + 1, n);

	// 왼쪽
	for (int current_y = 0; current_y < N; current_y++)
	{
		int current_x = 0;
		for (int i = 0; i < N; i++)
		{
			if (temp_board_left[current_y][i] == 0)
				continue;
			bool is_combine = false;
			for (int j = i + 1; j < N; j++)
			{
				if (temp_board_left[current_y][j] != temp_board_left[current_y][i] && temp_board_left[current_y][j] != 0)
					break;
				if (temp_board_left[current_y][i] == temp_board_left[current_y][j] && temp_board_left[current_y][i] != 0)
				{
					temp_board_left[current_y][current_x] = board[current_y][i] * 2;
					if (current_x != i)
						temp_board_left[current_y][i] = 0;
					temp_board_left[current_y][j] = 0;
					is_combine = true;
					current_x++;
					break;
				}
			}
			if (!is_combine && temp_board_left[current_y][current_x] == 0)
			{
				temp_board_left[current_y][current_x] = temp_board_left[current_y][i];
				temp_board_left[current_y][i] = 0;
				current_x++;
			}
			else if (!is_combine && temp_board_left[current_y][current_x] != 0)
			{
				current_x++;
			}
		}
	}
	if (is_promise(board, temp_board_left))
		backtracking(temp_board_left, r + 1, n);

	// 오른쪽
	for (int current_y = 0; current_y < N; current_y++)
	{
		int current_x = N - 1;
		for (int i = N - 1; i > -1; i--)
		{
			if (temp_board_right[current_y][i] == 0)
				continue;
			bool is_combine = false;
			for (int j = i - 1; j > -1; j--)
			{
				if (temp_board_right[current_y][j] != temp_board_right[current_y][i] && temp_board_right[current_y][j] != 0)
					break;
				if (temp_board_right[current_y][i] == temp_board_right[current_y][j] && temp_board_right[current_y][i] != 0)
				{
					temp_board_right[current_y][current_x] = board[current_y][i] * 2;
					if (current_x != i)
						temp_board_right[current_y][i] = 0;
					temp_board_right[current_y][j] = 0;
					is_combine = true;
					current_x--;
					break;
				}
			}
			if (!is_combine && temp_board_right[current_y][current_x] == 0)
			{
				temp_board_right[current_y][current_x] = temp_board_right[current_y][i];
				temp_board_right[current_y][i] = 0;
				current_x--;
			}
			else if (!is_combine && temp_board_right[current_y][current_x] != 0)
			{
				current_x--;
			}
		}
	}
	if (is_promise(board, temp_board_right))
		backtracking(temp_board_right, r + 1, n);
}

int main(void)
{
	int board[20][20];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	backtracking(board, 0, 5);
	cout << answer << '\n';
}