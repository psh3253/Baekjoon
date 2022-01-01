#include <iostream>
#include <algorithm>
using namespace std;
int L, C;
char arr[15];
char temp_arr[15];
bool visit[16];

void backtracking(int r, int n, int vowel_count, int consonant_count)
{
	if (n == r)
	{
		if(vowel_count >= 1 && consonant_count >= 2)
		{
			for(int i = 0; i < L; i++)
			{
				cout << temp_arr[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 0; i < C; i++)
	{
		if (r > 0 && temp_arr[r - 1] >= arr[i])
			continue;
		if (!visit[i])
		{
			int temp_vowel = vowel_count;
			int temp_consonant = consonant_count;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				temp_vowel++;
			}
			else
			{
				temp_consonant++;
			}
			temp_arr[r] = arr[i];
			visit[i] = true;
			backtracking(r + 1, n, temp_vowel, temp_consonant);
			visit[i] = false;
		}
	}
}

int main(void)
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + C);
	backtracking(0, L, 0, 0);
}