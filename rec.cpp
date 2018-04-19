//再帰
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp
#include<vector>
#include<iostream>
#include<algorithm>
#define MAX_N 101
#define MAX_W 10001

using namespace std;
int n,W;
int w[MAX_N];
int v[MAX_N];

//i番目以降の荷物から重さの総和がj以下になるように選ぶ
int rec(int i, int j)
{
	int res;
	if (i == n)
	{
		//もう品物は残っていない
		res = 0;
	}
	else if (j < w[i])
	{
		//この品物は入らない
		res = rec(i + 1, j);
	}
	else
	{
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return res;
}
int main()
{
	cin >> n >> W;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> w[i];
	}
	cout << rec(0, W) << endl;
}