#include <iostream>
#include <vector>
using namespace std;
int person[51];
vector<int> party[50];

int get_parent(int x)
{
	if (person[x] == x)
		return x;
	return person[x] = get_parent(person[x]);
}

void union_parent(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	if (x_parent < y_parent)
		person[y_parent] = x_parent;
	else
		person[x_parent] = y_parent;
}

int main(void)
{
	int answer = 0;
	int N, M;
	int truth_person_count;
	cin >> N >> M;
	cin >> truth_person_count;
	for (int i = 1; i < N + 1; i++)
		person[i] = i;
	for(int i = 0; i < truth_person_count; i++)
	{
		int truth_person;
		cin >> truth_person;
		union_parent(0, truth_person);
	}
	for(int i = 0; i < M; i++)
	{
		int party_count;
		cin >> party_count;
		for (int j = 0; j < party_count; j++)
		{
			int party_member;
			cin >> party_member;
			party[i].push_back(party_member);
			if(j >= 1)
			{
				union_parent(party[i][j - 1], party[i][j]);
			}
		}
	}
	for(int i = 0; i < M; i++)
	{
		bool is_include_truth = false;
		for(int j = 0; j < party[i].size(); j++)
		{
			if (get_parent(party[i][j]) == 0)
				is_include_truth = true;
			break;
		}
		if (!is_include_truth)
			answer++;
	}
	cout << answer << '\n';
}