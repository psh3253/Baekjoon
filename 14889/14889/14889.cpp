#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
bool visit[20];
int capability[20][20];
int start, link;
int min_difference = 2000;;

void dfs(int current_member, int member_count)
{
	if (member_count == N / 2)
	{
		start = 0;
		link = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = i; j < N; j++)
			{
				if(!visit[i] && !visit[j])
				{
					start += capability[i][j];
					start += capability[j][i];
				}
				else if(visit[i] && visit[j])
				{
					link += capability[i][j];
					link += capability[j][i];
				}
			}
		}
		min_difference = min(min_difference, abs(start - link));
		return;
	}
	for (int i = current_member + 1; i < N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(i, member_count + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> capability[i][j];
		}
	}
	dfs(0, 0);
	cout << min_difference << "\n";
}