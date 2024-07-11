#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long answer = 0;
	cin >> N;
    
	for (int i = 0; i < N; i++)
		cin >> A[i];
    //정렬
	sort(A, A + N);

	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j <N-1; j++)
		{
            // 두 사람를 고른다.
			int temp = A[i] + A[j];
            //아직 안본 사람중에서 합이 0이 되는 값을 바이너리서치로 찾는다.
			int sp = lower_bound(A+(j+1), A + N, -1 * temp) - A;
			int ep = upper_bound(A+(j+1), A + N, -1 * temp) - A;

			answer +=ep-sp; //찾은 사람들만큼 더해준다.
			
		}
	}
	cout << answer<<endl;
	return 0;
}