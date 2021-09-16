#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	deque<int> dq;
	int N, num;
	string command;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "pop_front")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (command == "pop_back")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (command == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (command == "empty")
		{
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "front")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';
			}
		}
		else if (command == "back")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}
}