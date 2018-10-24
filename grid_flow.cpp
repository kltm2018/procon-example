#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define for(i, a, b) for(ll (i)=a;(i)<(b);++(i))
#define rep(i, n)    for(i, 0, n)
#define MAX_V        20004

const ll inf = 1e15;
const ll mod = 1e9 + 7;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

struct edge {
	ll to, cap, rev;
	edge(ll t, ll c, ll r) : to(t), cap(c), rev(r) {}
};

vector<edge> G[MAX_V];
ll level[MAX_V];
ll iter[MAX_V];

void add_edge(ll from, ll to, ll cap) {
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}

void bfs(ll s) {
	memset(level, -1, sizeof(level));
	queue<ll> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		ll v = que.front(); que.pop();
		rep(i, G[v].size()) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

ll dfs(ll v, ll t, ll f) {
	if (v == t) return f;
	ll &i = iter[v];
	while (i < G[v].size()) {
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			ll d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
		i++;
	}
	return 0;
}

ll max_flow(ll s, ll t) {
	ll flow = 0;
	while (true) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		ll f;
		while ((f = dfs(s, t, inf)) > 0) {
			flow += f;
		}
	}
}

char field[101][101];
int main() {
	ll H, W; cin >> H >> W;
	rep(i, H) rep(j, W) {
		cin >> field[i][j];
		if (field[i][j] == 'X' && (i == 0 || i == H - 1 || j == 0 || j == W - 1)) {//淵に牛がいたら-1を出力
			cout << -1 << endl;
			return 0;
		}
	}

	ll S = 2 * H * W;//sorce 
	ll T = 2 * H * W + 1;//sink
	rep(i, H) rep(j, W) {
		if (field[i][j] == 'X') add_edge(S, i * W + j, inf);//sorceと牛がいるところに重みinfの辺を張る
		if (i == 0 || i == H - 1 || j == 0 || j == W - 1) add_edge(H * W + i * W + j, T, inf);//淵とsinkに重みinfの辺を張る
		add_edge(i * W + j, H * W + i * W + j, field[i][j] == 'X' ? inf : 1);//牛がいるgridの内部に重みinfの辺を張り、そうでないgridに重み1の辺を張る
		rep(k, 4) {//(i,j).outから隣接4grid.inに辺を張る
			if (i + dy[k] < 0 || H - 1 < i + dy[k] || j + dx[k] < 0 || W - 1 < j + dx[k]) continue;
			add_edge(H * W + i * W + j, (i + dy[k]) * W + (j + dx[k]), inf);
		}
	}
	cout << max_flow(S, T) << endl;

	return 0;
}
