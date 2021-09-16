#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int N, movie_count = 0;
	cin >> N;
	for (int i = 1; i <= 10000000; i++)
	{
		if (to_string(i).find("666") != string::npos)
			movie_count++;
		if (movie_count == N)
		{
			cout << i << endl;
			return 0;
		}
	}
}