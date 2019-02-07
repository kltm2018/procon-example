#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
int dp[11001];
int main() {
	int N, W;//N‚Í•i•¨‚Ì”@W‚Í‰×•¨‚Ìd‚³‚ÌãŒÀ
	cin >> N >> W;
	vector<int>vs(N);
	vector<int>ws(N);
	for (int i = 0; i < N; i++) {
		cin >> vs[i] >> ws[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = W; j >= 0; j--) {
			dp[j + ws[i]] = max(dp[j + ws[i]], dp[j] + vs[i]);
		}
	}
	cout << dp[W] << endl;
	return 0;
}






