#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B&lang=jp
const int INF = numeric_limits<int>::max();
struct edge {
	int from, to, cost;
};
vector<int> dijkstra(int s, vector<vector<edge>>&graph, vector<int>&d) {//頂点sからほかのすべての頂点の最短距離を入れたvectorを返す
	//以下pair<int,int>はfirstは最短距離 secondは頂点番号
	int n = graph.size();
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
	fill(d.begin(), d.begin() + n, INF);
	d[s] = 0;//スタート地点からスタート地点の距離はゼロ
	que.push(pair<int, int>(0, s));
	while (!que.empty()) {
		pair<int, int>p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) {
			continue;
		}
		for (int i = 0; i < graph[v].size(); i++) {
			edge e = graph[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(pair<int, int>(d[e.to], e.to));
			}
	    }
	}
	return d;
}

int main() {
	int n;//頂点数
	cin >> n;
	vector<vector<edge>>graph;
	graph.resize(n);
	vector<int>d(n, INF);//頂点sからの最短距離
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int to, cost;
			cin >> to >> cost;
			edge e;
			e.from = u;
			e.to = to;
			e.cost = cost;
			graph[u].push_back(e);
		}
	}
	vector<int> d_ans=dijkstra(0, graph, d);
	for (int i = 0; i < n; i++) {
		cout << i << " " << d_ans[i] << endl;
	}

}
