//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
const int INF = numeric_limits<int>::max();
int V, E;
vector < vector<ll>>dp;
vector<vector<ll>> Warshall_Floyd(int V, vector<vector<ll>>&dp) {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dp[i][k] == INF || dp[k][j] == INF) {
					continue;
				}
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	return dp;
}
signed main() {
	cin >> V >> E;
	dp.resize(V);
	for (int i = 0; i < V; i++) {
		dp[i].resize(V);
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i == j) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		dp[from][to] = cost;
		//dp[to][from] = cost;
	}
	dp = Warshall_Floyd(V, dp);
	bool minus = false;
	for (int i = 0; i < V; i++) {
		if (dp[i][i] < 0) {
			minus = true;
		}
	}

	if (minus) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (j != 0) {
					cout << " ";
				}
				if (dp[i][j] == INF) {
					cout << "INF";
				}
				else {
					cout << dp[i][j];
				}
			}
			cout << endl;
		}
	}

}