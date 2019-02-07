#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
int main() {
	int N, W;
	scanf("%d%d", &N, &W);
	vector<int>v(N);
	vector<int>w(N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &v[i],&w[i]);
	}
	// dp[n+1][W+1] : 最初は全て 0
	vector<vector<int>> dp(N + 1, vector<int>(W + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= W; j++) {
			if (j + w[i] <= W) {
				// もし i 番目の品物を取れるなら、取ったときのことを考える
				dp[i+1][j + w[i]] = max(dp[i+1][j + w[i]], dp[i][j] + v[i]);
			}
			// 取らなかったときのことも考える
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		}
	}
	// 求めるのは n 番目までで重さ W 以下の場合の価値の総和の最大値
	 printf("%d\n",dp[N][W]);
	 return 0;
}






