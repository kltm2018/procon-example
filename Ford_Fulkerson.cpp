//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __popcnt
#endif
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << fixed << setprecision(10);
}
int INF = numeric_limits<int>::max();
struct edge {
	int from, to, cap, rev;//revは逆辺のindex  to:行き先,cap:容量,rev:逆(G[e.to][e.rev]で逆辺の構造体にアクセスできる。)
};
int v, e;//頂点数　辺の数
vector<vector<edge>>g;
vector<bool>used;
void add_edge(int from,int to, int cap) {
	g[from].push_back(edge{ from, to, cap, (int)g[to].size() });//g[to].size()で次の行で取得される
	g[to].push_back(edge{ to, from, 0, (int)g[from].size()-1});
}
int dfs(int v, int t, int f) {//vからtに流せる最大
	if (v == t) {//終点までたどり着いたら
		return f;
	}
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		edge &e = g[v][i];//今見ている頂点から伸びている辺を参照している(コピーではない！！)
		if (!used[e.to] && e.cap>0) {//その辺の行き先をまだ調べていなくて、辺の容量にも余裕がある
			int d = dfs(e.to, t, min(f, e.cap));//capを超えない目一杯を流す
			if (d > 0) {//流しているなら
				e.cap -= d;//流した分capから引く
				g[e.to][e.rev].cap += d;//流した分逆辺のcapを増やす
				return d;
			}

		}
	
	}
	return 0;//何も流せなかった
}
int max_flow(int s, int t) {//sからtへの最大流
	int flow = 0;
	for (;;) {
		for (int i = 0; i<used.size(); i++) {
			used[i] = false;
		}
		int f = dfs(s, t, INF);
		if (f == 0) {
			return flow;//もう何も流せないので今まで流した量の和を返す
		}
		flow += f;
	}

}
signed main(){
	int v, e;
	cin >> v >> e;
	g.resize(v);
	used.resize(v);
	for (int i = 0; i < e; i++) {
		int from, to, cap;
		cin >> from >> to >> cap;
		add_edge(from, to, cap);
	}
	cout << max_flow(0, v - 1) << endl;
	return 0;
}
