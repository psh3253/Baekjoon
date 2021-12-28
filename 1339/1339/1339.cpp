#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int alphabet_count[30];

int main(void)
{
	int answer = 0;
	int number = 9;
	string word;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		for (int j = 0; j < word.size(); j++) {
			alphabet_count[word.at(j) - 'A'] += pow(10, word.size() - j - 1);
		}
	}

	sort(alphabet_count, alphabet_count + 30, greater<>());
	for(int i = 0; i < 30; i ++)
	{
		answer += alphabet_count[i] * number--;
	}
	cout << answer << '\n';
}