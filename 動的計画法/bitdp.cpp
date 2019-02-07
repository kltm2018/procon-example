#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
//https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#bit-dp
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=jp
//スタート地点は固定してよかった
const int INF = 100000000;
int V, E;
int dp[(1<<15)+1][15][15];
int dist[15][15];

//int res = INF;
int rec(int bit, int v,int start) {
	if (dp[bit][v][start] != -1) {
		return dp[bit][v][start];
	}
	
	if (bit == 1<<v) {
		if (dist[start][v] == -1)return  INF;
		return dp[bit][v][v] = dist[start][v];
	}
	int res = INF;
	int prev_bit = bit & ~(1 << v);
	for (int u = 0; u < V; u++) {
		if (!(prev_bit&(1 << u)))continue;
		if ( (dist[u][v] != -1)&&res > rec(prev_bit, u,start) + dist[u][v]) {
			//cout << res << endl;
			res = rec(prev_bit, u,start) + dist[u][v];
		}
	}
	return dp[bit][v][start] = res;
}
int main() {
	scanf("%d%d", &V, &E);
	memset(dist, -1, sizeof(dist));
	memset(dp, -1, sizeof(dp));		
	for (int i = 0; i < E; i++) {
		int s, t, d;
		scanf("%d%d%d", &s, &t, &d);
		dist[s][t] = d;
	}
	int result = INF;
	for (int v = 0; v < V; ++v) {
		if (result > rec((1 << V) - 1, v,v)) {
			result = rec((1 << V) - 1, v,v);
		}
	}
	if (result == INF)printf("%d\n", -1);
	else //cout << result << endl;
	 printf("%d\n", result);
}
//dp[1000][v]=0
//dp[1111][v]