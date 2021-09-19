#include <iostream>
using namespace std;
int weight[31];
int visit[31][30 * 500 + 1];
int ball[8];
int weight_count, ball_count;

void makeWeight(int index, int result)
{
	if (index > weight_count)
		return;
	if (visit[index][result])
		return;
	visit[index][result] = true;
	makeWeight(index + 1, result + weight[index]);
	makeWeight(index + 1, result);
	makeWeight(index + 1, abs(result - weight[index]));
}

int main(void)
{
	cin >> weight_count;
	for(int i = 0; i < weight_count; i++)
	{
		cin >> weight[i];
	}
	makeWeight(0, 0);
	cin >> ball_count;
	for(int i = 0; i < ball_count; i++)
	{
		cin >> ball[i];
	}
	for(int i = 0; i < ball_count; i++)
	{
		if (ball[i] > 500 * 30)
			cout << "N" << ' ';
		else if (visit[weight_count][ball[i]])
			cout << "Y" << ' ';
		else
			cout << 'N' << ' ';
	}
}