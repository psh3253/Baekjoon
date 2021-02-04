#include <iostream>
using namespace std;

int main(void)
{
	int E, S, M;
	int year = 1;
	cin >> E >> S >> M;
	while(true)
	{
		if((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0)
		{
			printf("%d", year);
			break;
		}
		year++;
	}
}