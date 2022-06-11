#include <iostream>
#include <stack>
using namespace std;
int memo[1001][1001];
stack<char> st;

int main(void)
{
	char answer[1000];
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	for(int i = 1; i < str2.size() + 1; i++)
	{
		for(int j = 1; j < str1.size() + 1; j++)
		{
			if(str1[j-1] == str2[i-1])
			{
				memo[i][j] = memo[i-1][j - 1] + 1;
			}
			else
			{
				memo[i][j] = max(memo[i-1][j], memo[i][j - 1]);
			}
		}
	}
	int y = str2.size();
	int x = str1.size();
	while(memo[y][x] != 0)
	{
		if(str2[y-1] == str1[x-1])
		{
			st.push(str2[y - 1]);
			x--;
			y--;
		}
		else
		{
			if (memo[y - 1][x] < memo[y][x - 1])
				x--;
			else
				y--;
		}
	}
	int idx = 0;
	while (!st.empty())
	{
		answer[idx++] = st.top();
		st.pop();
	}
	answer[idx] = '\0';
	cout << memo[str2.size()][str1.size()] << '\n';
	cout << answer << '\n';
}