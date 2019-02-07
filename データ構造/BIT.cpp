#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __builtin_popcountll
#  define __builtin_popcountll __popcnt
#endif
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << fixed << setprecision(10);
}
class BIT{
private:
	int N;
	vector<int>node;
public:
	BIT(vector<int>v) {
		N = v.size();
		node.resize(N + 1,0);
		//for (int i = 1; i <= N; i++) add(i, v[i-1]);
		
	}
	void add(int a, int w) {
		for (int x = a; x <= N; x += x & -x) node[x] += w;
	}
	int sum(int a) {
		int ret = 0;
		for (int x = a; x > 0; x -= x & -x) ret += node[x];
		return ret;
	}

};
signed main() {
	my_io();
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>a_v(n);
	for (int i = 0; i < n; i++) {
		a_v[i] = a[i];
	}
	sort(a_v.begin(), a_v.end());
	map<int, int>b;
	for (int i = 0; i<n; i++) b[a_v[i]] = i + 1;//BIT‚Í1-indexed‚È‚Ì‚Å”z—ñb‚Ìindex‚ð1-indexed‚É‚µ‚Ä‚¨‚­
	vector<int>v(n, 0);
	BIT bit(v);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += i - bit.sum(b[a[i]]);
		bit.add(b[a[i]], 1);

	}
	cout << ans << endl;
	return 0;
}

