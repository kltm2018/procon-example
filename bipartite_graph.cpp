#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
ll n, m;
vector<vector<int>>graph(n);
vector<int>color(n);//各頂点の色
bool dfs(int v, int c) {
	color[v] = c;//頂点vをcで塗る
	for (int i = 0; i < graph[v].size(); i++) {
		if (color[graph[v][i]] == c) {
			return false;
		}
		if (color[graph[v][i]] == 0 && !dfs(graph[v][i], -c)) {
			return false;
		}
	}
	return true;
}
int main(){
}
