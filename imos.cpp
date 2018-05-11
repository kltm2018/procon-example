//https://onlinejudge.u-aizu.ac.jp/#/problems/2331
//imos–@
#include<vector>
#include<iostream>
#include<algorithm>
#define MAX_N 100010
using namespace std;
long long v[MAX_N];
long long ans[MAX_N];
int main()
{
	int K;//—F’B‚Ì‘”
	cin >> K;
	for (long long i = 0; i < K; i++)
	{
		long long  a, b;
		cin >> a >> b;
		v[a] = v[a] + 1;
		v[b + 1]=v[b+1]-1;
		
	}
	for (long long i = 1; i < MAX_N ; i++)
	{
		v[i] = v[i] + v[i - 1];
	}
	long long x = 0;
	for (long long i = 0; i < MAX_N; i++)
	{
		
		if (i <= (v[i] + 1))
		{
			x = max(x, i);
		}
	}
	cout << x -1<< endl;
	
	return 0;
}
