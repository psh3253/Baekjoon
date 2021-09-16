#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int result[1000001];

int main(void)
{
	vector<int> v;
	stack<int> st;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = v.size() - 1; i > -1; i--)
	{
		while (!st.empty() && st.top() <= v[i])
			st.pop();
		if (st.empty())
			result[i] = -1;
		else
			result[i] = st.top();
		st.push(v[i]);
	}
	for(int i = 0; i < v.size(); i++)
	{
		cout << result[i] << ' ';
	}
	cout << '\n';
}