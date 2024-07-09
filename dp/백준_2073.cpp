#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001] = { 0, };
int D, P;
int L[350], C[350];
int main()
{
	cin >> D >> P;
	for (int i = 0; i < P; i++)
	{
		cin >> L[i] >> C[i];
	}
	dp[0] = (1 << 23)+1;
	for (int i = 0; i < P; i++)
	{
		for (int j = D; j >= L[i]; j--)
		{
			if (dp[j - L[i]] > 0)
			{
				dp[j] = max(dp[j], min(dp[j - L[i]], C[i]));
			}
		}
	}
	cout << dp[D] << endl;
	return 0;
}