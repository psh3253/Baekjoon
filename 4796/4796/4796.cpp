#include <iostream>
using namespace std;

int main(void)
{
	int t = 1;
	while(true)
	{
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		if(V - V / P * P > L)
			cout << "Case " << t << ": " << V / P * L + L << '\n';
		else
			cout << "Case " << t << ": " << V / P * L + V - V / P * P << '\n';
		t++;
	}
}