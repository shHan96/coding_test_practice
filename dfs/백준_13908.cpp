#include <iostream>
#include <unordered_set>
using namespace std;

int N, M;
int answer = 0;
unordered_set<int> s;

void dfs(int d)
{
	if (s.size() > N-d)
		return;
	if (d == N)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (s.find(i) != s.end())
		{
			s.erase(i);
			dfs(d + 1);
			s.insert(i);
		}
		else
		{
			dfs(d + 1);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		s.insert(temp);
	}
	dfs(0);
	cout << answer << endl;
	return 0;
}