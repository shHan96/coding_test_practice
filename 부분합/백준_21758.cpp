#include <iostream>
using namespace std;
int N;
int S[100001] = { 0, };
int A[100000];
int main() {
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		S[i + 1] = S[i] + A[i];
	}
	for (int i = 2; i < N; i++)
	{
   	// 꿀이 i번째 있고 양 끝에 벌이 있는 경우
		int a = S[i] - S[1]; // 왼쪽 끝 벌
		int b = S[N - 1] - S[i - 1]; // 오른쪽 끝 벌
		if (answer < a + b)
			answer = a + b;
       // 꿀이 왼쪽 끝에 있는 경우
		a = S[i - 1] - S[0];  // i번째 벌
		b = S[N - 1] - A[i - 1]; // 오른쪽 끝벌
		if (answer < a + b)
			answer = a + b;
       // 꿀이 오른쪽 끝에 있는 경우
		a = S[N] - S[1] - A[i - 1]; //왼쪽 끝벌
		b = S[N] - S[i]; // i번째 벌
		if (answer < a + b)
			answer = a + b;
	}
	cout << answer << endl;

	return 0;
}