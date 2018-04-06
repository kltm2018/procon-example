#include<vector>
#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;
long long N, K;
long long a[MAX];
long long solve()
{
	
	long long res = 0;
	long long s = 0, t = 0, seki = 1;
	for (long long i = 0; i < N; i++)
	{
		if (a[i] == 0)
		{
			res = N;
			return res;
		}
	}
	if (K == 0)
	{
		return  0;
	}
	

	for (long long i = 0; i<N; i++)
	{
		while (t < N&&seki < K)
		{
			seki = seki * a[t];
			t = t + 1;
		}

		if (seki <= K)
		{
			res = max(res, t - s);
		}
		else if (seki > K)
		{
			res = max(res, t - s - 1);
		}
		
		if (K != 1)
		{
			seki = seki / a[s];
		}
		s = s + 1;
	}
	return res;
}

int main()
{
	cin >> N >> K;


	for (long long i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	long long answer = solve();
	cout << answer << endl;




}


