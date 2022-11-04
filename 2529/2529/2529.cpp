#include <iostream>
#include <string>
using namespace std;
char arr[10];
string max_answer = "0";
string min_answer = "10000000000";
char number[11] = "";
bool visit[10];

void backtracking(int cur, int n)
{
	if (cur == n + 1)
	{
		number[cur] = '\0';
		min_answer = to_string(min(stoll(min_answer), atoll(number)));
		max_answer = to_string(max(stoll(max_answer), atoll(number)));
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (cur >= 1)
		{
			if (arr[cur - 1] == '>' && number[cur - 1] <= i + '0')
			{
				continue;
			}
			else if (arr[cur - 1] == '<' && number[cur - 1] >= i + '0')
			{
				continue;
			}
			if (visit[i])
				continue;
			number[cur] = i + '0';
			visit[i] = true;
			backtracking(cur + 1, n);
			visit[i] = false;
		}
		else
		{
			number[cur] = i + '0';
			visit[i] = true;
			backtracking(cur + 1, n);
			visit[i] = false;
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	backtracking(0, n);
	cout << max_answer << '\n';
	if (min_answer.length() != n + 1)
		cout << '0';
	cout << min_answer << '\n';
}