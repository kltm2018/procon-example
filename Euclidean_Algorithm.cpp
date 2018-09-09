#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//const int INF = numeric_limits<int>::max();
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
int main() {
	int n, x;
	cin >> n >> x;
	vector<ll>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	v.push_back(x);
	sort(v.begin(), v.end());
	vector<int>nv(n, 0);
	for (int i = 0; i < n; i++) {
		nv[i] = abs(v[i] - v[i + 1]);
	}
	ll m = nv[0];
	for (int i = 0; i < nv.size() - 1; i++) {
		m = GCD(m, nv[i + 1]);
	}
	cout << m << endl;
}
