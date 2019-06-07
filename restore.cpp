#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __builtin_popcountll
#  define __builtin_popcountll __popcnt
#endif
//#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const long double PI = acos(-1.0);
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int MAX_V = 500;

inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << fixed << setprecision(10);
}
const int INF = 1e8;
struct edge {
	int from, to;long double  cost;
};
vector<double> dijkstra(int s, vector<vector<edge>>&graph,vector<int>&prev_) {//頂点sからほかのすべての頂点の最短距離を入れたvectorを返す
														 //以下pair<int,int>はfirstは最短距離 secondは頂点番号
	int n = graph.size();
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
	vector<double>d(n, INF);//頂点sからの最短距離
	d[s] = 0;//スタート地点からスタート地点の距離はゼロ
	que.push(pair<int, int>(0, s));
	while (!que.empty()) {
		pair<int, int>p = que.top();
		que.pop();
		int v = p.second;
		for (int i = 0; i < graph[v].size(); i++) {
			edge const &e = graph[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(pair<int, int>(d[e.to], e.to));
				prev_[e.to] = v;
			}
		}
	}
	return d;
}
vector<int> get_path(int t,vector<int>&prev_) {
	vector<int>path;
	for (; t !=-1; t = prev_[t]) {
		path.push_back(t);
	}
	reverse(path.begin(), path.end());
	return path;
}
ld distance(ld x0, ld y0, ld x1, ld y1) {
	return sqrt((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1));
}
signed main(){
	int n;
	while (cin >> n, n) {
		
		vector<tuple<int, int, int>>vs(n);
		map<int, int>mp;
		map<int, int>mp1;
		for (int i = 0; i < n; i++) {
			int p;
			
			cin >> p >> get<1>(vs[i]) >> get<2>(vs[i]);
			mp[i] = p;  
			mp1[p] = i;
			
		}

		vector < vector<edge>>graph(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					ld d = distance(get<1>(vs[i]), get<2>(vs[i]), get<1>(vs[j]), get<2>(vs[j]));
					if (50 >= d) {
						graph[i].push_back({ i,j,d });
						graph[j].push_back({ j,i,d });

					}
				}
			}
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int s, g;
			cin >> s >> g;
			vector<int>prev_(n, -1);
			vector<double>distes = dijkstra(mp1[s], graph,prev_);
			if (distes[mp1[g]] == INF) {
				cout << "NA" << endl;

			}
			else {
				assert(prev_[mp1[s]] == -1);
				auto ans = get_path(mp1[g],prev_);
				for (int i = 0; i < ans.size(); i++) {
					ans[i] = mp[ans[i]];
				}
				for (int i = 0; i < ans.size(); i++) {
					int integer = ans[i] ;
					cout << integer;
					if (i != ans.size() - 1) {
						cout << " ";
					}
					else {
						cout << endl;
					}

				}
			}
		}
	}
	return 0;

}	



