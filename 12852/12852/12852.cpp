#include <iostream>
#include <queue>
using namespace std;
bool visit[1000001];
vector<int> answer_v;

struct Node
{
	int x;
	int count;
	vector<int> v;
};

int bfs(int start)
{
	queue<Node> q;
	vector<int> vs;
	vs.push_back(start);
	q.push({ start, 0, vs});
	visit[start] = true;
	while(!q.empty())
	{
		int x = q.front().x;
		int count = q.front().count;
		if (x == 1)
		{
			vector<int> v = q.front().v;
			answer_v = v;
			return count;
		}
		if (!visit[x % 3] && x % 3 == 0)
		{
			vector<int> v = q.front().v;
			v.push_back(x / 3);
			q.push({ x / 3, count + 1, v });
			visit[x / 3] = true;
		}
		if (!visit[x % 2] && x % 2 == 0)
		{
			vector<int> v = q.front().v;
			v.push_back(x / 2);
			q.push({x / 2, count + 1, v});
			visit[x / 2] = true;
		}
		if(!visit[x-1])
		{
			vector<int> v = q.front().v;
			v.push_back(x - 1);
			q.push({ x - 1, count + 1, v });
			visit[x - 1] = true;
		}
		q.pop();
	}
}

int main(void)
{
	int N;
	cin >> N;
	cout << bfs(N) << '\n';
	for(int i = 0; i < answer_v.size(); i++)
	{
		cout << answer_v[i] << " ";
	}
	cout << '\n';
}