//ダイクストラ法
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B&lang=jp
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_V 100
#define INF 1e9
using namespace std;
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;
void dijkstra(int s) {
	for (int i = 0; i < V; i++) {
		d[i] = INF;
		used[i] = false;
	}
	d[s] = 0;
	while (true) {
		int v = -1;
		for (int u = 0; u < V; u++) {
			if (!used[u] && ((v == -1) || d[u] < d[v])) {
				v = u;
			}
		}
		//全ての頂点が到達済み
		if (v == -1) {
			break;
		}
		//集合に新たに頂点を追加
		used[v] = true;
		for (int u = 0; u < V; u++) {
			if (cost[v][u] != -1) {
				d[u] = min(d[u], d[v] + cost[v][u]);
			}
		}
	}
}

int main() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cost[i][j] = -1;
		}
	}

	for (int i = 0; i < V; i++) {
		int u;
		cin >> u;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int v;
			cin >> v;
			int c;
			cin >> c;
			cost[u][v] = c;
		}
	}
	dijkstra(0);

	for (int i = 0; i < V; i++) {
		cout << i << " " << d[i] << endl;
	}
	return 0;
}
