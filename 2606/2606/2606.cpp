#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int c = 0;
int network[101] = { 0, };
bool visit[101] = { false , };

void dfs(vector<int> v[], int x)
{
	if (network[x] != 1 || visit[x])
		return;
	visit[x] = true;
	c++;
	for (int i = 0; i < v[x].size(); i++)
	{
		dfs(v, v[x][i]);
	}
}

int main(void)
{
	vector<int> v[101];
	int computer, edge, src, dst;
	cin >> computer;
	for (int i = 1; i < computer + 1; i++)
	{
		network[i] = 1;
	}
	cin >> edge;
	for (int i = 0; i < edge; i++)
	{
		cin >> src >> dst;
		v[src].push_back(dst);
		v[dst].push_back(src);
	}
	dfs(v, 1);
	cout << c - 1 << endl;
}