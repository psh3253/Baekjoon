#include <iostream>
using namespace std;
int matrix1[101][101];
int matrix2[101][101];
int result[101][101];

int main(void)
{
	int N, M, K;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> matrix1[i][j];
		}
	}
	cin >> M >> K;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < K; j++)
		{
			cin >> matrix2[i][j];
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < K; j++)
		{
			for(int k = 0; k < M; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < K; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}
}