#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	int age;
	string name;
	vector<pair<int, pair<int, string>>> member;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		member.push_back(make_pair(age, make_pair(i, name)));
	}
	sort(member.begin(), member.end());
	for (int i = 0; i < N; i++)
	{
		cout << member[i].first << " " << member[i].second.second << "\n";
	}
}