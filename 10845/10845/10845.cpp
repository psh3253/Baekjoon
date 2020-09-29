#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<int> q;
    int n, i, m;
    string cmd;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> m;
            q.push(m);
        }
        else if (cmd == "pop")
        {
            if (q.empty())
                cout << "-1" << endl;
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << q.size() << endl;
        }
        else if (cmd == "empty")
        {
            if (q.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if (cmd == "front")
        {
            if (q.empty())
                cout << "-1" << endl;
            else
                cout << q.front() << endl;
        }
        else if (cmd == "back")
        {
            if (q.empty())
                cout << "-1" << endl;
            else
                cout << q.back() << endl;
        }
    }
}