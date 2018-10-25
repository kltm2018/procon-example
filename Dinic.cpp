//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
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
 
struct edge {
	int from, to, cap, rev;
};
vector<vector<edge>>g;//グラフの隣接リスト表現
vector<int>level;//sからの距離(辺何本分離れているか)
vector<int>iter;//どこまで調べ終わったか
int v, e;

void add_edge(int from,int to, int cap) {//from→to　容量capの辺をグラフに追加
	g[from].push_back(edge{ from,to,cap,(int)g[to].size() });
	g[to].push_back(edge{ to,from ,0,(int)g[from].size() - 1 });
}
void dinic_bfs(int s) {//sからの最短距離(辺何本分離れているか)をbfsで計算する
	fill(level.begin(),level.end(),-1);
	queue<int>que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for(int i=0;i<g[v].size();i++){
			edge &e = g[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}
int dinic_dfs(int v, int t, int f) {//増加パスをdfsで探す
	if (v == t) {
		return f;
	}
	for (int &i = iter[v]; i < g[v].size(); i++) {//同じところを何度も通らないように枝刈りしている
		edge &e = g[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			int d = dinic_dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		dinic_bfs(s);
		if (level[t] < 0) {
			return flow;
		}
		fill(iter.begin(), iter.end(), 0);
		int f;
		while ((f = dinic_dfs(s, t, numeric_limits<int>::max())) > 0) {
			flow += f;
		}
	}
}
signed main() {
	cin >> v >> e;
	g.resize(v);
	level.resize(v);
	iter.resize(v);
	for (int i = 0; i < e; i++) {
		int from, to, cap;
		cin >> from >> to >> cap;
		add_edge(from, to, cap);
	}
	cout << max_flow(0, v - 1) << endl;
	return 0;
}

