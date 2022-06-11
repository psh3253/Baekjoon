#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, pair<string, int>> m;


string get_parent(string x)
{
	if (x == m[x].first)
		return x;
	return m[x].first = get_parent(m[x].first);
}

void union_set(string x, string y)
{
	string parent_x = get_parent(x);
	string parent_y = get_parent(y);
	if (parent_x < parent_y)
	{
		m[parent_y].first = parent_x;
		m[parent_x].second += m[parent_y].second;
	}
	else
	{
		m[parent_x].first = parent_y;
		m[parent_y].second += m[parent_x].second;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int F;
		cin >> F;
		m.clear();
		for(int j = 0; j < F; j++)
		{
			string start, end;
			cin >> start >> end;
			if (m.find(start) == m.end())
				m.insert({ start, make_pair(start, 1) });
			if (m.find(end) == m.end())
				m.insert({ end, make_pair(end, 1) });
			if(get_parent(start) != get_parent(end))
			{
				union_set(start, end);
			}
			cout << max(m[get_parent(start)].second, m[get_parent(end)].second) << '\n';
		}
	}
}