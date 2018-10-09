#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<functional>
#include<string>
using namespace std;
using ll = long long;

using weight = ll;

constexpr weight INF = 1e18;

struct edge {
	int from, to;
	weight cost;

	bool operator<(edge const& rhs) const {
		return cost > rhs.cost;
	}
};

using edges = std::vector<edge>;
using graph = std::vector<edges>;


void add_edge(graph& g, int from, int to, weight cost) {
	g[from].push_back(edge{ from, to, cost });
}

std::vector<weight> dijkstra(graph& g, int s) {
	using P = std::pair<weight, int>;
	std::vector<weight> d(g.size(), INF);
	std::priority_queue<P, std::vector<P>, std::greater<P>> que;
	fill(d.begin(), d.end(), INF);
	d[s] = 0;
	que.push(P{ 0, s });

	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) {
			continue;
		}
		for (int i = 0; i<g[v].size(); ++i) {
			edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P{ d[e.to], e.to });
			}
		}
	}
	return d;
}


int main() {
	int H, W, T;
	cin >> H >> W >> T;
	vector<string> s(H);
	for (int i = 0; i<H; ++i) {
		cin >> s[i];
	}
	int S = 0, G = 0;
	for (int i = 0; i<H; ++i) {
		for (int j = 0; j<W; ++j) {
			if (s[i][j] == 'S') {
				S = i * W + j;
			}
			else if (s[i][j] == 'G') {
				G = i * W + j;
			}
		}
	}
	ll l = 0, r = 1e9 + 7;
	while (r - l > 1) {//二分探索　単調性
		ll mid = (l + r) / 2;
		graph g(H*W);//有効グラフの隣接リスト表現　すべての頂点それぞれから出ている辺を記録
		int dx[4] = { 0, 1, 0, -1 },
			dy[4] = { 1, 0, -1, 0 };
		for (int i = 0; i<H; ++i) {
			for (int j = 0; j<W; ++j) {
				for (int k = 0; k<4; ++k) {//各頂点から4方向に延びる辺をグラフに追加
					int nx = j + dx[k], ny = i + dy[k];
					if (0 <= ny && ny < H && 0 <= nx && nx < W) {
						if (s[ny][nx] == '#') {
							add_edge(g, W*i + j, W*ny + nx, mid);
						}
						else {
							add_edge(g, W*i + j, W*ny + nx, 1);
						}
					}
				}
			}
		}
		auto d = dijkstra(g, S);
		if (d[G] <= T) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l << endl;
}
