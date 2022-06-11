#include <iostream>
#include <queue>
using namespace std;
int A, B;

int bfs(int start)
{
	queue<pair<long long, int>> q;
	q.push(make_pair(start, 1));
	while(!q.empty())
	{
		long long x = q.front().first;
		int distance = q.front().second;
		q.pop();
		if (x == B)
			return distance;
		long long nx = x * 2;
		if(nx <= B)
		{
			q.push(make_pair(nx, distance +  1));
		}
		nx = x * 10 + 1;
		if (nx <= B)
		{
			q.push(make_pair(nx, distance + 1));
		}
	}
	return -1;
}

int main(void)
{
	cin >> A >> B;
	cout << bfs(A) << '\n';
}