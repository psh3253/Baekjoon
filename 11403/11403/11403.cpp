#include <iostream>
using namespace std;
int map[100][100];
int d[100][100];

int main(void)
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				d[i][j] = map[i][j];
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < N; k++)
			{
				if (d[j][i] == 1 &&  d[i][k] == 1)
					d[j][k] = 1;
			}
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << d[i][j]  << " ";
		}
		cout << '\n';
	}
}