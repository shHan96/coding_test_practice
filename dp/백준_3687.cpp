#include <iostream>
#include <algorithm>
using namespace std;
int minarray[9] = { 0,0,1,7,4,2,0,8,10 };
long long dp[101];
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i < 9; i++)
		dp[i] = minarray[i];
	dp[6] = 6;
	
	for (int i = 9; i <= 100; i++)
	{
		dp[i] = dp[i - 2] * 10 + minarray[2];
		for (int j = 3; j < 8; j++)
			dp[i] = min(dp[i], dp[i - j] * 10 + minarray[j]);
	}

	for (int test = 0; test < T; test++)
	{
		int N;
		cin >> N;
		cout << dp[N] << " ";
		if (N % 2 == 0)
		{
			for (int i = 0; i < N / 2; i++)
				cout << 1;
		}
		else
		{
			cout << 7;
			for (int i = 0; i < N / 2 - 1; i++)
				cout << 1;
		}
		cout << endl;
		
	}
	return 0;
}