//メモ化再帰
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
int dp[MAX_N + 1][MAX_W + 1];//メモ化テーブル
//i番目以降の品物から重さの総和がj以下となるように選ぶ
int rec(int i,int j)
{
	if (dp[i][j] >= 0)
	{
		//すでに調べたことがあるならばその結果を再利用
		return dp[i][j];
	}
	int res;
	if (i == n)
	{
		res = 0;
	}
	else if (j < w[i])
	{
		res = rec(i + 1, j);
	}
	else
	{
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	//結果をテーブルに記憶
	return dp[i][j] = res;
}
int main()
{
	cin >> n >> W;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> w[i];
	}
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_W; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << rec(0, W) << endl;
}