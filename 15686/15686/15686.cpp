#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int N, M;
int chicken_count;
int map[50][50];
int answer = 987654321;
vector<pair<int, int>> house_pos;
vector<pair<pair<int, int>, bool>> chicken_pos;

void backtracking(int r, int n)
{
	if (r == M && chicken_count == n)
	{
		int sum = 0;
		for (int i = 0; i < house_pos.size(); i++)
		{
			int temp = 987654321;
			for (int j = 0; j < chicken_pos.size(); j++)
			{
				if(!chicken_pos[j].second)
					continue;
				int distance = abs(house_pos[i].first - chicken_pos[j].first.first) + abs(house_pos[i].second - chicken_pos[j].first.second);
				temp = min(temp, distance);
			}
			sum += temp;
		}
		answer = min(answer, sum);
		return;
	}
	if (n == chicken_count)
		return;
	chicken_pos[n].second = false;
	backtracking(r, n + 1);
	chicken_pos[n].second = true;
	backtracking(r + 1, n + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				chicken_pos.push_back(make_pair(make_pair(i, j), false));
				chicken_count++;
			} else if(map[i][j])
			{
				house_pos.push_back(make_pair(i, j));
			}
		}
	}
	
	backtracking(0, 0);
	
	cout << answer << '\n';
}