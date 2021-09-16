#include <iostream>
#include <algorithm>
#define INF 20000000
using namespace std;
int min_distance[101][101];

int main(void)
{
	int n, m, a, b, c;
	cin >> n;
	cin >> m;
	for(int i = 1; i < n + 1; i++)
	{
		for(int j = 1; j < n + 1; j++)
		{
			if (i != j)
				min_distance[i][j] = INF;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		min_distance[a][b] = min(min_distance[a][b], c);
	}
	for(int i = 1; i < n + 1; i++)
	{
		for(int j = 1; j < n + 1; j++)
		{
			for(int k = 1; k < n + 1; k++)
			{
				if(min_distance[j][k] > min_distance[j][i] + min_distance[i][k])
				{
					min_distance[j][k] = min_distance[j][i] + min_distance[i][k];
				}
			}
		}
	}
	for(int i = 1; i < n + 1; i++)
	{
		for(int j = 1; j < n + 1; j++)
		{
			if (min_distance[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << min_distance[i][j] << ' ';
		}
		cout << '\n';
	}
}