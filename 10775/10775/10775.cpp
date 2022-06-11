#include <iostream>
using namespace std;
int set[100001];
int airplane[100001];

int get_parent(int x)
{
	if (set[x] == x)
		return x;
	return set[x] = get_parent(set[x]);
}

void union_parent(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	if (x_parent < y_parent)
		set[y_parent] = x_parent;
	else
		set[x_parent] = y_parent;
}

int main(void)
{
	int answer = 0;
	int G;
	int P;
	cin >> G >> P;
	for(int i = 0; i < P; i++)
	{
		cin >> airplane[i];
	}
	for(int i = 1; i < G + 1; i++)
	{
		set[i] = i;
	}
	for(int i = 0; i < P; i++)
	{
		int parent = get_parent(airplane[i]);
		if (parent == 0)
			break;
		union_parent(parent, parent - 1);
		answer++;
	}
	cout << answer << '\n';
}