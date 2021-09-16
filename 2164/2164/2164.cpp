#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	queue<int> q;
	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
		q.push(i);
	while(q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front() << '\n';
}