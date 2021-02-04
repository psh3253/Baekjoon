#include <iostream>
using namespace std;
int paper[500][500];
int sum;

void checkMaxSum(int N, int M)
{
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 3; j++)
		{
			temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];
			sum = max(sum, temp);
		}
	}
	for (int i = 0; i < N - 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
			sum = max(sum, temp);
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			temp = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1];
			sum = max(sum, temp);
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j];
			sum = max(sum, temp);
			temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2];
			sum = max(sum, temp);
			temp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
			sum = max(sum, temp);
			temp = paper[i][j + 2] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
			sum = max(sum, temp);

			temp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
			sum = max(sum, temp);
			temp = paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j] + paper[i + 1][j + 1];
			sum = max(sum, temp);

			temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1];
			sum = max(sum, temp);
			temp = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
			sum = max(sum, temp);
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			temp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i][j + 1];
			sum = max(sum, temp);
			temp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1];
			sum = max(sum, temp);
			temp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
			sum = max(sum, temp);
			temp = paper[i + 2][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
			sum = max(sum, temp);

			temp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
			sum = max(sum, temp);
			temp = paper[i + 1][j] + paper[i + 2][j] + paper[i][j + 1] + paper[i + 1][j + 1];
			sum = max(sum, temp);

			temp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j + 1];
			sum = max(sum, temp);
			temp = paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
			sum = max(sum, temp);
		}
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> paper[i][j];
		}
	}
	checkMaxSum(N, M);
	cout << sum << endl;
}