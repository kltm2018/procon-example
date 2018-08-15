#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int INF = 100000;
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=jp
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>cs(m);
	for (int i = 0; i < m; i++) {
		cin >> cs[i];
	}
	vector<vector<int>>dp(m + 1, vector<int>(n+1,INF));
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
		
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < m; i++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (j - cs[i] >= 0) {
				dp[i + 1][j] = min({ dp[i + 1][j], dp[i][j - cs[i]] + 1, dp[i + 1][j - cs[i]] + 1});
			}
		
		}
	}
	//cout << dp[m][n] << endl;
	/*
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j] == INF) {
				cout << "INF"<<" ";
			}
			else {
				cout << dp[i][j]<<" ";
			}
		}
		cout << endl;
	}
	*/
	/*
	int ans = INF;
	for (int i = 0; i <= m; i++) {
		ans = min(ans, dp[i][n]);
	}
	cout << ans << endl;
	*/
	cout << dp[m][n] << endl;
}